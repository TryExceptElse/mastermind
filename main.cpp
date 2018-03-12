#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    mm::Model model;
    QApplication app(argc, argv);
    mm::MainWindow mainWindow(model);
    mainWindow.show();

    return app.exec();
}
