#include "ui_dnsstatuswidget.h"
#include "dnsstatuswidget.h"

DnsStatusWidget::DnsStatusWidget(QWidget* parent) : QWidget(parent), ui(new Ui::DnsStatusWidget) {
    ui->setupUi(this);
}

DnsStatusWidget::~DnsStatusWidget() {
    delete ui;
}
