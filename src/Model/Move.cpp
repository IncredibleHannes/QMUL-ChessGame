#include "Move.h"

Move::Move(Position origin, Position target)
  : origin(origin), target(target), casteling(false) {
}

Move::Move(Position origin, Position target, bool casteling)
  : origin(origin), target(target), casteling(casteling) {
}

Position Move::getOrigin() const {
  return this->origin;
}

Position Move::getTarget() const {
  return this->target;
}

bool Move::isCasteling() const {
  return this->casteling;
}

bool Move::operator==(const Move &toCompare) {
  return this->getOrigin() == toCompare.getOrigin() && this->getTarget() == toCompare.getTarget();
}
