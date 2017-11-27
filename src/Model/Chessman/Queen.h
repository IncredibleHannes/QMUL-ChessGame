#ifndef QUEEN_H
#define QUEEN_H

#include "Chessman.h"

class Queen : public Chessman {
public:
  Queen(Chessman::Colour colour, Position position);

  virtual std::list<Move> getPossibleMoves(const Board &board) const;
};

#endif
