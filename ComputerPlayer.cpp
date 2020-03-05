#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(QObject *parent) : QObject(parent)
{

}

int ComputerPlayer::moveFrom(QObject* game)
{
    Game* myGame = qobject_cast<Game*>(game);
    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            if(myGame->chessBoard(i, j) != nullptr && myGame->chessBoard(i, j)->side() == Piece::BLACK)
            {
                m_computerRoll = i;
                m_computerColumn = j;
                return i * 9 + j;
            }
        }
    }
}

int ComputerPlayer::moveTo(QObject* game)
{
    Game* myGame = qobject_cast<Game*>(game);
    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            if((m_computerRoll != i || m_computerColumn != j) && myGame->checkMove(Piece::BLACK, m_computerRoll, m_computerColumn, i, j))
            {
                return i * 9 + j;
            }
        }
    }
}
