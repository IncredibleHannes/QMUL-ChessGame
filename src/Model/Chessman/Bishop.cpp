#include "Bishop.h"
#include "Board.h"

Bishop::Bishop(Chessman::Colour colour, Position position)
  : StraightLineMover(colour, position) {
  this->type = Chessman::Bishop;
}

Chessman* Bishop::clone() const {
  return new Bishop(*this);
}

std::list<Move> Bishop::getPossibleMoves(const Board &board) const {
  std::list<Move> moves;
  if (!isCaptured()) {
    bool leftTop = true;
    bool rightTop = true;
    bool leftBottom = true;
    bool rightBottom = true;
    int i = 1;

    while (leftTop || rightTop || leftBottom || rightBottom) {
      checkMove(board, moves, leftTop, i, -i);
      checkMove(board, moves, rightTop, i, i);
      checkMove(board, moves, leftBottom, -i, -i);
      checkMove(board, moves, rightBottom, -i, i);
      i++;
    }
  }
  return moves;
}
