#ifndef BOARD_H
#define BOARD_H

#include <list>
#include <iostream>

#include "Chessman.h"


class Board {
public:
  // Constructores
  Board();
  Board(std::list<Move*> moves);

  std::list<Move> getAllPossibleMoves(Chessman::Colour colour) const;
  Chessman ** *getBoard();
  Chessman *getChessman(Position) const;
  bool applyMove(Move move);
  void undoLastMove();
  bool isCheck();
  bool currentlyInCheck();
  bool isCheckmate();
  bool isDraw();
  bool isPromotion(Move move);

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
