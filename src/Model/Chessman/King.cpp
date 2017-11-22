#include "King.h"

King::King(bool colour):Chessman(colour) {
  setValue(0);
  setType(FigureType::King);
}

std::list<Move> King::getPossibleMoves(Chessman*** board) {
  if(isCaptured()) {
    return NULL;
  } else {

  }
  return NULL;
}
