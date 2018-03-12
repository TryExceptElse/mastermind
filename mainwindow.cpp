#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace mm {


MainWindow::MainWindow(Model &model) :
    QMainWindow(),
    ui(new Ui::MainWindow),
    model(model)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


} // namespace mm
