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

    while (top || right || bottom || left || leftTop || rightTop || leftBottom || rightBottom) {
      if (top) {
        Position p = Position(x + i, y);
        if (p.isValid()) {
          if(board.getChessman(p) != nullptr){
            top = false;
            if (board.getChessman(p)->getColour() != this->colour)
              moves.push_back(Move(Position(x, y), p));
          } else {
            moves.push_back(Move(Position(x, y), p));
          }
        } else {
          top = false;
        }
      }
      if (right) {
        Position p = Position(x, y + i);
        if (p.isValid()) {
          if(board.getChessman(p) != nullptr){
            right = false;
            if (board.getChessman(p)->getColour() != this->colour)
              moves.push_back(Move(Position(x, y), p));
          } else {
            moves.push_back(Move(Position(x, y), p));
          }
        } else {
          right = false;
        }
      }
      if (bottom) {
        Position p = Position(x - i, y);
        if (p.isValid()) {
          if(board.getChessman(p) != nullptr){
            bottom = false;
            if (board.getChessman(p)->getColour() != this->colour)
              moves.push_back(Move(Position(x, y), p));
          } else {
            moves.push_back(Move(Position(x, y), p));
          }
        } else {
          bottom = false;
        }
      }
      if (left) {
        Position p = Position(x, y - i);
        if (p.isValid()) {
          if(board.getChessman(p) != nullptr){
            left = false;
            if (board.getChessman(p)->getColour() != this->colour)
              moves.push_back(Move(Position(x, y), p));
          } else {
            moves.push_back(Move(Position(x, y), p));
          }
        } else {
          left = false;
        }
      }
      if (leftTop) {
        Position p = Position(x + i, y - i);
        if (p.isValid()) {
          if(board.getChessman(p) != nullptr){
            leftTop = false;
            if (board.getChessman(p)->getColour() != this->colour)
              moves.push_back(Move(Position(x, y), p));
          } else {
            moves.push_back(Move(Position(x, y), p));
          }
        } else {
          leftTop = false;
        }
      }
      if (rightTop) {
        Position p = Position(x + i, y + i);
        if (p.isValid()) {
          if(board.getChessman(p) != nullptr){
            rightTop = false;
            if (board.getChessman(p)->getColour() != this->colour)
              moves.push_back(Move(Position(x, y), p));
          } else {
            moves.push_back(Move(Position(x, y), p));
          }
        } else {
          rightTop = false;
        }
      }
      if (leftBottom) {
        Position p = Position(x - i, y - i);
        if (p.isValid()) {
          if(board.getChessman(p) != nullptr){
            leftBottom = false;
            if (board.getChessman(p)->getColour() != this->colour)
              moves.push_back(Move(Position(x, y), p));
          } else {
            moves.push_back(Move(Position(x, y), p));
          }
        } else {
          leftBottom = false;
        }
      }
      if (rightBottom) {
        Position p = Position(x - i, y + i);
        if (p.isValid()) {
          if(board.getChessman(p) != nullptr){
            rightBottom = false;
            if (board.getChessman(p)->getColour() != this->colour)
              moves.push_back(Move(Position(x, y), p));
          } else {
            moves.push_back(Move(Position(x, y), p));
          }
        } else {
          rightBottom = false;
        }
      }
      i++;
    }
  }
  return moves;
}
