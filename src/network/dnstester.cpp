#include "dnstester.h"

#include <QtConcurrent>
#include <QNetworkAccessManager>
#include <QHostInfo>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QElapsedTimer>
#include <QNetworkReply>

void DnsTester::start(const std::vector<DnsConfig>&& dnsConfigs, const uint64_t&& timeout, const QString&& url) {
    qDebug() << "testing";
    QtConcurrent::run([=] {
        for (const DnsConfig& dns : dnsConfigs) {
            qDebug() << "testing" << dns.primary;
            emit dnsTestStarted(dns);
            testSpeed(dns, timeout, url);
        }
        emit allTestsFinished();
    });
}

void DnsTester::testSpeed(const DnsConfig& dns, const uint64_t& timeout, const QString& url) {
    QUrl      targetUrl(url);

    QHostInfo hostInfo = QHostInfo::fromName(dns.primary);
    if (hostInfo.error() != QHostInfo::NoError || hostInfo.addresses().empty()) {

        hostInfo = QHostInfo::fromName(dns.secondary);
        if (hostInfo.error() != QHostInfo::NoError || hostInfo.addresses().empty()) {
            emit dnsTestFinished(DnsTestResult{DnsTestStatus::FAILED, 0, 0});
            return;
        }
    }

    targetUrl.setHost(hostInfo.addresses().first().toString());
    QNetworkRequest request(targetUrl);
    request.setRawHeader("Host", url.toUtf8());

    QEventLoop    loop;
    QTimer        timeoutTimer;
    QElapsedTimer elapsedTimer;

    timeoutTimer.setInterval(timeout * 1000);
    timeoutTimer.setSingleShot(true);

    QNetworkAccessManager manager;
    QNetworkReply*        reply = manager.get(request);
    elapsedTimer.start();

    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    connect(&timeoutTimer, &QTimer::timeout, &loop, &QEventLoop::quit);

    timeoutTimer.start();
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        qint64 downloadedBytes = reply->bytesAvailable();
        double timeSeconds     = elapsedTimer.elapsed() / 1000.0;
        double speed           = downloadedBytes / timeSeconds;
        qDebug() << timeSeconds << downloadedBytes;

        reply->deleteLater();
        emit dnsTestFinished(DnsTestResult{DnsTestStatus::SUCCESSFULL, 0, speed});
        return;
    } else {
        qDebug() << reply->error();
        reply->abort();
        reply->deleteLater();
        emit dnsTestFinished(DnsTestResult{DnsTestStatus::FAILED, 0, 0});
        return;
    }
}
