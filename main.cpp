#include <QApplication>
#include "View/MainWindow.h"
#include "Models/SocketUdpModel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
