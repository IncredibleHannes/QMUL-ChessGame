#include "King.h"
#include "Board.h"

King::King(Chessman::Colour colour, Position position)
  : Chessman(colour, position) {
  this->type = Chessman::King;
}

std::list<Move> King::getPossibleMoves(const Board &board) const {
  std::list<Move> moves;
  if (!isCaptured()) {
    int x = this->position.getX();
    int y = this->position.getY();
    for (int i = -1; i < 2; i++) {
      for (int j = -1; j < 2; j ++) {
        int targetx = x + i;
        int targety = y + j;
        if (targetx >= 0 && targetx < 8 && targety >= 0 && targety < 8) {
          if (board.getChessman(Position(targetx, targety)) != nullptr
              && board.getChessman(Position(targetx, targety))->getColour() != this->getColour()) {
            moves.push_back(Move(Position(x, y), Position(targetx, targety)));
          } else if (board.getChessman(Position(targetx, targety)) == nullptr) {
            moves.push_back(Move(Position(x, y), Position(targetx, targety)));
          }
        }
      }
    }
    // Castling
    if ((x == 0 || x == 7) && y == 4 && !this->wasMoved()) {
      if (board.getChessman(Position(x, y + 1)) == nullptr
          && board.getChessman(Position(x, y + 2)) == nullptr
          && board.getChessman(Position(x, y + 3))->getType() == Chessman::FigureType::Rook
          && board.getChessman(Position(x, y + 3))->getColour() == this->colour
          && !board.getChessman(Position(x, y + 3))->wasMoved()) {
        moves.push_back(Move(Position(x, y), Position(x, y + 2), true));

      }
      if (board.getChessman(Position(x, y - 1)) == nullptr
          && board.getChessman(Position(x, y - 2)) == nullptr
          && board.getChessman(Position(x, y - 3)) == nullptr
          && board.getChessman(Position(x, y - 4))->getType() == Chessman::FigureType::Rook
          && board.getChessman(Position(x, y - 4))->getColour() == this->colour
          && !board.getChessman(Position(x, y - 4))->wasMoved()) {
        moves.push_back(Move(Position(x, y), Position(x, y - 2), true));

      }

    }
  }
  return moves;
}
