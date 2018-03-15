#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace mm {


static const QString NEW_GAME_MSG =
        "New game started.";


MainWindow::MainWindow(Model &model) :
    QMainWindow(),
    ui(new Ui::MainWindow),
    model(model)
{
    // set up UI elements
    ui->setupUi(this);

    // connect buttons to methods
    connect(
                ui->newGameBtn,
                SIGNAL (released()),
                this,
                SLOT (handleNewGameClicked())
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleNewGameClicked() {
    model.newGame();
    ui->feedback->setText(NEW_GAME_MSG);
}


} // namespace mm
