#ifndef GAME_H
#define GAME_H
#include "Piece.h"
#include <QObject>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit                    Game(QObject *parent = nullptr);
    Q_INVOKABLE void            init();
    Q_INVOKABLE int             checkGameState();
    Q_INVOKABLE bool            checkMove(      int side,     int fromRoll,   int fromColumn, int toRoll, int toColumn);
    Q_INVOKABLE bool            checkWin(       int side);
    bool                        cheCheckMove(   int fromRoll, int fromColumn, int toRoll, int toColumn);
    bool                        maCheckMove(    int fromRoll, int fromColumn, int toRoll, int toColumn);
    bool                        xiangCheckMove( int fromRoll, int fromColumn, int toRoll, int toColumn);
    bool                        shiCheckMove(   int fromRoll, int fromColumn, int toRoll, int toColumn);
    bool                        jiangCheckMove( int fromRoll, int fromColumn, int toRoll, int toColumn);
    bool                        paoCheckMove(   int fromRoll, int fromColumn, int toRoll, int toColumn);
    bool                        bingCheckMove(  int fromRoll, int fromColumn, int toRoll, int toColumn);
    void                        movePiece(      int fromRoll, int fromColumn, int toRoll, int toColumn);

signals:
private:
    QVector<Piece*> m_pieceCollection;
    Piece*          m_chessBoard[10][9];
};

#endif // GAME_H
