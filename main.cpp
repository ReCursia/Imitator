#include <QApplication>
#include "View/mainwindow.h"
#include "Model/socketudpmodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
