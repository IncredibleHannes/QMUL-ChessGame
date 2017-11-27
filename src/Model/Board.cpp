#include "Board.h"

#include <cmath>
#include <iostream>

Board::Board() : currentColour(Chessman::Colour::White) {
  this->board = createStartBoard();
}

std::list<Move> Board::getAllPossibleMoves(Chessman::Colour colour) const{
  std::list<Move> list;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (this->board[i][j] != nullptr && this->board[i][j]->getColour() == colour){
         std::list<Move> moves = this->board[i][j]->getPossibleMoves(*this);
         for (Move m : moves) {
           list.push_back(m);
         }
      }
    }
  }
  return list;
}

Chessman*** Board::createStartBoard() {
  Chessman*** array2d = new Chessman**[8];
  for (int i = 0; i < 8; ++i) {
    array2d[i] = new Chessman*[8];
  }
  for (int i = 0; i < 8; ++i) {
    for (int j = 2; j < 6; ++j) {
      array2d[i][j] = nullptr;
    }
  }
  for (int i = 0; i < 8; i++) {
    array2d[1][i] = new Pawn(Chessman::Colour::White, Position(1,i));
    array2d[6][i] = new Pawn(Chessman::Colour::Black, Position(6,i));
  }
  array2d[0][0] = new Rook(Chessman::Colour::White, Position(0,0));
  array2d[0][7] = new Rook(Chessman::Colour::White, Position(0,7));
  array2d[7][0] = new Rook(Chessman::Colour::Black, Position(7,0));
  array2d[7][7] = new Rook(Chessman::Colour::Black, Position(7,7));
  array2d[0][1] = new Knight(Chessman::Colour::White, Position(0,1));
  array2d[0][6] = new Knight(Chessman::Colour::White, Position(0,6));
  array2d[7][1] = new Knight(Chessman::Colour::Black, Position(7,1));
  array2d[7][6] = new Knight(Chessman::Colour::Black, Position(7,6));
  array2d[0][2] = new Bishop(Chessman::Colour::White, Position(0,2));
  array2d[0][5] = new Bishop(Chessman::Colour::White, Position(0,5));
  array2d[7][2] = new Bishop(Chessman::Colour::Black, Position(7,2));
  array2d[7][5] = new Bishop(Chessman::Colour::Black, Position(7,5));
  array2d[0][3] = new Queen(Chessman::Colour::White, Position(0,3));
  array2d[0][4] = new King(Chessman::Colour::White, Position(0,4));
  array2d[7][3] = new Queen(Chessman::Colour::Black, Position(7,3));
  array2d[7][4] = new King(Chessman::Colour::Black, Position(7,4));
  return array2d;
}

Chessman* Board::getChessman(Position position) const {
  return this->board[position.getX()][position.getY()];
}

bool Board::applyMove(const Move move) {
  Chessman* currentChessman = getChessman(move.getOrigin());
  if(currentChessman != nullptr && currentChessman->isMoveValid(*this, move)
     && currentChessman->getColour() == currentColour) {

    Board::move(move.getOrigin(), move.getTarget());
    // Castling
    Position *rookTarget = nullptr;
    Position *rookOrigin = nullptr;
    if(currentChessman->getType() == Chessman::FigureType::King
       && move.getOrigin().getY() - move.getTarget().getY() == 2 ) {
         rookTarget = new Position(move.getTarget().getX(), move.getTarget().getY() + 1);
         rookOrigin = new Position(move.getTarget().getX(), 0);
    }
    if(currentChessman->getType() == Chessman::FigureType::King
       && move.getOrigin().getY() - move.getTarget().getY() == -2 ) {
         rookTarget = new Position(move.getTarget().getX(), move.getTarget().getY() - 1);
         rookOrigin = new Position(move.getTarget().getX(), 7);
    }
    if (rookTarget != nullptr){
      Board::move(*rookOrigin, *rookTarget);
    }
    delete rookOrigin;
    delete rookTarget;

    changeCurrentColour();
    return true;
  }
  return false;
}

void Board::move(Position origin, Position target){
  Chessman* currentChessman = this->board[origin.getX()][origin.getY()];
  this->board[origin.getX()][origin.getY()] = nullptr;

  Chessman* targetChessman = this->board[target.getX()][target.getY()];
  if(targetChessman != nullptr) {
    targetChessman->capture();
    capturedChessman.push_back(targetChessman);
  }
  this->board[target.getX()][target.getY()] = currentChessman;
  currentChessman->setCurrentPosition(target);
}

void Board::changeCurrentColour(){
  if (this->currentColour == Chessman::Colour::White) {
    this->currentColour = Chessman::Colour::Black;
  } else {
    this->currentColour = Chessman::Colour::White;
  }
}
