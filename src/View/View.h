#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "Board.h"
#include "Chessman.h"

class View {
public:
  void printBoard(Board *board);
  Move *getMove();
  void printGreeting();

private:
  void printBoardLine();
  void printBottomBoardLine();
  void printTopBoardLine();
  void printBoardLabel();
  void printChessman(Chessman *chessman);

};
#endif
