#include "mainwindow.h"

#include <QApplication>
#include <QString>
#include <ctime>

static const QString WORD_FILE_PATH = ":/4-letter-words.txt";

int main(int argc, char *argv[]) {
    Q_INIT_RESOURCE(resources);

    // seed random number generator used to generate words
    std::srand(std::time(nullptr));

    mm::Model model;
    model.loadWords(WORD_FILE_PATH);
    QApplication app(argc, argv);
    mm::MainWindow mainWindow(model);
    mainWindow.show();

    return app.exec();
}
