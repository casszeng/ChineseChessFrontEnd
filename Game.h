#ifndef GAME_H
#define GAME_H

#include "ChessPiece.h"
#include <QObject>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);

    Q_INVOKABLE void initNewGame();
    Q_INVOKABLE QString src(int index);
    Q_INVOKABLE int role(int index);
    Q_INVOKABLE int side(int index);
    Q_INVOKABLE int roll(int index);
    Q_INVOKABLE int column(int index);

signals:

private:
    QVector<ChessPiece*> m_chessPieces;

};

#endif // GAME_H
