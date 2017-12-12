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
#include "Controller/Controller.h"

/**
 * Main function of the programm
 * @param  argc This application has no arguments
 * @param  argv This application has no arguments
 * @return      [description]
 */
int main(int argc, char const *argv[]) {
  Controller c = Controller();
  c.run();
  return 0;
}
