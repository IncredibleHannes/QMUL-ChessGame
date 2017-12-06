#ifndef CHESSMAN_H
#define CHESSMAN_H

#include <list>

#include "Move.h"
#include "Position.h"

class Board;
class Move;

class Chessman {
public:
  enum FigureType { King, Queen, Pawn, Knight, Rook, Bishop };
  enum Colour : bool { Black, White };

  // Constructors
  Chessman(Colour colour, Position position);
  virtual Chessman* clone() const = 0;
  virtual ~Chessman() = default;

  // getters and setters for the fields
  Colour getColour() const;
  void capture();
  bool isCaptured() const;
  void unsetCapture();
  bool isMoveValid(const Board &board, const Move &move) const;
  FigureType getType() const;
  Position getCurrentPosition() const;
  void setCurrentPosition(Position position);
  bool wasMoved() const;

  virtual std::list<Move> getPossibleMoves(const Board &board) const = 0;

protected:
  Colour colour;
  bool captured;
  bool moved;
  FigureType type;
  Position position;
};

Chessman::Colour operator!(Chessman::Colour colour);
#endif
