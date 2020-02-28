#include "CheRule.h"

CheRule::CheRule()
{

}


int CheRule::checkMove(ChessPiece *chessPiece, ChessPiece *chessPieces[][9], int tor, int toc)
{

    int result = 0;
    if(chessPieces[tor][toc] != nullptr)
    {
        result = 2;
        if(chessPieces[tor][toc]->side() == chessPiece->side())
        {
            return 0;
        }
    }
    else
    {
        result = 1;
    }

    if(chessPiece->roll() == tor || chessPiece->column() == toc)
    {
        if(toc > chessPiece->column())
        {
            for(int i = chessPiece->column() + 1; i < toc; ++i)
            {
                if(chessPieces[tor][i] != nullptr)
                {
                    return 0;
                }

            }
            return result;
        }
        else if(toc < chessPiece->column())
        {
            for(int i = chessPiece->column() - 1; i > toc; --i)
            {
                if(chessPieces[tor][i] != nullptr)
                {
                    return 0;
                }

            }
            return result;
        }
        else if(tor > chessPiece->roll())
        {
            for(int i = chessPiece->roll() + 1; i < tor; ++i)
            {
                if(chessPieces[i][toc] != nullptr)
                {
                    return 0;
                }

            }
            return result;

        }
        else if(tor < chessPiece->roll())
        {
            for(int i = chessPiece->roll() - 1; i > tor; --i)
            {
                if(chessPieces[i][toc] != nullptr)
                {
                    return 0;
                }

            }
            return result;
        }
    }

    return 0;
}
