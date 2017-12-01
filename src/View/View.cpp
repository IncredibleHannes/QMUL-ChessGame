#include "View.h"

void View::printBoard(Board *board) {
  printBoardLabel();
  printTopBoardLine();
  for (int i = 0; i < 8; i ++) {

    std::cout << i + 1 << " │ ";
    for (int j = 0; j < 8; j ++) {
      printChessman(board->getChessman(Position(i, j)));
      std::cout << " │ ";
    }
    std::cout << " "  << i + 1 << std::endl;
    if (i < 7) {
      printBoardLine();
    }
  }
  printBottomBoardLine();
  printBoardLabel();

}

void View::printBoardLine() {
  std::cout <<
            "  ├───┼───┼───┼───┼───┼───┼───┼───┤"
            << std::endl;
}

void View::printTopBoardLine() {
  std::cout <<
            "  ┌───┬───┬───┬───┬───┬───┬───┬───┐"
            << std::endl;
}

void View::printBottomBoardLine() {
  std::cout <<
            "  └───┴───┴───┴───┴───┴───┴───┴───┘"
            << std::endl;
}

void View::printBoardLabel() {
  std::cout << "    A   B   C   D   E   F   G   H" << std::endl;
}

void View::printChessman(Chessman *chessman) {
  if (chessman == nullptr) {
    std::cout << " ";
    return;
  }
  if (chessman->getColour() != Chessman::White) {
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

Move *View::getMove() {
  std::cout << "Please select a figure: ";
  std::string origin, target;
  std::cin >> origin;
  std::cout << std::endl << "Please select a target: ";
  std::cin >> target;

  return new Move(Position(origin), Position(target));
}

void View::printGreeting() {
  std::cout << " ___________________________________" << std::endl << std::endl;
  std::cout << " Welcome to my incredible chess game" << std::endl;
  std::cout << " ___________________________________" << std::endl << std::endl << std::endl;
}

void View::printCheck() {
  std::cout << "You are in check!!!" << std::endl;
}

void View::printCheckmate() {
  std::cout << "You are in Checkmate!!!" << std::endl;
  std::cout << "The game is finish!" << std::endl;
}

void View::printDraw() {
  std::cout << "The game is a Draw!!!" << std::endl;
  std::cout << "The game is finish!" << std::endl;
}
