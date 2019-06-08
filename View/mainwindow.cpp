#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    presenter = new SocketUdpPresenter(this);
    ui->setupUi(this);
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

void MainWindow::setProgressBarLabel(QString str)
{
    ui->progressBar->setFormat(str);
}

void MainWindow::setProgressBarValue(int value)
{
    ui->progressBar->setValue(value);
}

void MainWindow::setCounterValue(int value)
{
    ui->transmissionCounter->setText(QString::number(value));
}

void MainWindow::setStatusBarMessage(QString message)
{
    ui->statusBar->showMessage(message);
}
