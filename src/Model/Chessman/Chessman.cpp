#include "Chessman.h"

Chessman::Chessman(bool colour) {
  this->colour = colour;
  this->captured = false;
}

bool Chessman::getColor() {
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

bool Chessman::isMoveValid(Board board, Move move) {
  return true;
}
