#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include <vector>

#include "../config/configmanager.h"

enum class DnsTestStatus {
    SUCCESSFULL,
    FAILED,
};

struct DnsTestResult {
    DnsTestStatus status;
    uint64_t      id;
    double        speed;
};
Q_DECLARE_METATYPE(DnsTestResult);

class DnsTester : public QObject {
    Q_OBJECT

  public:
    void start(const std::vector<DnsConfig>&& dnsConfigs, const uint64_t&& timeout, const QString&& url);

  private:
    void testSpeed(const DnsConfig& dns, const uint64_t& timeout, const QString& url);

  signals:
    void dnsTestStarted(const DnsConfig& dns);
    void dnsTestFinished(const DnsTestResult result);
    void allTestsFinished();
};
