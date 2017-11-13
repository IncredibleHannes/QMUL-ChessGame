#ifndef CHESSMAN_H
#define CHESSMAN_H
#include "../Move.h"
#include "../Board.h"

class Chessman {
public:
  Chessman(bool colour);
  bool getColor();
  void capture();
  bool isCaptured();
  int getValue();
  bool isMoveValid(Board board, Move move);
  virtual Move** getPossibleMoves(Board board) = 0;

protected:
  void setValue(int value);
  bool colour;
  bool captured;
  int value;
};
#endif
