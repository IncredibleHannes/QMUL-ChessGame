#ifndef BISHOP_H
#define BISHOP_H

#include "StraightLineMover.h"

class Bishop : public StraightLineMover {
public:
  Bishop(Chessman::Colour colour, Position position);

  virtual std::list<Move> getPossibleMoves(const Board &board) const;
};

#endif
