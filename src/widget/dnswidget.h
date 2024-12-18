#ifndef DNSWIDGET_H
#define DNSWIDGET_H

#include <QWidget>

#include "../config/configmanager.h"

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

    void           setUiConnects();
    void           addDnsStatusWidget(const DnsConfig& dns);
    void           setPageLocked(const bool&& lock);

  private slots:
    void startButtonClicked();
    void linkLineEditEdited(const QString& text);
};

#endif // DNSWIDGET.H
