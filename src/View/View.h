#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <fstream>
#include "Board.h"
#include "Chessman.h"
#include "UserAction.h"

class View {
public:
  void printBoard(Board const *board) const;
  Chessman::FigureType getPromotionType() const;
  UserAction *getUserAction() const;
  void printGreeting() const;
  void printCheck() const;
  void printCheckmate() const;
  void printDraw() const;
  void printInvalidMove() const;
  void printInvalidUserAction() const;
  void printQuitMessage() const;

  void saveToFile(std::list<Move*> moves) const;
  std::list<Move*> loadFromFile() const;

private:
  void printBoardLine() const;
  void printBottomBoardLine() const;
  void printTopBoardLine() const;
  void printBoardLabel() const;
  void printChessman(Chessman const *chessman) const;

};
#endif
