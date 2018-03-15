#include "mainwindow.h"

#include <QString>
#include "ui_mainwindow.h"

namespace mm {


static const QString NEW_GAME_MSG = "New game started.";


MainWindow::MainWindow(Model &model) :
    QMainWindow(),
    ui(new Ui::MainWindow),
    model(model)
{
    // set up UI elements
    ui->setupUi(this);

    // connect buttons to methods
    connect(
                ui->newGameBtn, // widget
                SIGNAL (released()), // event signal
                this, // handler
                SLOT (handleNewGameClicked()) // method
    );
    connect(
                ui->guessBtn, // widget
                SIGNAL (released()), // event signal
                this, // handler
                SLOT (handleGuessClicked()) // method
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

void MainWindow::handleGuessClicked() {
    const QString guess = ui->lineEdit->text();
    QString feedback;
    // get results of guess, with feedback stored in feedback string.
    model.guess(feedback, guess);
    ui->feedback->setText(feedback);
}


} // namespace mm
