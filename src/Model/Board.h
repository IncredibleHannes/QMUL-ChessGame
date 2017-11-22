#ifndef BOARD_H
#define BOARD_H

#include "Chessman/Chessman.h"
#include "Move.h"
#include "Position.h"
#include <list>


class Board {
public:
  // Constructores
  Board();
  Board(Board& board, Move move);

  std::list<Move> getAllPossibleMoves(bool colour);
  Chessman*** getBoard();
  Chessman* getChessman(Position);

private:
  // 2D array with chessman pointer
  Chessman*** board;
  Board* previousBoard;

  Chessman*** createStartBoard();
  bool applyMove(Move move);

};

#endif
