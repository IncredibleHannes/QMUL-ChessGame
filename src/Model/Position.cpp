#include "Position.h"

Position::Position(int x, int y)
  : x(x), y(y) {
}

int Position::getX() const {
  return this->x;
}

int Position::getY() const {
  return this->y;
}
