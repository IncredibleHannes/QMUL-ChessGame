#include "Queen.h"
#include "Board.h"

Queen::Queen(Chessman::Colour colour, Position position)
  : Chessman(colour, position) {
    this->type = Chessman::Queen;
}

std::list<Move> Queen::getPossibleMoves(const Board& board) const {
  std::list<Move> moves;
  if(!isCaptured()) {
    int x = this->getCurrentPosition().getX();
    int y = this->getCurrentPosition().getY();
    bool top = true;
    bool right = true;
    bool bottom = true;
    bool left = true;
    bool leftTop = true;
    bool rightTop = true;
    bool leftBottom = true;
    bool rightBottom = true;
    int i = 1;

    while (top || right || bottom || left) {
      if (top) {
        if (x + i >= 0 && x + i < 8 && y >= 0 && y < 8) {
          if(board.getChessman(Position(x + i, y)) != nullptr){
            top = false;
          }
          moves.push_back(Move(Position(x, y), Position(x + i, y)));
        } else {
          top = false;
        }
      }
      if (right) {
        if (x >= 0 && x< 8 && y + i >= 0 && y + i < 8) {
          if(board.getChessman(Position(x, y + i)) != nullptr){
            right = false;
          }
          moves.push_back(Move(Position(x, y), Position(x, y + i)));
        } else {
          right = false;
        }
      }
      if (bottom) {
        if (x - i >= 0 && x - i < 8 && y >= 0 && y < 8) {
          if(board.getChessman(Position(x - i,y)) != nullptr){
            bottom = false;
          }
          moves.push_back(Move(Position(x, y), Position(x - i, y)));
        } else {
          bottom = false;
        }
      }
      if (left) {
        if (x >= 0 && x < 8 && y - i >= 0 && y - i < 8) {
          if(board.getChessman(Position(x, y - i)) != nullptr){
            left = false;
          }
          moves.push_back(Move(Position(x, y), Position(x, y - i)));
        } else {
          left = false;
        }
      }
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
