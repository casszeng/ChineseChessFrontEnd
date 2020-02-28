#include "CheRule.h"
#include "Game.h"

Game::Game(QObject *parent) : QObject(parent)
{
    m_rules[ChessPiece::CHE] = new CheRule();
    m_rules[ChessPiece::MA] = new CheRule();
    m_rules[ChessPiece::XIANG] = new CheRule();
    m_rules[ChessPiece::PAO] = new CheRule();
    m_rules[ChessPiece::ZU] = new CheRule();
    m_rules[ChessPiece::SHI] = new CheRule();
    m_rules[ChessPiece::JIANG] = new CheRule();
}

void Game::initNewGame()
{
    m_chessPieces.clear();
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/hongche.png", ChessPiece::CHE, ChessPiece::RED, 9, 0));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/hongche.png", ChessPiece::CHE, ChessPiece::RED, 9, 8));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/hongma.png", ChessPiece::MA, ChessPiece::RED, 9, 1));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/hongma.png", ChessPiece::MA, ChessPiece::RED, 9, 7));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/hongxiang.png", ChessPiece::XIANG, ChessPiece::RED, 9, 2));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/hongxiang.png", ChessPiece::XIANG, ChessPiece::RED, 9, 6));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/hongshi.png", ChessPiece::SHI, ChessPiece::RED, 9, 3));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/hongshi.png", ChessPiece::SHI, ChessPiece::RED, 9, 5));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/hongshuai.png", ChessPiece::JIANG, ChessPiece::RED, 9, 4));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/hongpao.png", ChessPiece::PAO, ChessPiece::RED, 7, 1));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/hongpao.png", ChessPiece::PAO, ChessPiece::RED, 7, 7));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/bing.png", ChessPiece::ZU, ChessPiece::RED, 6, 0));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/bing.png", ChessPiece::ZU, ChessPiece::RED, 6, 2));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/bing.png", ChessPiece::ZU, ChessPiece::RED, 6, 4));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/bing.png", ChessPiece::ZU, ChessPiece::RED, 6, 6));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/bing.png", ChessPiece::ZU, ChessPiece::RED, 6, 8));

    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/heiche.png", ChessPiece::CHE, ChessPiece::BLACK, 0, 0));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/heiche.png", ChessPiece::CHE, ChessPiece::BLACK, 0, 8));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/heima.png", ChessPiece::MA, ChessPiece::BLACK, 0, 1));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/heima.png", ChessPiece::MA, ChessPiece::BLACK, 0, 7));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/heixiang.png", ChessPiece::XIANG, ChessPiece::BLACK, 0, 2));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/heixiang.png", ChessPiece::XIANG, ChessPiece::BLACK, 0, 6));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/heishi.png", ChessPiece::SHI, ChessPiece::BLACK, 0, 3));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/heishi.png", ChessPiece::SHI, ChessPiece::BLACK, 0, 5));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/jiang.png", ChessPiece::JIANG, ChessPiece::BLACK, 0, 4));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/heipao.png", ChessPiece::PAO, ChessPiece::BLACK, 2, 1));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/heipao.png", ChessPiece::PAO, ChessPiece::BLACK, 2, 7));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/zu.png", ChessPiece::ZU, ChessPiece::BLACK, 3, 0));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/zu.png", ChessPiece::ZU, ChessPiece::BLACK, 3, 2));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/zu.png", ChessPiece::ZU, ChessPiece::BLACK, 3, 4));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/zu.png", ChessPiece::ZU, ChessPiece::BLACK, 3, 6));
    m_chessPieces.push_back(new ChessPiece("qrc:/chessPieces/Images/zu.png", ChessPiece::ZU, ChessPiece::BLACK, 3, 8));

    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            m_board[i][j] = nullptr;
        }
    }

    for(auto chess: m_chessPieces)
    {
        m_board[chess->roll()][chess->column()] = chess;
    }
}

QString Game::src(int index)
{
    if(index > 31)
    {
        return "";
    }
    return m_chessPieces[index]->src();
}

int Game::role(int index)
{
    if(index > 31)
    {
        return ChessPiece::ERROR;
    }
    return m_chessPieces[index]->role();
}

bool Game::alive(int index)
{
    if(index > 31)
    {
        return false;
    }
    return m_chessPieces[index]->alive();
}

int Game::side(int index)
{
    if(index > 31)
    {
        return ChessPiece::ERR;
    }
    return m_chessPieces[index]->side();
}

int Game::roll(int index)
{
    if(index > 31)
    {
        return -1;
    }
    return m_chessPieces[index]->roll();
}

int Game::column(int index)
{
    if(index > 31)
    {
        return -1;
    }
    return m_chessPieces[index]->column();
}

bool Game::checkMove(int fromr, int tor, int fromc, int toc)
{
    int result = 0;
    for(auto chess: m_chessPieces)
    {
        if(chess->roll() == fromr && chess->column() == fromc)
        {
            result = m_rules[chess->role()]->checkMove(chess, m_board, tor, toc);
            if(result == 2)
            {
                chess->setRoll(tor);
                chess->setColumn(toc);
                m_board[fromr][fromc] = nullptr;
                m_board[tor][toc]->setAlive(false);
                m_board[tor][toc] = chess;

            }
            else if(result == 1)
            {
                chess->setRoll(tor);
                chess->setColumn(toc);
                m_board[fromr][fromc] = nullptr;
                m_board[tor][toc] = chess;
            }
            break;
        }
    }

    return result != 0;
}


