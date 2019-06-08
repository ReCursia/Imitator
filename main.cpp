#include "mainWindow.h"
#include "mainWindowPresenter.h"
#include <QApplication>

static MainWindow* mainWindow = nullptr;
static MainWindowPresenter* presenter = nullptr;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    mainWindow = new MainWindow();
    mainWindow->show();

    return app.exec();
}
