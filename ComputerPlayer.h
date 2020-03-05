#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H
#include "Piece.h"
#include "Game.h"
#include <QObject>

class ComputerPlayer : public QObject
{
    Q_OBJECT
public:
    ComputerPlayer(QObject *parent = nullptr);

    Q_INVOKABLE int moveFrom(QObject* game);
    Q_INVOKABLE int moveTo(QObject* game);

private:
    int m_computerRoll;
    int m_computerColumn;
};

#endif // COMPUTERPLAYER_H
