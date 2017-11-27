#ifndef MOVE_H
#define MOVE_H

#include "Position.h"

class Move {
public:
  Move(Position origin, Position target);
  Move(Position origin, Position target, bool casteling);
  Position getOrigin() const;
  Position getTarget() const;
  bool operator==(const Move &toCompare);
  bool isCasteling() const;
private:
  Position origin;
  Position target;
  bool casteling;
};
#endif
