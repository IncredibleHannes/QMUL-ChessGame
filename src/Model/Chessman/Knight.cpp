#include "Knight.h"

Knight::Knight(Chessman::Colour colour, Position position)
  : Chessman(colour, position) {
    this->type = Chessman::Knight;
}

std::list<Move> Knight::getPossibleMoves(const Board& board) const {
  std::list<Move> moves;
  if(!isCaptured()) {

  }
  return moves;
}
