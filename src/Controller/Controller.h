/**
    <h1>Controller</h1>
    <h3>Controller.cpp</h3><br>
    This class is representing the controller. The whole game is implemented
    in the Model View Controller style. The run methode implements the whole game cicle.
    It has to create the board, check if its check/checkmate/draw and after this
    handle the user actions


    @author Johannes Hartmann
    @version 1.0 2017-12-12
*/
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Board.h"
#include "View.h"
#include "Move.h"
#include "UserAction.h"

class Controller {
public:
  /**
   * Starts the game and implements the whole game cicle
   */
  void run();
};
#endif
