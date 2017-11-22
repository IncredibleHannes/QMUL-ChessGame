#include "Chessman.h"

Chessman::Chessman(Colour colour, Position position)
  : colour(colour), captured(false), position(position) {
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
  this->position = position;
}

bool Chessman::isMoveValid(const Board& board, const Move& move) const {
  return true;
}
