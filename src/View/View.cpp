#include "View.h"

void View::printBoard(Board* board){
  for (int i = 0; i < 8; i ++) {
    printBoardLine();
    std::cout << "| ";
    for (int j = 0; j < 8; j ++) {
        printChessman(board->getChessman(Position(i,j)));
        std::cout << " | ";
    }
    std::cout << std::endl;
  }
  printBoardLine();

}

void View::printBoardLine(){
  std::cout << "+-------------------------------+" << std::endl;
}

void View::printChessman(Chessman* chessman){
  if (chessman == nullptr) {
    std::cout << " ";
    return;
  }
  if (chessman->getColour() == Chessman::White){
    switch (chessman->getType()) {
      case Chessman::Bishop :
        std::cout << "♗";
        break;
      case Chessman::King :
        std::cout << "♔";
        break;
      case Chessman::Knight :
        std::cout << "♘";
        break;
      case Chessman::Pawn :
        std::cout << "♙";
        break;
      case Chessman::Queen :
        std::cout << "♕";
        break;
      case Chessman::Rook :
        std::cout << "♖";
        break;
      }
  } else {
    switch (chessman->getType()) {
      case Chessman::Bishop :
        std::cout << "♝";
        break;
      case Chessman::King :
        std::cout << "♚";
        break;
      case Chessman::Knight :
        std::cout << "♞";
        break;
      case Chessman::Pawn :
        std::cout << "♟";
        break;
      case Chessman::Queen :
        std::cout << "♛";
        break;
      case Chessman::Rook :
        std::cout << "♜";
        break;
      }
  }
}

Move* View::getMove(){
  std::cout << "Enter X coordinate of your figure" << std::endl;
  int x1, x2, y1, y2;
  std::cin >> x1;
  std::cout << std::endl << "Enter Y coordinate of your figure" << std::endl;
  std::cin >> y1;
  std::cout << std::endl << "Enter X coordinate of your target" << std::endl;
  std::cin >> x2;
  std::cout << std::endl << "Enter Y coordinate of your target" << std::endl;
  std::cin >> y2;
  return new Move(Position(x1,y1), Position(x2, y2));
}
