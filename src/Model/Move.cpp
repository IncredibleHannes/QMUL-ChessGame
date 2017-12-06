#include "Move.h"

Move::Move(Position origin, Position target)
  : origin(origin), target(target), type(Move::MoveType::Normal), capturedChessman(nullptr) {
}

Move::Move(Position origin, Position target, Move::MoveType type)
  : origin(origin), target(target), type(type), capturedChessman(nullptr) {
}

Move::Move(const Move &move)
  : origin(move.origin), target(move.target), type(move.type), capturedChessman(){
    if(move.getCapturedChessman() == nullptr) {
      this->capturedChessman = nullptr;
    } else {
      this->capturedChessman = move.getCapturedChessman()->clone();
    }
}

Move::~Move() {
  if(this->capturedChessman != nullptr) {
    delete this->capturedChessman;
  }
}

Position Move::getOrigin() const {
  return this->origin;
}

Position Move::getTarget() const {
  return this->target;
}

void Move::addType(MoveType type) {
  this->type |= type;
}

bool Move::hasType(MoveType type) const {
  return this->type & type;
}

Chessman* Move::getCapturedChessman() const {
  return this->capturedChessman;
}

void Move::setCaptureMove(Chessman *chessman) {
  this->addType(Move::Capture);
  this->capturedChessman = chessman->clone();
}

bool Move::operator==(const Move &toCompare) {
  return this->getOrigin() == toCompare.getOrigin() && this->getTarget() == toCompare.getTarget()
         && this->type == toCompare.type;
}
