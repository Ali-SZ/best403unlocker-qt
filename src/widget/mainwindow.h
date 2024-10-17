#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTabBar>

#include "dnswidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

  private:
    Ui::MainWindow* ui;

    void            addDnsWidget();
    void            addDnsLogWidget();
    void            addDockerWidget();
    void            addDockerLogWidget();
    void            applyTheme();
};

#endif // MAINWINDOW.H
