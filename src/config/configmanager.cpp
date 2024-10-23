#include "configmanager.h"

#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QDir>
#include <QFile>

#include <vector>

ConfigManager::~ConfigManager() {
    saveTimeoutToFile();
}

void ConfigManager::init(const QString&& jsonPath) {
    m_jsonPath = jsonPath;
    openJsonFile();
}

std::vector<DnsConfig> ConfigManager::dnsConfigs() {
    return m_dnsConfigs;
}

uint64_t ConfigManager::timeout() {
    return m_timeout;
}

void ConfigManager::setTimeout(uint64_t timeout) {
    m_timeout = timeout;
}

void ConfigManager::openJsonFile() {
    QFile jsonFile(m_jsonPath);
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

    if (jsonObject.contains("dns-list") && jsonObject["dns-list"].isArray()) {
        QJsonArray dnsArray = jsonObject["dns-list"].toArray();
        m_dnsConfigs.clear();
        m_dnsConfigs.reserve(dnsArray.size());

        for (const QJsonValue& value : dnsArray) {
            QJsonObject dnsObject = value.toObject();
            DnsConfig   dns;
            dns.name      = dnsObject["name"].toString();
            dns.primary   = dnsObject["primary"].toString();
            dns.secondary = dnsObject["secondary"].toString();

            m_dnsConfigs.emplace_back(dns);
        }
    }
}

void ConfigManager::saveTimeoutToFile() {
    if (!m_jsonDoc.isObject()) {
        // TODO: error message
        return;
    }

    QJsonObject jsonObject = m_jsonDoc.object();
    jsonObject["timeout"]  = static_cast<double>(m_timeout);
    m_jsonDoc.setObject(jsonObject);

    QFile file(m_jsonPath);
    if (!file.open(QIODevice::WriteOnly)) {
        // TODO: error message
        return;
    }
    file.write(m_jsonDoc.toJson());
    file.close();
}
