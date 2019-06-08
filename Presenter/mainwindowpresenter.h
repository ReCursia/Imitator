#ifndef MAINWINDOWPRESENTER_H
#define MAINWINDOWPRESENTER_H

#include "mainwindowcontract.h"



class MainWindowPresenter
{
private:
    MainWindowContract* ui;
    bool buttonStatus;
public:
    MainWindowPresenter(MainWindowContract* ui);
    void onAcceptButtonPressed();
    void onStartButtonPressed();
};

#endif // MAINWINDOWPRESENTER_H
