#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "Board.h"
#include "Chessman.h"

class View {
public:
  enum UserAction { Load, Save, MakeMove, Quit, Undo };
  void printBoard(Board *board);
  Move *getMove();
  UserAction getUserAction();
  void printGreeting();
  void printCheck();
  void printCheckmate();
  void printDraw();

private:
  void printBoardLine();
  void printBottomBoardLine();
  void printTopBoardLine();
  void printBoardLabel();
  void printChessman(Chessman *chessman);

};
#endif
