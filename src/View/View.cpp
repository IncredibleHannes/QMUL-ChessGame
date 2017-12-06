#include "View.h"


void View::printBoard(Board const *board) const {
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

void View::printBoardLine() const {
  std::cout <<
            "  ├───┼───┼───┼───┼───┼───┼───┼───┤"
            << std::endl;
}

void View::printTopBoardLine() const {
  std::cout <<
            "  ┌───┬───┬───┬───┬───┬───┬───┬───┐"
            << std::endl;
}

void View::printBottomBoardLine() const {
  std::cout <<
            "  └───┴───┴───┴───┴───┴───┴───┴───┘"
            << std::endl;
}

void View::printBoardLabel() const {
  std::cout << "    A   B   C   D   E   F   G   H" << std::endl;
}

void View::printChessman(Chessman const *chessman) const {
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

void View::printInvalidMove() const {
  std::cout << "Invalid Move. Please try again" << std::endl;
}

void View::printInvalidUserAction() const {
  std::cout << "Invalid User Action. Please try again" << std::endl;
}

void View::printQuitMessage() const {
  std::cout << "Thank you for playing Chess with us!" << std::endl;
}

Chessman::FigureType View::getPromotionType() const {
  while (true) {
    std::cout << "Please specify the figure you want your pawn be promoted to:" << std::endl;
    std::cout << "Q(Queen), K(Knight), R(Rook), B(Bishop)" << std::endl;
    std::string type;
    std::cin >> type;
    switch (toupper(type[0])) {
      case 'Q':
        return Chessman::Queen;
      case 'K':
        return Chessman::Knight;
      case 'R':
        return Chessman::Rook;
      case 'B':
        return Chessman::Bishop;
      default:
        continue;
    }
  }
}

UserAction* View::getUserAction() const {
  std::cout << "Please select a figure: ";
  std::string origin, target;
  std::cin >> origin;
  if(origin[0] == ':') {
    switch (toupper(origin[1])) {
      case 'S':
        return new UserAction(UserAction::Save);
      case 'L':
        return new UserAction(UserAction::Load);
      case 'Q':
        return new UserAction(UserAction::Quit);
      case 'U':
        return new UserAction(UserAction::Undo);
      default:
        return new UserAction(UserAction::Invalid);
    }
  }
  std::cout << std::endl << "Please select a target: ";
  std::cin >> target;
  if(origin.length() == 2 && target.length() == 2
     && toupper(origin[0]) - 'A' >= 0 &&  toupper(origin[0]) - 'A' < 8
     && origin[1] - '0' > 0 &&  origin[1] - '0' <= 8
     && toupper(target[0]) - 'A' >= 0 &&  toupper(target[0]) - 'A' < 8
     && target[1] - '0' > 0 &&  target[1] - '0' <= 8) {
    return new UserAction(new Move(Position(origin), Position(target)));
  }
  return new UserAction(UserAction::Invalid);
}

void View::printGreeting() const {
  std::cout << " ___________________________________" << std::endl << std::endl;
  std::cout << " Welcome to my incredible chess game" << std::endl;
  std::cout << " ___________________________________" << std::endl << std::endl << std::endl;
}

void View::printCheck() const {
  std::cout << "You are in check!!!" << std::endl;
}

void View::printCheckmate() const {
  std::cout << "You are in Checkmate!!!" << std::endl;
  std::cout << "The game is finish!" << std::endl;
}

void View::printDraw() const {
  std::cout << "The game is a Draw!!!" << std::endl;
  std::cout << "The game is finish!" << std::endl;
}

void View::saveToFile(std::list<Move*> moves) const {
  std::ofstream myStream("./SaveFile.txt");
  if(myStream.is_open())
    for(Move *m : moves){
      myStream << (char) ('A' + m->getOrigin().getY()) << m->getOrigin().getX() + 1 << " "
        << (char) ('A' + m->getTarget().getY()) << m->getTarget().getX() + 1 << std::endl;
    }

}
std::list<Move*> View::loadFromFile() const {
  std::list<Move*> moves;
  std::ifstream myStream("./SaveFile.txt");
  if(!myStream.is_open()) {
    std::cout << "There is no savefile to open" << std::endl;
    return moves;
  }
  std::string line;
  while(getline(myStream,line)){
    if (line.size() == 5) {
      moves.push_back(new Move(Position(line.substr(0, 2)), Position(line.substr(3, 5))));
    }
  }
  return moves;
}
