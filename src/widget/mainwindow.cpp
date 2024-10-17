#include "ui_mainwindow.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    addDnsWidget();
    applyTheme();
    ui->mainTabWidget->tabBar()->setDocumentMode(true);
    ui->mainTabWidget->tabBar()->setExpanding(true);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::addDnsWidget() {
    QVBoxLayout* layout = new QVBoxLayout(ui->dnsPage);
    DnsWidget*   dw     = new DnsWidget(ui->dnsPage);
    layout->addWidget(dw);
    ui->dnsPage->setLayout(layout);
}

void MainWindow::addDnsLogWidget() {}

void MainWindow::addDockerWidget() {}

void MainWindow::addDockerLogWidget() {}

void MainWindow::applyTheme() {
    QFile file(":/style/main.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet{file.readAll()};
    this->setStyleSheet(styleSheet);
}
