#include "Knight.h"
#include "Board.h"

Knight::Knight(Chessman::Colour colour, Position position)
  : Chessman(colour, position) {
  this->type = Chessman::Knight;
}

std::list<Move> Knight::getPossibleMoves(const Board &board) const {
  std::list<Move> moves;
  if (!isCaptured()) {
    int x = this->getCurrentPosition().getX();
    int y = this->getCurrentPosition().getY();
    std::list<Position> positions = {
      Position(x + 2, y - 1), Position(x + 1, y - 2), Position(x + 2, y + 1),
      Position(x + 1, y + 2), Position(x - 2, y - 1), Position(x - 1, y - 2),
      Position(x - 2, y + 1),  Position(x - 1, y + 2)
    };

    for (Position p : positions) {
      if (p.isValid())
      { moves.push_back(Move(Position(x, y), p)); }
    }
  }
  return moves;
}
