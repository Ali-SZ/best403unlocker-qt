#ifndef DNSWIDGET_H
#define DNSWIDGET_H

#include <QWidget>

#include "dnsstatuswidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class DnsWidget;
}
QT_END_NAMESPACE

class DnsWidget : public QWidget {
    Q_OBJECT

  public:
    DnsWidget(QWidget* parent = nullptr);
    ~DnsWidget();

  private:
    Ui::DnsWidget* ui;

    void           addDnsStatusWidget();
};

#endif // DNSWIDGET.H
