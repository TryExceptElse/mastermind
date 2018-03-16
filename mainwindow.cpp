#include "mainwindow.h"

#include <QString>
#include <QMessageBox>
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
                SLOT (newGame()) // method
    );
    connect(
                ui->guessBtn, // widget
                SIGNAL (released()), // event signal
                this, // handler
                SLOT (guess()) // method
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newGame() {
    if (model.isInProgress() && !showGameAlreadyInProgressDlg()) {
        return;
    }
    model.newGame();
    ui->feedback->setText(NEW_GAME_MSG);
}

void MainWindow::guess() {
    if (!model.isInProgress()) {
        showNoGameInProgressDlg();
        return;
    }
    const QString guess = ui->lineEdit->text();
    QString feedback;
    // get results of guess, with feedback stored in feedback string.
    const bool success = model.guess(feedback, guess);
    ui->feedback->setText(feedback);
    if (success) {
        showSuccessDlg();
    }
}

void MainWindow::showNoGameInProgressDlg() {
    QMessageBox msgBox;
    msgBox.setText("No game is currently in progress.");
    msgBox.setInformativeText("Would you like to start a new game?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    msgBox.setStyleSheet(styleSheet()); // set dialog stylesheet to own
    int result = msgBox.exec();
    if (result == QMessageBox::Yes) {
        newGame();
    }
}

void MainWindow::showSuccessDlg() {
    QMessageBox msgBox;
    msgBox.setText("Success");
    const QString &word = model.getWord();
    const QString tries = QString::number(model.getNGuesses());
    msgBox.setInformativeText("You correctly guessed " + word +
                              "\nIt took you " + tries + " tries.");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setStyleSheet(styleSheet()); // set dialog stylesheet to own
    msgBox.exec();
}

bool MainWindow::showGameAlreadyInProgressDlg() {
    QMessageBox msgBox;
    msgBox.setText("A game is already in progress.");
    msgBox.setInformativeText("Are you sure you want to start a new game?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.setStyleSheet(styleSheet()); // set dialog stylesheet to own
    return msgBox.exec() == QMessageBox::Yes;
}


} // namespace mm
