#include "Rook.h"
#include "Board.h"

Rook::Rook(Chessman::Colour colour, Position position)
  : StraightLineMover(colour, position) {
  this->type = Chessman::Rook;
}

std::list<Move> Rook::getPossibleMoves(const Board &board) const {
  std::list<Move> moves;
  if (!isCaptured()) {
    bool top = true;
    bool right = true;
    bool bottom = true;
    bool left = true;
    int i = 1;

    while (top || right || bottom || left) {
      checkMove(board, moves, top, i, 0);
      checkMove(board, moves, right, 0, i);
      checkMove(board, moves, bottom, -i, 0);
      checkMove(board, moves, left, 0, -i);
      i++;
    }
  }
  return moves;
}
