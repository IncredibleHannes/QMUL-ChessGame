#include "Bishop.h"
#include "Board.h"

#include <iostream>

Bishop::Bishop(Chessman::Colour colour, Position position)
  : Chessman(colour, position) {
  this->type = Chessman::Bishop;
}

std::list<Move> Bishop::getPossibleMoves(const Board &board) const {
  std::list<Move> moves;
  if (!isCaptured()) {
    int x = this->getCurrentPosition().getX();
    int y = this->getCurrentPosition().getY();
    bool leftTop = true;
    bool rightTop = true;
    bool leftBottom = true;
    bool rightBottom = true;
    int i = 1;

    while (leftTop || rightTop || leftBottom || rightBottom) {
      if (leftTop) {
        Position p = Position(x + i, y - i);
        if (p.isValid()) {
          if (board.getChessman(p) != nullptr) {
            leftTop = false;
            if (board.getChessman(p)->getColour() != this->colour)
            { moves.push_back(Move(Position(x, y), p)); }
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
          if (board.getChessman(p) != nullptr) {
            rightTop = false;
            if (board.getChessman(p)->getColour() != this->colour)
            { moves.push_back(Move(Position(x, y), p)); }
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
          if (board.getChessman(p) != nullptr) {
            leftBottom = false;
            if (board.getChessman(p)->getColour() != this->colour)
            { moves.push_back(Move(Position(x, y), p)); }
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
          if (board.getChessman(p) != nullptr) {
            rightBottom = false;
            if (board.getChessman(p)->getColour() != this->colour)
            { moves.push_back(Move(Position(x, y), p)); }
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
