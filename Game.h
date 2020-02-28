#ifndef GAME_H
#define GAME_H

#include "ChessPiece.h"
#include "ChessRule.h"
#include <QMap>
#include <QObject>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);

    Q_INVOKABLE void    initNewGame();
    Q_INVOKABLE QString src(        int index);
    Q_INVOKABLE int     role(       int index);
    Q_INVOKABLE bool    alive(      int index);
    Q_INVOKABLE int     side(       int index);
    Q_INVOKABLE int     roll(       int index);
    Q_INVOKABLE int     column(     int index);
    Q_INVOKABLE bool    checkMove(  int fromx, int tox, int fromy, int toy); //return 0 for not movable, 1 for movable, 2 for eatable

signals:

private:
    QVector<ChessPiece*>    m_chessPieces;
    ChessPiece*             m_board[10][9];
    QMap<int, ChessRule*>   m_rules;

};

#endif // GAME_H
