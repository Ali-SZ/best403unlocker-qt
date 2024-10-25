#ifndef DNSSTATUSWIDGET_H
#define DNSSTATUSWIDGET_H

#include <QWidget>

#include "../config/configmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class DnsStatusWidget;
}
QT_END_NAMESPACE

class DnsStatusWidget : public QWidget {
    Q_OBJECT

  public:
    DnsStatusWidget(DnsConfig dns, QWidget* parent = nullptr);
    ~DnsStatusWidget();

  private:
    Ui::DnsStatusWidget* ui;

    DnsConfig            m_dns;

    void                 loadDns();
};

#endif // DNSSTATUSWIDGET.H
