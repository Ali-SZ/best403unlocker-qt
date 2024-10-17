#include "ui_dnswidget.h"
#include "dnswidget.h"

DnsWidget::DnsWidget(QWidget* parent) : QWidget(parent), ui(new Ui::DnsWidget) {
    ui->setupUi(this);

    for (int i = 0; i < 10; i++)
        addDnsStatusWidget();
}

DnsWidget::~DnsWidget() {
    delete ui;
}

void DnsWidget::addDnsStatusWidget() {
    DnsStatusWidget* dsw = new DnsStatusWidget();
    ui->dnsListVerticalLayout->insertWidget(0, dsw);
}
