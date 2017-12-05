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

  Move(Position origin, Position target);
  Move(Position origin, Position target, MoveType type);
  Move(const Move &move);
  ~Move();
  Position getOrigin() const;
  Position getTarget() const;
  void addType(MoveType type);
  bool hasType(MoveType type) const;
  Chessman* getCapturedChessman() const;
  void setCaptureMove(Chessman *chessman);
  bool operator==(const Move &toCompare);
private:
  Position origin;
  Position target;
  int type;
  Chessman *capturedChessman;
};
#endif
