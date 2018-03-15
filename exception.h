#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QException>

class GameException: QException {
public:
    GameException(const QString &msg): QException(), msg(msg) {}
private:
    const QString msg;
};

#endif // EXCEPTION_H
