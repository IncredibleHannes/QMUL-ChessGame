#include "Chessman.h"
#include "Board.h"

Chessman::Chessman(Colour colour, Position position)
  : colour(colour), captured(false), moved(false), position(position) {
}

Chessman::Colour Chessman::getColour() const {
  return colour;
}

void Chessman::capture() {
  this->captured = true;
}

bool Chessman::isCaptured() const {
  return captured;
}

void Chessman::unsetCapture() {
  this->captured = false;
}

bool Chessman::isMoveValid(const Board &board, const Move &move) const {
  std::list<Move> moves = this->getPossibleMoves(board);
  for (std::list<Move>::iterator it = moves.begin(); it != moves.end(); it++) {
    if (*it == move)
    { return true; }
  }
  return false;
}

Chessman::FigureType Chessman::getType() const {
  return this->type;
}

Position Chessman::getCurrentPosition() const {
  return this->position;
}

void Chessman::setCurrentPosition(Position position) {
  this->moved = true;
  this->position = position;
}

bool Chessman::wasMoved() const {
  return this->moved;
}

Chessman::Colour operator!(Chessman::Colour colour) {
  return static_cast<Chessman::Colour>(! static_cast<bool>(colour));
}
