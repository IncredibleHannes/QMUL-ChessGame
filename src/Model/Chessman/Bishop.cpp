#include "Bishop.h"
#include "Board.h"

Bishop::Bishop(Chessman::Colour colour, Position position)
  : Chessman(colour, position) {
    this->type = Chessman::Bishop;
}

std::list<Move> Bishop::getPossibleMoves(const Board& board) const {
  std::list<Move> moves;
  if(!isCaptured()) {

  }
  return moves;
}
