#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Model &model) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->model = model;
}

MainWindow::~MainWindow()
{
    delete ui;
}
