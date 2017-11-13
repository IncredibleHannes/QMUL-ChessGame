#include "King.h"

King::King(bool colour):Chessman(colour) {
  setValue(0);
}

Move** King::getPossibleMoves(Board board) {
  if(isCaptured()) {
    return 0;
  } else {

  }
  return 0;
}
