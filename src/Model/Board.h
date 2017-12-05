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
  Board(const Board &b);

  ~Board();

  std::list<Move> getAllPossibleMoves(Chessman::Colour colour) const;
  Chessman ** *getBoard();
  Chessman *getChessman(Position) const;
  bool applyMove(Move *move);
  void applyPromotion(Move const *move, Chessman::FigureType type);
  void undoLastMove();
  bool isCheck() const;
  bool isCheckmate() const;
  bool isDraw() const;
  bool isPromotion(Move *move) const;

private:
  // 2D array with chessman pointer
  Chessman ** *board;
  Chessman::Colour currentColour;

  // helper functions
  Chessman ** *createStartBoard();
  void move(Move *move);
  void changeCurrentColour();

  std::list<Chessman *> capturedChessmen;
  std::list<Move *> previousMoves;

};

#endif
