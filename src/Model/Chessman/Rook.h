#ifndef ROOK_H
#define ROOK_H

#include "StraightLineMover.h"

class Rook : public StraightLineMover {
public:
  Rook(Chessman::Colour colour, Position position);
  virtual Chessman* clone() const;

  virtual std::list<Move> getPossibleMoves(const Board &board) const;
};

#endif
