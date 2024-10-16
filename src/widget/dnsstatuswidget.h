#ifndef DNSSTATUSWIDGET_H
#define DNSSTATUSWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
  class DnsStatusWidget;
}
QT_END_NAMESPACE

class DnsStatusWidget : public QWidget {
  Q_OBJECT

public:
  DnsStatusWidget(QWidget* parent = nullptr);
  ~DnsStatusWidget();

private:
  Ui::DnsStatusWidget* ui;
};

#endif // DNSSTATUSWIDGET.H