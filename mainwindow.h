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
    void handleNewGameClicked();

private:
    Ui::MainWindow *ui;
    Model &model;
};


} // namespace mm

#endif // MAINWINDOW_H
