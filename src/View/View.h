/**
    <h1>View</h1>
    <h3>View.h</h3><br>
    This class is representing the view. The whole game is implemented
    in the Model View Controller style. It handles all user interaction
    and prints out every output. It is also responsible for the save and load
    actions. Therefore it handles file input and output.


    @author Johannes Hartmann
    @version 1.0 2017-12-12
*/
#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <fstream>
#include "Board.h"
#include "Chessman.h"
#include "UserAction.h"

class View {
public:
  /**
   * Prints a given chessboard to console
   * @param board the board to print out
   */
  void printBoard(Board const *board) const;
  /**
   * Asks the user to whitch figure he wants to promote it figure to
   * @return The promotion type the figure will be promoted to
   */
  Chessman::FigureType getPromotionType() const;
  /**
   * Asks the user for an input. The caller is responsible to delete the given
   * pointer
   * @return A pointer to a user action object.
   */
  UserAction *getUserAction() const;
  /**
   * prints the initial greeting
   */
  void printGreeting() const;
  /**
   * Prints a check situation
   */
  void printCheck() const;
  /**
   * Prints a checkmate situation
   */
  void printCheckmate() const;
  /**
   * Prints a draw situation
   */
  void printDraw() const;
  /**
   * Prints a invalid move situation
   */
  void printInvalidMove() const;
  /**
   * Prints a invalid user action situation
   */
  void printInvalidUserAction() const;
  /**
   * Prints the end message of the game
   */
  void printQuitMessage() const;

  /**
   * Saves a given list of moves to the file. The format will be just the
   * origin position followed by a space and then the target position followed
   * by a newline
   * @param moves List of move pointers starting at a initial board
   */
  void saveToFile(std::list<Move*> moves) const;
  /**
   * Returns al list of moves readed from the savefile
   */
  std::list<Move*> loadFromFile() const;

private:
  void printBoardLine() const;
  void printBottomBoardLine() const;
  void printTopBoardLine() const;
  void printBoardLabel() const;
  void printChessman(Chessman const *chessman) const;

};
#endif
