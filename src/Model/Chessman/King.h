#ifndef KING_H
#define KING_H
#include "Chessman.h"


class King : public Chessman {
public:
  King(bool colour);
  std::list<Move> getPossibleMoves(Chessman*** board);
};

#endif
