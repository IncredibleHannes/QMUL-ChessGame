/**
    ChessGame
    Move.h
    Purpose: Representing the a move in the game. A move can have multiple
    different types corresponding to the sandart chess rules.
    This class implements no game logic. Types will be set from outside.


    @author Johannes Hartmann
    @version 1.0 2017-12-12
*/

#ifndef MOVE_H
#define MOVE_H

#include "Position.h"
#include "Chessman.h"

class Chessman;

class Move {
public:
  enum MoveType : int {
    Normal = 0x00,
    Capture = 0x01,
    Casteling = 0x02,
    Promotion = 0x04
  };
  /**
   * Standart constructor with a origin and taget. Sets move type to normal
   * @param origin Origin of the move
   * @param target Target of the move
   */
  Move(Position origin, Position target);
  /**
   * Standart constuctor with a aditional option to set a type
   * @param origin Origin of the move
   * @param target Target of the move
   * @param type   Type of the move
   */
  Move(Position origin, Position target, MoveType type);
  /**
   * Copy constructor witch copies the caured chessman aswell if its not a nullptr
   * @param move Move to copy
   */
  Move(const Move &move);
  /**
   * Desturctor deletes everything including the capured chessman if not nullptr
   */
  ~Move();
  /**
   * Getter for origin
   * @return Origin of the mvoe
   */
  Position getOrigin() const;
  /**
   * Getter for target
   * @return target of the move
   */
  Position getTarget() const;
  /**
   * Adds a type to the move.
   * @param type Type to add to the move
   */
  void addType(MoveType type);
  /**
   * Checks if the move is of the given type
   * @param  type Type to check against
   * @return      True if the move has this type
   */
  bool hasType(MoveType type) const;
  /**
   * Returns a pointer to the captured chessman if the move is a capture. If
   * not it returns a nullptr
   * @return Pointer to chessman
   */
  Chessman* getCapturedChessman() const;
  /**
   * Adds the type capture to the move and stores the given chassmanpointer.
   * @param chessman The chessman tha was captured
   */
  void setCaptureMove(Chessman *chessman);
  /**
   * Equals opertator overloaded
   */
  bool operator==(const Move &toCompare);
private:
  Position origin;
  Position target;
  int type;
  Chessman *capturedChessman;
};
#endif
