#include <QApplication>
#include "View/mainwindow.h"
#include "Model/socketudpmodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    SocketUdpModel test;
    QList<double> data;
    data.append(15);
    data.append(20);
    test.setData(data);
    test.startTransmission();
    return app.exec();
}
