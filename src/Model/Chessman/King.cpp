#include "King.h"
#include "Board.h"

King::King(Chessman::Colour colour, Position position)
  : Chessman(colour, position) {
    this->type = Chessman::King;
}

std::list<Move> King::getPossibleMoves(const Board& board) const {
  std::list<Move> moves;
  if(!isCaptured()) {

  }
  return moves;
}
