#-------------------------------------------------
#
# Project created by QtCreator 2019-06-07T23:59:02
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Imitator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Contracts/SendContractView.cpp \
        Led/Led.cpp \
        Models/SendStrategies/NamedPipeSendStrategy.cpp \
        Models/SendStrategies/SharedMemorySendStrategy.cpp \
        Models/SendStrategies/SocketUdpSendStrategy.cpp \
        Models/DataModel.cpp \
        Models/SendModel.cpp \
        Presenter/SendPresenter.cpp \
        Utilities/EventListener.cpp \
        Utilities/EventManager.cpp \
        Utilities/SendStrategy.cpp \
        main.cpp \
        View\mainWindow.cpp

HEADERS += \
    Contracts/SendContractView.h \
        Exceptions/EmptyData.h \
        Exceptions/NoDataToSend.h \
        Led/Led.h \
    Models/SendStrategies/SharedMemorySendStrategy.h \
    Presenter/SendPresenter.h \
    Utilities/EventListener.h \
    Utilities/EventManager.h \
        Utilities/SendStrategy.h \
        Models/SendStrategies/NamedPipeSendStrategy.h \
        Models/SendStrategies/SocketUdpSendStrategy.h \
        Models/DataModel.h \
        Models/SendModel.h \
        View\mainWindow.h \

FORMS += \
        View\MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
