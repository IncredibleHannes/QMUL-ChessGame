#ifndef MOVE_H
#define MOVE_H

#include "Position.h"
#include "Chessman.h"

class Chessman;

class Move {
public:
  enum MoveType { Normal, Capture, Casteling };

  Move(Position origin, Position target);
  Move(Position origin, Position target, MoveType type);
  Position getOrigin() const;
  Position getTarget() const;
  MoveType getType() const;
  void setType(MoveType type);
  void setCaptureMove(Chessman *chessman);
  bool operator==(const Move &toCompare);
private:
  Position origin;
  Position target;
  MoveType type;
  Chessman *capturedChessman;
};
#endif
