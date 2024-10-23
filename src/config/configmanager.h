#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <QString>
#include <QJsonDocument>

#include <vector>

struct DnsConfig {
    QString name;
    QString ip;
};

class ConfigManager {
  public:
    void                   init();

    std::vector<DnsConfig> dnsConfigs();
    uint64_t               timeout();
    void                   setTimeout(uint64_t timeout);

  private:
    uint64_t               m_timeout;
    std::vector<DnsConfig> m_dnsConfigs;
    QJsonDocument          m_jsonDoc;

    void                   openJsonFile(const QString jsonPath);
    void                   parseJson();
};

#endif //CONFIGMANAGER_H
