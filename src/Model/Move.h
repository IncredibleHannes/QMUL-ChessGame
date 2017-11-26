#ifndef MOVE_H
#define MOVE_H

#include "Position.h"

class Move{
public:
  Move(Position origin, Position target);
  Position getOrigin() const;
  Position getTarget() const;
  bool operator==(const Move &toCompare);
private:
  Position origin;
  Position target;
};
#endif
