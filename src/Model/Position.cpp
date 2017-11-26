#include "Position.h"

Position::Position(int x, int y)
  : x(x), y(y) {
}

Position::Position(std::string str) {
  this->y = toupper(str[0]) - 'A';
  this->x =(str[1] - '0') - 1;
}

int Position::getX() const {
  return this->x;
}

int Position::getY() const {
  return this->y;
}

bool Position::operator==(const Position& toCompare){
  return this->getX() == toCompare.getX() && this->getY() == toCompare.getY();
}
