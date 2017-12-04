#include "Queen.h"
#include "Board.h"

Queen::Queen(Chessman::Colour colour, Position position)
  : StraightLineMover(colour, position) {
  this->type = Chessman::Queen;
}

Chessman* Queen::clone() const {
  return new Queen(*this);
}

std::list<Move> Queen::getPossibleMoves(const Board &board) const {
  std::list<Move> moves;
  if (!isCaptured()) {
    bool top = true;
    bool right = true;
    bool bottom = true;
    bool left = true;
    bool leftTop = true;
    bool rightTop = true;
    bool leftBottom = true;
    bool rightBottom = true;
    int i = 1;

    while (top || right || bottom || left || leftTop || rightTop || leftBottom || rightBottom) {
      checkMove(board, moves, leftTop, i, -i);
      checkMove(board, moves, rightTop, i, i);
      checkMove(board, moves, leftBottom, -i, -i);
      checkMove(board, moves, rightBottom, -i, i);
      checkMove(board, moves, top, i, 0);
      checkMove(board, moves, right, 0, i);
      checkMove(board, moves, bottom, -i, 0);
      checkMove(board, moves, left, 0, -i);
      i++;
    }
  }
  return moves;
}
