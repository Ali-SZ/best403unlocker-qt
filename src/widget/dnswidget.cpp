#include "ui_dnswidget.h"
#include "dnswidget.h"

#include <QThread>
#include <QtConcurrent/QtConcurrent>

#include "../config/configmanager.h"
#include "dnsstatuswidget.h"

DnsWidget::DnsWidget(QWidget* parent) : QWidget(parent), ui(new Ui::DnsWidget) {
    ui->setupUi(this);
    setUiConnects();
}

DnsWidget::~DnsWidget() {
    delete ui;
}

void DnsWidget::setUiConnects() {
    connect(ui->linkLineEdit, &QLineEdit::textEdited, this, &DnsWidget::linkLineEditEdited);
    connect(ui->startButton, &QPushButton::clicked, this, &DnsWidget::startButtonClicked);
}

void DnsWidget::addDnsStatusWidget(const DnsConfig& dns) {
    DnsStatusWidget* dsw = new DnsStatusWidget(dns, this);
    ui->dnsListVerticalLayout->insertWidget(0, dsw);
}

void DnsWidget::setPageLocked(const bool&& lock) {
    ui->startButton->setEnabled(!lock);
    ui->linkLineEdit->setEnabled(!lock);
    ui->timeoutSpinBox->setEnabled(!lock);
}

void DnsWidget::startButtonClicked() {
    QtConcurrent::run([=] {
        setPageLocked(true);

        // TODO: start finding process
        // temp
        QThread::sleep(ui->timeoutSpinBox->value());

        setPageLocked(false);
    });
}

void DnsWidget::linkLineEditEdited(const QString& text) {
    ui->startButton->setEnabled(!text.isEmpty());
}
