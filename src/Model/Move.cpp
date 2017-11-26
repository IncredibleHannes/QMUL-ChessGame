#include "Move.h"

Move::Move(Position origin, Position target)
  : origin(origin), target(target) {
}

Position Move::getOrigin() const{
  return this->origin;
}
Position Move::getTarget() const{
  return this->target;
}

bool Move::operator==(const Move &toCompare){
  return this->getOrigin() == toCompare.getOrigin() && this->getTarget() == toCompare.getTarget();
}
