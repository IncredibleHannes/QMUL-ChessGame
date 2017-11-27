#include "Position.h"

Position::Position()
  : x(-1), y(-1) {
}

Position::Position(int x, int y)
  : x(x), y(y) {
}

Position::Position(std::string str) {
  this->y = toupper(str[0]) - 'A';
  this->x = (str[1] - '0') - 1;
}

int Position::getX() const {
  return this->x;
}

int Position::getY() const {
  return this->y;
}

bool Position::isValid() const {
  return this->x >= 0 && this->x < 8 && this->y >= 0 && this->y < 8;
}

bool Position::operator==(const Position &toCompare) {
  return this->getX() == toCompare.getX() && this->getY() == toCompare.getY();
}
