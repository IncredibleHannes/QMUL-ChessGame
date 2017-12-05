#include "Model/Board.h"
#include "View/View.h"
#include "Model/Move.h"
#include "Model/UserAction.h"

int main(int argc, char const *argv[]) {

  std::list<Move*> testMoves = {
    new Move(Position(1,5), Position(2,5)),
    new Move(Position(6,4), Position(4,4)),
    new Move(Position(1,6), Position(3,6)),
    new Move(Position(7,5), Position(6,4)),
    new Move(Position(0,6), Position(2,7)),
    new Move(Position(7,6), Position(5,7)),
    new Move(Position(2,5), Position(3,5)),
    new Move(Position(6,6), Position(4,6)),
    new Move(Position(3,5), Position(4,6)),
    new Move(Position(5,7), Position(3,6)),
    new Move(Position(4,6), Position(5,6)),
    new Move(Position(3,6), Position(1,7)),
    new Move(Position(5,6), Position(6,6)),
    new Move(Position(1,7), Position(0,5)),
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

    bool noMoveAction = true;
    while (noMoveAction) {
      UserAction *userAction = view.getUserAction();
      switch (userAction->getType()) {
        case UserAction::Save :
          std::cout << "UserAction Save" << std::endl;
          //TODO: implement
          delete userAction;
          break;
        case UserAction::Load :
          std::cout << "UserAction Load" << std::endl;
          //TODO: implement
          delete userAction;
          break;
        case UserAction::Undo :
          delete userAction;
          board.undoLastMove();
          noMoveAction = false;
          break;
        case UserAction::MoveAction :
          if(!board.applyMove(userAction->getMove())) {
            view.printInvalidMove();
            continue;
          }
          if (board.isPromotion(userAction->getMove())) {
            board.applyPromotion(userAction->getMove(), view.getPromotionType());
          }
          delete userAction;
          noMoveAction = false;
          break;
        case UserAction::Quit :
          view.printQuitMessage();
          delete userAction;
          return 0;
        default:
          view.printInvalidUserAction();
      }
    }
  }
  return 0;
}
