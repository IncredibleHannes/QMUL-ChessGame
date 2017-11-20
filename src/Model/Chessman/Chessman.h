#ifndef CHESSMAN_H
#define CHESSMAN_H
#include "../Move.h"
#include "../Board.h"
#include "../Position.h"
#include <list>

class Chessman {
public:
  enum FigureType {King, Queen, Pawn, Knight, Rook, Bishop};
  // Constructores
  Chessman(bool colour);
  // getter and setter for the fields
  bool getColor();
  void capture();
  bool isCaptured();
  int getValue();
  bool isMoveValid(Board* board, Move move);
  FigureType getType();
  Position getCurrentPosition();
  void setCurrentPosition(Position position);

  virtual std::list<Move> getPossibleMoves(const Board& board) = 0;

protected:
  void setValue(int value);
  void setType(FigureType type);
  bool colour;
  bool captured;
  int value;
  FigureType type;
  Position position;
};
#endif
