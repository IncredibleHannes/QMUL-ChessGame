#ifndef BOARD_H
#define BOARD_H

#include <list>
#include <iostream>

#include "Chessman.h"


class Board {
public:
  // Constructores
  Board();
  Board(Board *board, Move move);

  std::list<Move> getAllPossibleMoves(Chessman::Colour colour) const;
  Chessman ** *getBoard();
  Chessman *getChessman(Position) const;
  bool applyMove(Move move);
  void undoMove(const Move move);
  bool isCheck();
  bool isCheckmate();
  bool isDraw();

private:
  // 2D array with chessman pointer
  Chessman ** *board;
  Chessman::Colour currentColour;

  // helper functions
  Chessman ** *createStartBoard();
  void move(Move move);
  void changeCurrentColour();
  Chessman::Colour swapColour(Chessman::Colour c);

  std::list<Chessman *> capturedChessmen;
  std::list<Move *> previousMoves;

};

#endif
