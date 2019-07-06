#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Presenter/SocketUdpPresenter.h>
#include "Contracts/SocketUdpContractView.h"

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
    void on_comboBox_currentIndexChanged(int index);

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
    void setDoubleValidator(QDoubleValidator *validator);
    void disableAcceptButton();
    void enableAcceptButton();
    void addItemToComboBox(QString value);
    void disableComboBox();
    void enableComboBox();
};

#endif // MAINWINDOW_H
