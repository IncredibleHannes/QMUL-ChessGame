#include "Bishop.h"
#include "Board.h"

#include <iostream>

Bishop::Bishop(Chessman::Colour colour, Position position)
  : Chessman(colour, position) {
    this->type = Chessman::Bishop;
}

std::list<Move> Bishop::getPossibleMoves(const Board& board) const {
  std::list<Move> moves;
  if(!isCaptured()) {
    int x = this->getCurrentPosition().getX();
    int y = this->getCurrentPosition().getY();
    bool leftTop = true;
    bool rightTop = true;
    bool leftBottom = true;
    bool rightBottom = true;
    int i = 1;

    while (leftTop || rightTop || leftBottom || rightBottom) {
      if (leftTop) {
        if (x + i >= 0 && x + i < 8 && y - i >= 0 && y - i < 8) {
          if(board.getChessman(Position(x + i,y - i)) != nullptr){
            leftTop = false;
          }
          moves.push_back(Move(Position(x, y), Position(x + i, y - i)));
        } else {
          leftTop = false;
        }
      }
      if (rightTop) {
        if (x + i >= 0 && x + i < 8 && y + i >= 0 && y + i < 8) {
          if(board.getChessman(Position(x + i,y + i)) != nullptr){
            rightTop = false;
          }
          moves.push_back(Move(Position(x, y), Position(x + i, y + i)));
        } else {
          rightTop = false;
        }
      }
      if (leftBottom) {
        if (x - i >= 0 && x - i < 8 && y - i >= 0 && y - i < 8) {
          if(board.getChessman(Position(x - i,y - i)) != nullptr){
            leftBottom = false;
          }
          moves.push_back(Move(Position(x, y), Position(x - i, y - i)));
        } else {
          leftBottom = false;
        }
      }
      if (rightBottom) {
        if (x - i >= 0 && x - i < 8 && y + i >= 0 && y + i < 8) {
          if(board.getChessman(Position(x - i,y + i)) != nullptr){
            rightBottom = false;
          }
          moves.push_back(Move(Position(x, y), Position(x - i, y + i)));
        } else {
          rightBottom = false;
        }
      }
      i++;
    }
  }
  return moves;
}
