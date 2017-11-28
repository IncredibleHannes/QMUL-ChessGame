#include "StraightLineMover.h"

StraightLineMover::StraightLineMover(Chessman::Colour colour, Position position)
  : Chessman(colour, position) {
}

void StraightLineMover::checkMove(const Board &board, std::list<Move> &moves,
                                  bool &direction, int dx, int dy) const {
  int x = this->getCurrentPosition().getX();
  int y = this->getCurrentPosition().getY();

  if (!direction) { return; }
  Position p = Position(x + dx, y + dy);
  if (!p.isValid()) {
    direction = false;
    return;
  }
  if (board.getChessman(p) != nullptr) {
    direction = false;
    if (board.getChessman(p)->getColour() != this->colour) {
      moves.push_back(Move(Position(x, y), p));
    }
  } else {
    moves.push_back(Move(Position(x, y), p));
  }
}
