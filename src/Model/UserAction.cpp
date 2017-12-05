#include "UserAction.h"

UserAction::UserAction(ActionType type)
  : type(type), move(nullptr) {

}
UserAction::UserAction(Move *move)
  : type(UserAction::MoveAction), move(move){

}
UserAction::~UserAction() {
  delete this->move;
}

UserAction::ActionType UserAction::getType() const {
  return this->type;
}

// Returns nullptr if user action is not MoveAction
Move* UserAction::getMove() const {
  return this->move;
}
