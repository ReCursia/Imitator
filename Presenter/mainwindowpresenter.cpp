#include "mainwindowpresenter.h"

MainWindowPresenter::MainWindowPresenter(MainWindowContract *ui)
{
    this->ui = ui;
    buttonStatus = false;
}

void MainWindowPresenter::onAcceptButtonPressed(){
    ui->setStatusMessage("TESTING");
}

void MainWindowPresenter::onStartButtonPressed()
{
    buttonStatus == false ? ui->setStartButtonLabel("ПУСК") : ui->setStartButtonLabel("СТОП");
    buttonStatus = !buttonStatus;
}
