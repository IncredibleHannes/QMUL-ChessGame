#ifndef QUEEN_H
#define QUEEN_H

#include "StraightLineMover.h"

class Queen : public StraightLineMover {
public:
  Queen(Chessman::Colour colour, Position position);
  virtual Chessman* clone() const;

  virtual std::list<Move> getPossibleMoves(const Board &board) const;
};

#endif
