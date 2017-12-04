#ifndef KNIGHT_H
#define KNIGHT_H

#include "Chessman.h"


class Knight : public Chessman {
public:
  Knight(Chessman::Colour colour, Position position);
  virtual Chessman* clone() const;

  virtual std::list<Move> getPossibleMoves(const Board &board) const;
};

#endif
