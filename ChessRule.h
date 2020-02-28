#ifndef CHESSRULE_H
#define CHESSRULE_H

#include "ChessPiece.h"

#include <QVector>



class ChessRule
{
public:
    ChessRule()=default;

    virtual int checkMove(ChessPiece* chessPiece, ChessPiece* chessPieces[][9], int tor, int toc)=0;
};

#endif // CHESSRULE_H
