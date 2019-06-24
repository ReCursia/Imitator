#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Presenter/SocketUdpPresenter.h>
#include "Contract/SocketUdpContractView.h"

namespace Ui {
class MainWindow;
}

const int STATUS_BAR_DEFAULT_TIMEOUT = 5000; //ms


class MainWindow : public QMainWindow, public SocketUdpContractView
{
    Q_OBJECT
private slots:
    void on_acceptButton_clicked();
    void on_startButton_clicked();
    void on_addButton_clicked();
    void on_deleteButton_clicked();
private:
    Ui::MainWindow *ui;
    SocketUdpPresenter* presenter;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setStartButtonLabel(QString str);
    void setCounterValue(int value);
    void setStatusBarMessage(QString message);
    void lightOnLed();
    void lightOffLed();
    void setListModel(QStringListModel *model);
    QString getEditLineText();
    bool hasSelectedRow();
    int getSelectedRowIndex();
};

#endif // MAINWINDOW_H
