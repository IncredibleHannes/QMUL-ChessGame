#include "Move.h"

Move::Move(Position origin, Position target){
  this->origin = origin;
  this->target = target;
}

Position Move::getOrigin() const{
  return this->origin;
}
Position Move::getTarget() const{
  return this->target;
}
