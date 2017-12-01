#include "Model/Board.h"
#include "View/View.h"
#include "Model/Move.h"

int main(int argc, char const *argv[]) {

  std::list<Move*> testMoves = {
    new Move(Position(1,5), Position(2,5)),
    new Move(Position(6,4), Position(4,4)),
    new Move(Position(1,6), Position(3,6)),
    new Move(Position(7,5), Position(6,4)),
    new Move(Position(0,6), Position(2,7)),
    new Move(Position(7,6), Position(5,7)),
  };
  Board board = Board(testMoves);
  View view = View();

  view.printGreeting();


  while (true) {
    if (board.isCheck()) {
      view.printCheck();
      if (board.isCheckmate()) {
        view.printCheckmate();
        view.printBoard(&board);
        break;
      }
    }
    if (board.isDraw()) {
      view.printDraw();
      view.printBoard(&board);
      break;
    }
    view.printBoard(&board);
    Move *move = view.getMove();
    board.applyMove(*move);
  }
  return 0;
}
