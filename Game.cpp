#include "Game.h"
#include <QDebug>

Game::Game(QObject *parent) : QObject(parent)
{
    init();
}

void Game::init()
{
    m_pieceCollection.push_back(new Piece(Piece::CHE,    Piece::RED,     9, 0));
    m_pieceCollection.push_back(new Piece(Piece::CHE,    Piece::RED,     9, 8));
    m_pieceCollection.push_back(new Piece(Piece::MA,     Piece::RED,     9, 1));
    m_pieceCollection.push_back(new Piece(Piece::MA,     Piece::RED,     9, 7));
    m_pieceCollection.push_back(new Piece(Piece::XIANG,  Piece::RED,     9, 2));
    m_pieceCollection.push_back(new Piece(Piece::XIANG,  Piece::RED,     9, 6));
    m_pieceCollection.push_back(new Piece(Piece::SHI,    Piece::RED,     9, 3));
    m_pieceCollection.push_back(new Piece(Piece::SHI,    Piece::RED,     9, 5));
    m_pieceCollection.push_back(new Piece(Piece::JIANG,  Piece::RED,     9, 4));
    m_pieceCollection.push_back(new Piece(Piece::PAO,    Piece::RED,     7, 1));
    m_pieceCollection.push_back(new Piece(Piece::PAO,    Piece::RED,     7, 7));
    m_pieceCollection.push_back(new Piece(Piece::ZU,     Piece::RED,     6, 0));
    m_pieceCollection.push_back(new Piece(Piece::ZU,     Piece::RED,     6, 2));
    m_pieceCollection.push_back(new Piece(Piece::ZU,     Piece::RED,     6, 4));
    m_pieceCollection.push_back(new Piece(Piece::ZU,     Piece::RED,     6, 6));
    m_pieceCollection.push_back(new Piece(Piece::ZU,     Piece::RED,     6, 8));

    m_pieceCollection.push_back(new Piece(Piece::CHE,    Piece::BLACK,      0, 0));
    m_pieceCollection.push_back(new Piece(Piece::CHE,    Piece::BLACK,      0, 8));
    m_pieceCollection.push_back(new Piece(Piece::MA,     Piece::BLACK,      0, 1));
    m_pieceCollection.push_back(new Piece(Piece::MA,     Piece::BLACK,      0, 7));
    m_pieceCollection.push_back(new Piece(Piece::XIANG,  Piece::BLACK,      0, 2));
    m_pieceCollection.push_back(new Piece(Piece::XIANG,  Piece::BLACK,      0, 6));
    m_pieceCollection.push_back(new Piece(Piece::SHI,    Piece::BLACK,      0, 3));
    m_pieceCollection.push_back(new Piece(Piece::SHI,    Piece::BLACK,      0, 5));
    m_pieceCollection.push_back(new Piece(Piece::JIANG,  Piece::BLACK,      0, 4));
    m_pieceCollection.push_back(new Piece(Piece::PAO,    Piece::BLACK,      2, 1));
    m_pieceCollection.push_back(new Piece(Piece::PAO,    Piece::BLACK,      2, 7));
    m_pieceCollection.push_back(new Piece(Piece::ZU,     Piece::BLACK,      3, 0));
    m_pieceCollection.push_back(new Piece(Piece::ZU,     Piece::BLACK,      3, 2));
    m_pieceCollection.push_back(new Piece(Piece::ZU,     Piece::BLACK,      3, 4));
    m_pieceCollection.push_back(new Piece(Piece::ZU,     Piece::BLACK,      3, 6));
    m_pieceCollection.push_back(new Piece(Piece::ZU,     Piece::BLACK,      3, 8));

    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            m_chessBoard[i][j] = nullptr;
        }
    }

    for(auto piece: m_pieceCollection)
    {
        m_chessBoard[piece->roll()][piece->column()] = piece;
    }
}

int Game::checkGameState()
{
    return 0;
}

