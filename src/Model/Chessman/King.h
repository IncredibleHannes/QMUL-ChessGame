#ifndef KING_H
#define KING_H

#include "Chessman.h"

class King : public Chessman {
public:
  King(Chessman::Colour colour, Position position);

  virtual Chessman* clone() const;

  virtual std::list<Move> getPossibleMoves(const Board &board) const;
};

#endif
