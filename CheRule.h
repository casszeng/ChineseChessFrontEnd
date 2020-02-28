#ifndef CHERULE_H
#define CHERULE_H

#include "ChessRule.h"



class CheRule : public ChessRule
{
public:
    CheRule();

    // ChessRule interface
public:
    int checkMove(ChessPiece *chessPiece, ChessPiece *chessPieces[][9], int tor, int toc);
};

#endif // CHERULE_H
