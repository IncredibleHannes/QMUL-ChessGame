#ifndef USERACTION_H
#define USERACTION_H

#include "Move.h"

class UserAction {
public:
  enum ActionType { MoveAction, Load, Save, Quit, Undo, Invalid};

  UserAction(ActionType type);
  UserAction(Move *move);

  ActionType getType() const;
  Move* getMove() const;

private:
  const ActionType type;
  Move *move;
};
#endif
