#include "Pawn.h"

Pawn::Pawn(Chessman::Colour colour, Position position)
  : Chessman(colour, position) {
    this->type = Chessman::Pawn;
}

std::list<Move> Pawn::getPossibleMoves(const Board& board) const {
  std::list<Move> moves;
  if(!isCaptured()) {

  }
  return moves;
}
