#include "mainwindow.h"

#include <QApplication>
#include <QString>

static const QString WORD_FILE_PATH = ":/resources/4-letter-words.txt";

int main(int argc, char *argv[]) {
    Q_INIT_RESOURCE(resources);

    mm::Model model;
    model.loadWords(WORD_FILE_PATH);
    QApplication app(argc, argv);
    mm::MainWindow mainWindow(model);
    mainWindow.show();

    return app.exec();
}
