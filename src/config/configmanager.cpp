#include "configmanager.h"

#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QDir>
#include <QFile>

#include <vector>

void ConfigManager::init() {
    openJsonFile(QString("%1/best403unlocker/config.json").arg(QDir::homePath()));
}

std::vector<DnsConfig> ConfigManager::dnsConfigs() {
    return m_dnsConfigs;
}

uint64_t ConfigManager::timeout() {
    return m_timeout;
}

void ConfigManager::setTimeout(uint64_t timeout) {
    m_timeout = timeout;
    // TODO: save changes to file
}

void ConfigManager::openJsonFile(const QString jsonPath) {
    QFile jsonFile(jsonPath);
    if (!jsonFile.open(QIODevice::ReadOnly)) {
        // TODO: error message
        return;
    }
    const QByteArray jsonData = jsonFile.readAll();
    jsonFile.close();

    QJsonParseError jsonError;
    m_jsonDoc = QJsonDocument::fromJson(jsonData, &jsonError);
    if (jsonError.error != QJsonParseError::NoError) {
        // TODO: error message
    }
}

void ConfigManager::parseJson() {
    if (!m_jsonDoc.isObject()) {
        // TODO: error message
        return;
    }

    QJsonObject jsonObject = m_jsonDoc.object();

    if (jsonObject.contains("timeout") && jsonObject["timeout"].isDouble()) {
        m_timeout = jsonObject["timeout"].toInt(10000);
    }

    if (jsonObject.contains("dns") && jsonObject["dns"].isArray()) {
        QJsonArray dnsArray = jsonObject["dns"].toArray();
        m_dnsConfigs.clear();
        m_dnsConfigs.reserve(dnsArray.size());

        for (const QJsonValue& value : dnsArray) {
            QJsonObject dnsObject = value.toObject();
            DnsConfig   dns;
            dns.name = dnsObject["name"].toString();
            dns.ip   = dnsObject["ip"].toString();

            m_dnsConfigs.emplace_back(dns);
        }
    }
}
