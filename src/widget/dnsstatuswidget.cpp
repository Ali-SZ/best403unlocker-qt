#include "ui_dnsstatuswidget.h"
#include "dnsstatuswidget.h"

DnsStatusWidget::DnsStatusWidget(DnsConfig dns, QWidget* parent) : m_dns(dns), QWidget(parent), ui(new Ui::DnsStatusWidget) {
    ui->setupUi(this);

    loadDns();
}

DnsStatusWidget::~DnsStatusWidget() {
    delete ui;
}

void DnsStatusWidget::loadDns() {
    ui->groupBox->setTitle(m_dns.name);
    ui->primaryLabel->setText(m_dns.primary);
    if (m_dns.secondary.isEmpty()) {
        ui->secondaryLabel->setVisible(false);
    } else {
        ui->secondaryLabel->setText(m_dns.secondary);
    }
}
