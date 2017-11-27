#ifndef BOARD_H
#define BOARD_H

#include <list>
#include <iostream>

#include "Chessman.h"
#include "Pawn.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Move.h"
#include "Position.h"

class Board {
public:
  // Constructores
  Board();

  std::list<Move> getAllPossibleMoves(Chessman::Colour colour) const;
  Chessman*** getBoard();
  Chessman *getChessman(Position) const;
  bool applyMove(const Move move);

private:
  // 2D array with chessman pointer
  Chessman*** board;
  Board *previousBoard;
  Chessman::Colour currentColour;

  // helper functions
  Chessman*** createStartBoard();
  void move(Position origin, Position target);
  void changeCurrentColour();

  std::list<Chessman *> capturedChessman;

};

#endif
