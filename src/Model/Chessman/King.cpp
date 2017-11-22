#include "King.h"

King::King(Chessman::Colour colour, Position position)
  : Chessman(colour, position) {
}

std::list<Move> King::getPossibleMoves(const Board& board) const {
  std::list<Move> moves;
  if(!isCaptured()) {

  }
  return moves;
}