bool Game::checkMove(int side, int fromRoll, int fromColumn, int toRoll, int toColumn)
{
    if(m_chessBoard[fromRoll][fromColumn] == nullptr)
    {
        return false;
    }
    if(m_chessBoard[fromRoll][fromColumn]->side() != side)
    {
        return false;
    }
    if(m_chessBoard[toRoll][toColumn] != nullptr)
    {
        if(m_chessBoard[fromRoll][fromColumn]->side() == m_chessBoard[toRoll][toColumn]->side())
        {
            return false;
        }
    }
    switch (m_chessBoard[fromRoll][fromColumn]->role())
    {
    case Piece::CHE:
        return cheCheckMove(    fromRoll, fromColumn, toRoll, toColumn);
    case Piece::MA:
        return maCheckMove(     fromRoll, fromColumn, toRoll, toColumn);
    case Piece::XIANG:
        return xiangCheckMove(  fromRoll, fromColumn, toRoll, toColumn);
    case Piece::SHI:
        return shiCheckMove(    fromRoll, fromColumn, toRoll, toColumn);
    case Piece::JIANG:
        return jiangCheckMove(  fromRoll, fromColumn, toRoll, toColumn);
    case Piece::PAO:
        return paoCheckMove(    fromRoll, fromColumn, toRoll, toColumn);
    case Piece::ZU:
        return bingCheckMove(   fromRoll, fromColumn, toRoll, toColumn);
    default:
        return false;
    }
}

bool Game::checkWin(int side)
{
    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            if(m_chessBoard[i][j] != nullptr && m_chessBoard[i][j]->role() == Piece::JIANG && m_chessBoard[i][j]->side() != side)
            {
                return false;
            }
        }
    }
    return true;
}

bool Game::cheCheckMove(int fromRoll, int fromColumn, int toRoll, int toColumn)
{
    if(fromRoll == toRoll || fromColumn == toColumn)
    {
        if(fromRoll > toRoll)
        {
            for(int i = fromRoll - 1; i > toRoll; --i)
            {
                if(m_chessBoard[i][fromColumn] != nullptr)
                {
                    return false;
                }
            }
        }
        if(fromRoll < toRoll)
        {
            for(int i = fromRoll + 1; i < toRoll; ++i)
            {
                if(m_chessBoard[i][fromColumn] != nullptr)
                {
                    return false;
                }
            }
        }
        if(fromColumn > toColumn)
        {
            for(int i = fromColumn - 1; i > toColumn; --i)
            {
                if(m_chessBoard[fromRoll][i] != nullptr)
                {
                    return false;
                }
            }
        }
        if(fromColumn < toColumn)
        {
            for(int i = fromColumn + 1; i < toColumn; ++i)
            {
                if(m_chessBoard[fromRoll][i] != nullptr)
                {
                    return false;
                }
            }
        }
        movePiece(fromRoll, fromColumn, toRoll, toColumn);
        return true;
    }
    return false;
}

bool Game::maCheckMove(int fromRoll, int fromColumn, int toRoll, int toColumn)
{
    if(toRoll + 2 == fromRoll && toColumn + 1 == fromColumn)
    {
        if(m_chessBoard[fromRoll - 1][fromColumn] == nullptr)
        {
            movePiece(fromRoll, fromColumn, toRoll, toColumn);
            return true;
        }
    }
    if(toRoll + 2 == fromRoll && toColumn - 1 == fromColumn)
    {
        if(m_chessBoard[fromRoll - 1][fromColumn] == nullptr)
        {
            movePiece(fromRoll, fromColumn, toRoll, toColumn);
            return true;
        }
    }

    if(toRoll - 2 == fromRoll && toColumn + 1 == fromColumn)
    {
        if(m_chessBoard[fromRoll + 1][fromColumn] == nullptr)
        {
            movePiece(fromRoll, fromColumn, toRoll, toColumn);
            return true;
        }
    }
    if(toRoll - 2 == fromRoll && toColumn - 1 == fromColumn)
    {
        if(m_chessBoard[fromRoll + 1][fromColumn] == nullptr)
        {
            movePiece(fromRoll, fromColumn, toRoll, toColumn);
            return true;
        }
    }

    if(toRoll + 1 == fromRoll && toColumn + 2 == fromColumn)
    {
        if(m_chessBoard[fromRoll][fromColumn - 1] == nullptr)
        {
            movePiece(fromRoll, fromColumn, toRoll, toColumn);
            return true;
        }
    }
    if(toRoll - 1 == fromRoll && toColumn + 2 == fromColumn)
    {
        if(m_chessBoard[fromRoll][fromColumn - 1] == nullptr)
        {
            movePiece(fromRoll, fromColumn, toRoll, toColumn);
            return true;
        }
    }

    if(toRoll + 1 == fromRoll && toColumn - 2 == fromColumn)
    {
        if(m_chessBoard[fromRoll][fromColumn + 1] == nullptr)
        {
            movePiece(fromRoll, fromColumn, toRoll, toColumn);
            return true;
        }
    }
    if(toRoll - 1 == fromRoll && toColumn - 2 == fromColumn)
    {
        if(m_chessBoard[fromRoll][fromColumn + 1] == nullptr)
        {
            movePiece(fromRoll, fromColumn, toRoll, toColumn);
            return true;
        }
    }

    return false;
}

