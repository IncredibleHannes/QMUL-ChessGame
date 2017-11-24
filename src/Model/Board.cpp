#include "Board.h"

Board::Board() {
  this->board = createStartBoard();
}

Board::Board(Board& board, Move move) {
  this->previousBoard = new Board(board);
  applyMove(move);
}

std::list<Move> getAllPossibleMoves(bool colour){
  std::list<Move> list;
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
  array2d[7][7] = new Rook(Chessman::Colour::Black, Position(0,7));
  array2d[0][1] = new Knight(Chessman::Colour::White, Position(0,1));
  array2d[0][6] = new Knight(Chessman::Colour::White, Position(0,6));
  array2d[7][1] = new Knight(Chessman::Colour::Black, Position(7,1));
  array2d[7][6] = new Knight(Chessman::Colour::Black, Position(0,6));
  array2d[0][2] = new Bishop(Chessman::Colour::White, Position(0,2));
  array2d[0][5] = new Bishop(Chessman::Colour::White, Position(0,5));
  array2d[7][2] = new Bishop(Chessman::Colour::Black, Position(7,2));
  array2d[7][5] = new Bishop(Chessman::Colour::Black, Position(0,5));
  array2d[0][3] = new Queen(Chessman::Colour::White, Position(0,3));
  array2d[0][4] = new King(Chessman::Colour::White, Position(0,4));
  array2d[7][3] = new Queen(Chessman::Colour::Black, Position(7,3));
  array2d[7][4] = new King(Chessman::Colour::Black, Position(0,4));
  // TODO: initialise and place the chessman correctly
  return array2d;
}

Chessman* Board::getChessman(Position position) {
  return this->board[position.getX()][position.getY()];
}

bool Board::applyMove(const Move move) {
  Chessman* currentChessman = getChessman(move.getOrigin());
  if(currentChessman != nullptr /* && currentChessman->isMoveValid(*this, move)*/) {
    this->board[move.getOrigin().getX()][move.getOrigin().getY()] = nullptr;
    Chessman* target = this->board[move.getTarget().getX()][move.getTarget().getY()];
    if(target != nullptr) {
      target->capture();
      capturedChessman.push_back(target);
    }
    this->board[move.getTarget().getX()][move.getTarget().getY()] = currentChessman;
    currentChessman->setCurrentPosition(move.getOrigin());
    return true;
  }
  return false;
}
