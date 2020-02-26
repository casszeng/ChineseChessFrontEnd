#include "ChessPiece.h"

ChessPiece::ChessPiece(QObject *parent)
    : QObject(parent)
{

}

ChessPiece::ChessPiece(QString src, Role role, Side side, int roll, int column, QObject *parent)
    : QObject(parent)
{
    m_src = src;
    m_role = role;
    m_side = side;
    m_roll = roll;
    m_column = column;
}

QString ChessPiece::src() const
{
    return m_src;
}

void ChessPiece::setSrc(const QString &src)
{
    m_src = src;
}

int ChessPiece::role() const
{
    return m_role;
}

void ChessPiece::setRole(const Role &role)
{
    m_role = role;
}

int ChessPiece::side() const
{
    return m_side;
}

void ChessPiece::setSide(const Side &side)
{
    m_side = side;
}

int ChessPiece::roll() const
{
    return m_roll;
}

void ChessPiece::setRoll(int value)
{
    m_roll = value;
}

int ChessPiece::column() const
{
    return m_column;
}

void ChessPiece::setColumn(int value)
{
    m_column = value;
}
