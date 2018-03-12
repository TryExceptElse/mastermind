#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Model model;
    QApplication app(argc, argv);
    MainWindow mainWindow(model);
    mainWindow.show();

    return app.exec();
}
