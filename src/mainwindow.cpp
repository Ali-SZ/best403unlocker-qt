#include "ui_mainwindow.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  addDnsWidget();
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::addDnsWidget() {
  DnsWidget* dw = new DnsWidget();

  QVBoxLayout* layout = new QVBoxLayout();
  layout->addWidget(dw);
  ui->dnsPage->setLayout(layout);
}