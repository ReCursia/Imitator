#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    presenter = new SocketUdpPresenter(this);
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
    ui->statusBar->showMessage(message,STATUS_BAR_DEFAULT_TIMEOUT);
}

void MainWindow::lightOnLed()
{
    ui->led->turnOn();
}

void MainWindow::lightOffLed()
{
    ui->led->turnOff();
}

void MainWindow::setListModel(QStringListModel *model)
{
    ui->listView->setModel(model);
}

QString MainWindow::getEditLineText()
{
    return ui->lineEdit->text();
}

bool MainWindow::hasSelectedRow()
{
    return !(ui->listView->selectionModel()->selectedRows().isEmpty());
}

int MainWindow::getSelectedRowIndex()
{
    return ui->listView->selectionModel()->selectedRows().first().row();
}

void MainWindow::on_addButton_clicked()
{
    presenter->onAddButtonPressed();
}

void MainWindow::on_deleteButton_clicked()
{
    presenter->onDeleteButtonPressed();
}
