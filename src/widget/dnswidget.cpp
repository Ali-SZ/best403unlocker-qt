#include "ui_dnswidget.h"
#include "dnswidget.h"

DnsWidget::DnsWidget(QWidget* parent) : QWidget(parent), ui(new Ui::DnsWidget) {
  ui->setupUi(this);
}

DnsWidget::~DnsWidget() {
  delete ui;
}