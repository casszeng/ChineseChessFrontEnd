#include "Piece.h"

Piece::Piece(Role role, Side side, int roll, int column, QObject *parent)
    : QObject(parent),
      m_role(role),
      m_side(side),
      m_roll(roll),
      m_column(column)
{

}

int Piece::role() const
{
    return m_role;
}

void Piece::setRole(const Role &role)
{
    m_role = role;
}

int Piece::side() const
{
    return m_side;
}

void Piece::setSide(const Side &side)
{
    m_side = side;
}

int Piece::roll() const
{
    return m_roll;
}

void Piece::setRoll(int value)
{
    m_roll = value;
}

int Piece::column() const
{
    return m_column;
}

void Piece::setColumn(int value)
{
    m_column = value;
}
