/** @file */
/**
    <h1>main</h1>
    <h3>Main.cpp</h3><br>
    This class is representing the controller. The whole game is implemented
    in the Model View Controller style. The main implements the whole game cicle.
    It has to create the board, check if its check/checkmate/draw and after this
    handle the user actions


    @author Johannes Hartmann
    @version 1.0 2017-12-12
*/
#include "Model/Board.h"
#include "View/View.h"
#include "Model/Move.h"
#include "Model/UserAction.h"

/**
 * Main function of the programm
 * @param  argc This application has no arguments
 * @param  argv This application has no arguments
 * @return      [description]
 */
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
