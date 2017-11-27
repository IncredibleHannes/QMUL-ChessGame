#ifndef BISHOP_H
#define BISHOP_H

#include "Chessman.h"

class Bishop : public Chessman {
public:
  Bishop(Chessman::Colour colour, Position position);

  virtual std::list<Move> getPossibleMoves(const Board &board) const;
};

#endif
