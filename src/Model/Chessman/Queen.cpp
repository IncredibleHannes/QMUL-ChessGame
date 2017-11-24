#include "Queen.h"

Queen::Queen(Chessman::Colour colour, Position position)
  : Chessman(colour, position) {
    this->type = Chessman::Queen;
}

std::list<Move> Queen::getPossibleMoves(const Board& board) const {
  std::list<Move> moves;
  if(!isCaptured()) {

  }
  return moves;
}
