#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "Board.h"
#include "Chessman.h"

class View {
public:
  void printBoard(Board* board);
  Move* getMove();

private:
  void printBoardLine();
  void printChessman(Chessman* chessman);

};
#endif
