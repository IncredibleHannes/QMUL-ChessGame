#include "Chessman.h"

#include "Board.h"

Chessman::Chessman(Colour colour, Position position)
  : colour(colour), captured(false), moved(false), position(position) {
}

Chessman::Colour Chessman::getColour() const {
  return colour;
}

bool Chessman::isCaptured() const {
  return captured;
}

void Chessman::setValue(int value) {
  this->value = value;
}

int Chessman::getValue() const {
  return this->value;
}

void Chessman::capture() {
  this->captured = true;
}

Chessman::FigureType Chessman::getType() const {
  return this->type;
}

void Chessman::setType(Chessman::FigureType type) {
  this->type = type;
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

bool Chessman::isMoveValid(const Board &board, const Move &move) const {
  std::list<Move> moves = board.getAllPossibleMoves(this->getColour());
  for (std::list<Move>::iterator it = moves.begin(); it != moves.end(); it++) {
    if (*it == move)
    { return true; }
  }
  return false;
}
