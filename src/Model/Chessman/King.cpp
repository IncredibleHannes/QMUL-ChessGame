#include "King.h"

King::King(bool colour):Chessman(colour) {
  setValue(0);
  setType(FigureType::King);
}

Move** King::getPossibleMoves(Board board) {
  if(isCaptured()) {
    return 0;
  } else {

  }
  return 0;
}
