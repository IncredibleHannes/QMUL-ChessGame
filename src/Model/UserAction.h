/**
    ChessGame
    UserAction.h
    Purpose: This class representing the actions a user can make in this game.
    Useractions can be of different types.


    @author Johannes Hartmann
    @version 1.0 2017-12-12
*/
#ifndef USERACTION_H
#define USERACTION_H

#include "Move.h"

class UserAction {
public:
  enum ActionType { MoveAction, Load, Save, Quit, Undo, Invalid};
  /**
   * Constructor should only be used if the type is not MoveAction
   * @param type Sets the type of the action
   */
  UserAction(ActionType type);
  /**
   * Constructor if the type is MoveAction
   * @param move representing the move that will be done with this action
   */
  UserAction(Move *move);
  /**
   * Desctuctor deletes the type is a MoveAction
   */
  ~UserAction();

  ActionType getType() const;
  /**
   * Getter for the move
   * @return Move pointer if the type is MoveAction or nullptr for each other type
   */
  Move* getMove() const;

private:
  const ActionType type;
  Move *move;
};
#endif
