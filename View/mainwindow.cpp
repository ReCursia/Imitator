#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    presenter = new SocketUdpPresenter(this);
    ui->setupUi(this);
    //TODO
    ui->listWidget->addItem("5");
    ui->listWidget->addItem("4.0");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete presenter;
}

void MainWindow::on_acceptButton_clicked()
{
    presenter->onAcceptButtonPressed();
}

void MainWindow::on_startButton_clicked()
{
    presenter->onStartButtonPressed();
}

void MainWindow::setStartButtonLabel(QString str)
{
    ui->startButton->setText(str);
}

void MainWindow::setCounterValue(int value)
{
    ui->transmissionCounter->setText(QString::number(value));
}

void MainWindow::setStatusBarMessage(QString message)
{
    ui->statusBar->showMessage(message,STATUS_BAR_MESSAGE_TIMEOUT);
}

QList<double> MainWindow::getDataFromWidgetList()
{
    QList<double> values;
    for(int i = 0; i < ui->listWidget->count();i++){
        values.append(ui->listWidget->item(i)->text().toDouble());
    }
    return values;
}
