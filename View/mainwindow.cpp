#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Presenter/mainwindowcontract.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    presenter = new MainWindowPresenter(this);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_acceptButton_clicked()
{
    presenter->onAcceptButtonPressed();
}

void MainWindow::on_startButton_clicked()
{
    presenter->onStartButtonPressed();
}
//Interface implementation

void MainWindow::setStatusMessage(QString message)
{
    ui->statusBar->showMessage(message);
}

void MainWindow::setProgressStatus(int value)
{
    ui->progressBar->setValue(value);
}

void MainWindow::setStartButtonLabel(QString label){
    ui->startButton->setText(label);
}