bool Game::xiangCheckMove(int fromRoll, int fromColumn, int toRoll, int toColumn)
{
    if(fromRoll + 2 == toRoll && fromColumn + 2 == toColumn)
    {
        if(m_chessBoard[fromRoll + 1][fromColumn + 1] == nullptr)
        {
            movePiece(fromRoll, fromColumn, toRoll, toColumn);
            return true;
        }
    }

    if(fromRoll - 2 == toRoll && fromColumn + 2 == toColumn)
    {
        if(m_chessBoard[fromRoll - 1][fromColumn + 1] == nullptr)
        {
            movePiece(fromRoll, fromColumn, toRoll, toColumn);
            return true;
        }
    }

    if(fromRoll + 2 == toRoll && fromColumn - 2 == toColumn)
    {
        if(m_chessBoard[fromRoll + 1][fromColumn - 1] == nullptr)
        {
            movePiece(fromRoll, fromColumn, toRoll, toColumn);
            return true;
        }
    }

    if(fromRoll - 2 == toRoll && fromColumn - 2 == toColumn)
    {
        if(m_chessBoard[fromRoll - 1][fromColumn - 1] == nullptr)
        {
            movePiece(fromRoll, fromColumn, toRoll, toColumn);
            return true;
        }
    }

    return false;
}

bool Game::shiCheckMove(int fromRoll, int fromColumn, int toRoll, int toColumn)
{
    if((toColumn >= 3 && toColumn <= 5 && toRoll >= 0 && toRoll <= 2) ||
       (toColumn >= 3 && toColumn <= 5 && toRoll >= 7 && toRoll <= 9))
    {
        if(
              (fromRoll + 1 == toRoll && fromColumn + 1 == toColumn)
            ||(fromRoll - 1 == toRoll && fromColumn + 1 == toColumn)
            ||(fromRoll + 1 == toRoll && fromColumn - 1 == toColumn)
            ||(fromRoll - 1 == toRoll && fromColumn - 1 == toColumn))
        {
            movePiece(fromRoll, fromColumn, toRoll, toColumn);
            return true;
        }
    }
    return false;
}

bool Game::jiangCheckMove(int fromRoll, int fromColumn, int toRoll, int toColumn)
{
    if((toColumn >= 3 && toColumn <= 5 && toRoll >= 0 && toRoll <= 2) ||
       (toColumn >= 3 && toColumn <= 5 && toRoll >= 7 && toRoll <= 9))
    {
        if(
              (fromRoll == toRoll && fromColumn - 1 == toColumn)
            ||(fromRoll == toRoll && fromColumn + 1 == toColumn)
            ||(fromRoll + 1 == toRoll && fromColumn == toColumn)
            ||(fromRoll - 1 == toRoll && fromColumn == toColumn))
        {
            movePiece(fromRoll, fromColumn, toRoll, toColumn);
            return true;
        }
    }

    return false;
}

