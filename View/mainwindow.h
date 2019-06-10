#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <Presenter/SocketUdpPresenter.h>

#include "Contract/SocketUdpContractView.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public SocketUdpContractView
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_acceptButton_clicked();
    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    SocketUdpPresenter* presenter;
    const int STATUS_BAR_MESSAGE_TIMEOUT = 10000; //ms
public:
    void setStartButtonLabel(QString str);
    void setCounterValue(int value);
    void setStatusBarMessage(QString message);
    QList<double> getDataFromWidgetList();

    // SocketUdpContractView interface
public:
    void lightOnLed();
    void lightOffLed();
};

#endif // MAINWINDOW_H
