#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <Presenter/socketudppresenter.h>

#include "Contract/socketudpcontract.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public SocketUdpContract
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
public:
    void setStartButtonLabel(QString str);
    void setProgressBarLabel(QString str);
    void setProgressBarValue(int value);
    void setCounterValue(int value);
    void setStatusBarMessage(QString message);
};

#endif // MAINWINDOW_H
