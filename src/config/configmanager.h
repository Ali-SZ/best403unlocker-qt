#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <QString>
#include <QJsonDocument>

#include <vector>

struct DnsConfig {
    QString name;
    QString primary;
    QString secondary;
};

class ConfigManager {
  public:
    ~ConfigManager();
    void                   init(const QString&& jsonPath);

    std::vector<DnsConfig> dnsConfigs();
    uint64_t               timeout();
    void                   setTimeout(uint64_t timeout);

  private:
    uint64_t               m_timeout;
    std::vector<DnsConfig> m_dnsConfigs;
    QJsonDocument          m_jsonDoc;
    QString                m_jsonPath;

    void                   openJsonFile();
    void                   parseJson();
    void                   saveTimeoutToFile();
};

#endif //CONFIGMANAGER_H
