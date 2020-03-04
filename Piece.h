#ifndef PIECE_H
#define PIECE_H

#include <QObject>

class Piece : public QObject
{
    Q_OBJECT

public:
    enum Role{
            CHE, MA, XIANG, SHI, PAO, ZU, JIANG, ERROR
    };
    Q_ENUM(Role)
    enum Side{
        RED, BLACK, ERR
    };
    Q_ENUM(Side)
    explicit            Piece(    Role role, Side side, int roll, int column, QObject *parent = nullptr);

   Q_INVOKABLE int role() const;
   Q_INVOKABLE void setRole(const Role &role);

   Q_INVOKABLE int side() const;
   Q_INVOKABLE void setSide(const Side &side);

   Q_INVOKABLE int roll() const;
   Q_INVOKABLE void setRoll(int value);

   Q_INVOKABLE int column() const;
   Q_INVOKABLE void setColumn(int value);

   signals:

   private:
       Role m_role; //Role of the chess piece
       Side m_side;//Red or Black
       //Position of the chess piece
       int m_roll;
       int m_column;
};

#endif // PIECE_H
