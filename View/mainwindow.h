#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <Presenter/mainwindowcontract.h>
#include <Presenter/mainwindowpresenter.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public MainWindowContract
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
    MainWindowPresenter* presenter;
    void setStatusMessage(QString message);
    void setProgressStatus(int value);
    void setStartButtonLabel(QString label);
};

#endif // MAINWINDOW_H
