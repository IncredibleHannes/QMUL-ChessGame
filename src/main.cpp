#include "Model/Board.h"
#include "View/View.h"
#include "Model/Move.h"
#include "Model/UserAction.h"

int main(int argc, char const *argv[]) {

  Board *board = new Board();

  View view = View();

  view.printGreeting();

  while (true) {
    if (board->isCheck()) {
      view.printCheck();
      if (board->isCheckmate()) {
        view.printCheckmate();
        view.printBoard(board);
        break;
      }
    }
    if (board->isDraw()) {
      view.printDraw();
      view.printBoard(board);
      break;
    }
    view.printBoard(board);

    bool noInvalidAction = true;
    while (noInvalidAction) {
      UserAction *userAction = view.getUserAction();
      Move *move;
      switch (userAction->getType()) {
        case UserAction::Save :
          view.saveToFile(board->getPreviousMoves());
          noInvalidAction = false;
          break;
        case UserAction::Load :
          delete board;
          board = new Board(view.loadFromFile());
          noInvalidAction = false;
          break;
        case UserAction::Undo :
          board->undoLastMove();
          noInvalidAction = false;
          break;
        case UserAction::MoveAction :
          move = new Move(*userAction->getMove());
          if(!board->applyMove(move)) {
            view.printInvalidMove();
            delete move;
            delete userAction;
            continue;
          }
          if (board->isPromotion(move)) {
            board->applyPromotion(move, view.getPromotionType());
          }
          noInvalidAction = false;
          //delete move;
          break;
        case UserAction::Quit :
          view.printQuitMessage();
          delete board;
          delete userAction;
          return 0;
        default:
          view.printInvalidUserAction();
      }
      delete userAction;
    }
  }
  return 0;
}
