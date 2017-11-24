#ifndef PAWN_H
#define PAWN_H

#include "Chessman.h"

class Pawn : public Chessman {
public:
  Pawn(Chessman::Colour colour, Position position);

  virtual std::list<Move> getPossibleMoves(const Board& board) const;
};

#endif
