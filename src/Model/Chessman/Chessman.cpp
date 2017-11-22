#include "Chessman.h"

Chessman::Chessman(Colour colour) {
  this->colour = colour;
  this->captured = false;
}

Colour Chessman::getColour() {
  return colour;
}

bool Chessman::isCaptured() {
  return captured;
}

void Chessman::setValue(int value) {
  this->value = value;
}

int Chessman::getValue() {
  return value;
}

void Chessman::capture() {
  this->captured = true;
}

Chessman::FigureType Chessman::getType() {
  return this->type;
}

void Chessman::setType(Chessman::FigureType type) {
  this->type = type;
}

Position Chessman::getCurrentPosition() {
  return this->position;
}

void Chessman::setCurrentPosition(Position position) {
  this->position = position;
}

bool Chessman::isMoveValid(Chessman*** board, Move move) {
  return true;
}
