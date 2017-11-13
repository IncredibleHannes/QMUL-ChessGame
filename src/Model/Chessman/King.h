#ifndef KING_H
#define KING_H
#include "Chessman.h"


class King : public Chessman {
public:
  King(bool colour);
  Move** getPossibleMoves(Board board);
};

#endif
