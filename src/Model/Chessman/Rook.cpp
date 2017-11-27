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
      i++;
    }
  }
  return moves;
}
