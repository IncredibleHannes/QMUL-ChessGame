#include "Rook.h"
#include "Board.h"

Rook::Rook(Chessman::Colour colour, Position position)
  : Chessman(colour, position) {
    this->type = Chessman::Rook;
}

std::list<Move> Rook::getPossibleMoves(const Board& board) const {
  std::list<Move> moves;
  if(!isCaptured()) {
    int x = this->getCurrentPosition().getX();
    int y = this->getCurrentPosition().getY();
    bool top = true;
    bool right = true;
    bool bottom = true;
    bool left = true;
    int i = 1;

    while (top || right || bottom || left) {
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
      i++;
    }
  }
  return moves;
}
