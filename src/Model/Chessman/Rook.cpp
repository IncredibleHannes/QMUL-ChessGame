#include "Rook.h"

Rook::Rook(Chessman::Colour colour, Position position)
  : Chessman(colour, position) {
    this->type = Chessman::Rook;
}

std::list<Move> Rook::getPossibleMoves(const Board& board) const {
  std::list<Move> moves;
  if(!isCaptured()) {

  }
  return moves;
}