bool Game::paoCheckMove(int fromRoll, int fromColumn, int toRoll, int toColumn)
{
    if(fromRoll == toRoll || fromColumn == toColumn)
    {
        if(fromRoll > toRoll)
        {
            int count = 0;
            for(int i = fromRoll; i > toRoll; --i)
            {
                if(m_chessBoard[i][fromColumn] != nullptr)
                {
                    ++count;
                }
            }
            if(count != 2 && m_chessBoard[toRoll][toColumn] != nullptr)
            {
                return false;
            }
            if(count != 1 && m_chessBoard[toRoll][toColumn] == nullptr)
            {
                return false;
            }
        }
        if(fromRoll < toRoll)
        {
            int count = 0;
            for(int i = fromRoll; i < toRoll; ++i)
            {
                if(m_chessBoard[i][fromColumn] != nullptr)
                {
                    ++count;
                }
            }
            if(count != 2 && m_chessBoard[toRoll][toColumn] != nullptr)
            {
                return false;
            }
            if(count != 1 && m_chessBoard[toRoll][toColumn] == nullptr)
            {
                return false;
            }
        }
        if(fromColumn > toColumn)
        {
            int count = 0;
            for(int i = fromColumn; i > toColumn; --i)
            {
                if(m_chessBoard[fromRoll][i] != nullptr)
                {
                    ++count;
                }
            }
            if(count != 2 && m_chessBoard[toRoll][toColumn] != nullptr)
            {
                return false;
            }
            if(count != 1 && m_chessBoard[toRoll][toColumn] == nullptr)
            {
                return false;
            }
        }
        if(fromColumn < toColumn)
        {
            int count = 0;
            for(int i = fromColumn; i < toColumn; ++i)
            {
                if(m_chessBoard[fromRoll][i] != nullptr)
                {
                    ++count;
                }
            }
            if(count != 2 && m_chessBoard[toRoll][toColumn] != nullptr)
            {
                return false;
            }
            if(count != 1 && m_chessBoard[toRoll][toColumn] == nullptr)
            {
                return false;
            }
        }
        movePiece(fromRoll, fromColumn, toRoll, toColumn);
        return true;
    }
    return false;
}

bool Game::bingCheckMove(int fromRoll, int fromColumn, int toRoll, int toColumn)
{
    if(m_chessBoard[fromRoll][fromColumn]->side() == Piece::RED)
    {
        if(fromRoll <= 4)
        {
            if(
                  (fromRoll == toRoll && fromColumn - 1 == toColumn)
                ||(fromRoll == toRoll && fromColumn + 1 == toColumn)
                ||(fromRoll - 1 == toRoll && fromColumn == toColumn))
            {
                movePiece(fromRoll, fromColumn, toRoll, toColumn);
                return true;
            }
        }
        else
        {
            if(fromRoll - 1 == toRoll && fromColumn == toColumn)
            {
                movePiece(fromRoll, fromColumn, toRoll, toColumn);
                return true;
            }
        }
    }

    if(m_chessBoard[fromRoll][fromColumn]->side() == Piece::BLACK)
    {
        if(fromRoll >= 5)
        {
            if(
                  (fromRoll == toRoll && fromColumn - 1 == toColumn)
                ||(fromRoll == toRoll && fromColumn + 1 == toColumn)
                ||(fromRoll + 1 == toRoll && fromColumn == toColumn))
            {
                movePiece(fromRoll, fromColumn, toRoll, toColumn);
                return true;
            }
        }
        else
        {
            if(fromRoll + 1 == toRoll && fromColumn == toColumn)
            {
                movePiece(fromRoll, fromColumn, toRoll, toColumn);
                return true;
            }
        }
    }

    return false;
}

void Game::movePiece(int fromRoll, int fromColumn, int toRoll, int toColumn)
{
    if(m_chessBoard[fromRoll][fromColumn] != nullptr)
    {
        m_chessBoard[toRoll][toColumn] = m_chessBoard[fromRoll][fromColumn];
        m_chessBoard[fromRoll][fromColumn] = nullptr;
        m_chessBoard[toRoll][toColumn]->setRoll(toRoll);
        m_chessBoard[toRoll][toColumn]->setColumn(toColumn);
    }
}

Piece *Game::chessBoard(int roll, int column)
{
    return m_chessBoard[roll][column];
}
