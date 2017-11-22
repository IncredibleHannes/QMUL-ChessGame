#ifndef CHESSMAN_H
#define CHESSMAN_H

#include <list>

#include "Move.h"
#include "Board.h"
#include "Position.h"

class Board;

class Chessman {
public:
  enum FigureType { King, Queen, Pawn, Knight, Rook, Bishop };
  enum Colour : bool { Black, White };

  // Constructors
  Chessman(Colour colour, Position position);

  // getters and setters for the fields
  Colour getColour() const;
  void capture();
  bool isCaptured() const;
  int getValue() const;
  bool isMoveValid(const Board& board, const Move& move) const;
  FigureType getType() const;
  Position getCurrentPosition() const;
  void setCurrentPosition(Position position);

  virtual std::list<Move> getPossibleMoves(const Board& board) const = 0;

protected:
  void setValue(int value);
  void setType(FigureType type);

  Colour colour;
  bool captured;
  int value;
  FigureType type;
  Position position;
};
#endif
