#ifndef MAINWINDOWCONTRACT_H
#define MAINWINDOWCONTRACT_H

#include "QString"

class MainWindowContract {
public:
    virtual ~MainWindowContract() = 0;
    virtual void setStatusMessage(QString message) = 0;
    virtual void setProgressStatus(int value) = 0;
    virtual void setStartButtonLabel(QString label) = 0;
};

#endif // MAINWINDOWCONTRACT_H
