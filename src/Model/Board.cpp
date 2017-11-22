#include "Board.h"

Board::Board(){
  this->board = createStartBoard();
}

Board::Board(Board& board, Move move){
  this->previousBoard = new Board(board);
  applyMove(move);
}

std::list<Move> getAllPossibleMoves(bool colour){
  std::list<Move> list;
  return list;
}

Chessman*** Board::createStartBoard() {
  Chessman*** array2d = new Chessman**[7];
  for (int i = 0; i < 8; ++i) {
    array2d[i] = new Chessman*[7];
  }
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      array2d[i][j] = 0;
    }
  }
  // TODO: initialise and place the chessman correctly
  return array2d;
}

Chessman* Board::getChessman(Position position) {
  return this->board[position.getX()][position.getY()];
}

bool Board::applyMove(Move move) {
//  Chessman* currentChessman = getChessman(move.getOrigin());
//  if(currentChessman != 0 && currentChessman->isMoveValid(this->board, move)) {
//    this->board[move.getOrigin().getX()][move.getOrigin().getY()] = 0;
//    this->board[move.getTarget().getX()][move.getTarget().getY()] = currentChessman;
//    return true;
//  }
  return false;
}
