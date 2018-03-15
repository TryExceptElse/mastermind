#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QException>


namespace mm {


class GameException: QException {
public:
    GameException(const QString &msg): QException(), msg(msg) {}
private:
    const QString msg;
};


} // namespace mm

#endif // EXCEPTION_H
