#include "Move.h"

Move::Move(Position origin, Position target)
  : origin(origin), target(target), type(Move::MoveType::Normal) {
}

Move::Move(Position origin, Position target, Move::MoveType type)
  : origin(origin), target(target), type(type) {
}

Position Move::getOrigin() const {
  return this->origin;
}

Position Move::getTarget() const {
  return this->target;
}

Move::MoveType Move::getType() const {
  return this->type;
}

void Move::setType(MoveType type) {
  this->type = type;
}

void Move::setCaptureMove(Chessman *chessman){
  this->type = Move::Capture;
  this->capturedChessman = chessman;
}

bool Move::operator==(const Move &toCompare) {
  return this->getOrigin() == toCompare.getOrigin() && this->getTarget() == toCompare.getTarget()
  && this->type == toCompare.getType();
}
