#ifndef ROOK_H
#define ROOK_H

#include "Chessman.h"

class Rook : public Chessman {
public:
  Rook(Chessman::Colour colour, Position position);

  virtual std::list<Move> getPossibleMoves(const Board &board) const;
};

#endif
