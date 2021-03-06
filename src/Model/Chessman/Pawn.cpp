#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(Chessman::Colour colour, Position position)
  : Chessman(colour, position) {
  this->type = Chessman::Pawn;
}

Chessman* Pawn::clone() const {
  return new Pawn(*this);
}

std::list<Move> Pawn::getPossibleMoves(const Board &board) const {
  std::list<Move> moves;
  if (!isCaptured()) {
    int x = this->position.getX();
    int y = this->position.getY();
    if (this->colour == Chessman::Colour::White) {
      if (board.getChessman(Position(x + 1, y)) == nullptr)
      { moves.push_back(Move(Position(x, y), Position(x + 1, y))); }
      //can move 2 fields!
      if (x == 1) {
        if (board.getChessman(Position(x + 1, y)) == nullptr &&
            board.getChessman(Position(x + 2, y)) == nullptr) {
          moves.push_back(Move(Position(x, y), Position(x + 2, y)));
        }
      }
      if(0 <= y - 1 && board.getChessman(Position(x + 1, y - 1)) != nullptr) {
        moves.push_back(Move(Position(x, y), Position(x + 1, y - 1)));
      }
      if(y + 1 < 8 && board.getChessman(Position(x + 1, y + 1)) != nullptr) {
        moves.push_back(Move(Position(x, y), Position(x + 1, y + 1)));
      }
    } else {
      if (board.getChessman(Position(x - 1, y)) == nullptr) {
        moves.push_back(Move(Position(x, y), Position(x - 1, y)));
      }
      //can move 2 fields!
      if (x == 6) {
        if (board.getChessman(Position(x - 1, y)) == nullptr &&
            board.getChessman(Position(x - 2, y)) == nullptr)
        { moves.push_back(Move(Position(x, y), Position(x - 2, y))); }
      }
      if(0 <= y - 1 && board.getChessman(Position(x - 1, y - 1)) != nullptr) {
        moves.push_back(Move(Position(x, y), Position(x - 1, y - 1)));
      }
      if(y + 1 < 8 && board.getChessman(Position(x - 1, y + 1)) != nullptr) {
        moves.push_back(Move(Position(x, y), Position(x - 1, y + 1)));
      }
    }
  }
  return moves;
}
