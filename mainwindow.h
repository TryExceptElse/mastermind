#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model.h"


namespace Ui {

class MainWindow;

} // namespace Ui


namespace mm {


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Model &model);
    ~MainWindow();

private slots:
    void newGame();
    void guess();

    /**
     * Displays dialog informing the user that no game is currently in
     * progress, and asking them if they would like to begin one.
     */
    void showNoGameInProgressDlg();

    /**
     * Displays dialog informing the user that they have won the game.
     */
    void showSuccessDlg();

    /**
     * Displays dialog asking user if they are sure they want to begin
     * a new game, when one is already underway. Returns boolean of
     * their response.
     */
    bool showGameAlreadyInProgressDlg();

private:
    Ui::MainWindow *ui;
    Model &model;
};


} // namespace mm

#endif // MAINWINDOW_H
