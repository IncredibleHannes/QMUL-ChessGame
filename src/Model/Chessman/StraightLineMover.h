#ifndef STRAIGHTLINEMOVER_H
#define STRAIGHTLINEMOVER_H

#include "Chessman.h"
#include "Board.h"

class StraightLineMover : public Chessman {
public:
  StraightLineMover(Colour colour, Position position);
protected:
  void checkMove(const Board &board, std::list<Move> &moves, bool &direction, int dx, int dy) const;
};
#endif
