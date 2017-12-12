/**
    <h1>Board</h1>
    <h3>Board.h</h3><br>
    This class is representing the chessboard. This class stores all figures. It
    is responsible for applying and undoing moves, and holds the game logic
    check and checkmate as well as for promotion and casteling moves


    @author Johannes Hartmann
    @version 1.0 2017-12-12
*/

#ifndef BOARD_H
#define BOARD_H

#include <list>
#include <iostream>

#include "Chessman.h"


class Board {
public:
  /**
   * Default constructor initialises the board with the starting postions of each
   * chessman.
   */
  Board();
  /**
   * Creates a initial board and applyes a list of moves to this board
   * @param moves A list of moves to be applyed to the board
   */
  Board(std::list<Move*> moves);
  /**
   * Copy constructor. Makes copies of each chessman of the board, as well as
   * copies of each previousMoves
   * @param b The board that will be copied.
   */
  Board(const Board &b);

  /**
   * Destructor deletes each chesman of the board and each previous moves, as well
   * as the chasman array itself.
   */
  ~Board();


  /**
   * Returns all possible moves for a given colour of the board. Internaly this methode
   * calls the virtual getPossobleMoves methode of each chesman, whitch holds the
   * individual game logic of each chesman
   * @param  colour The colour for for witch this methode will be applied
   * @return        All possible moves for a given colour
   */
  std::list<Move> getAllPossibleMoves(Chessman::Colour colour) const;
  /**
   * Returns all previous moves in a list of move pointer
   */
  std::list<Move*> getPreviousMoves() const;
  /**
   * Returns the pointer of a chesman at a given position. Is nullptr if there is
   * no chessman at the board
   */
  Chessman *getChessman(Position) const;
  /**
   * This methode applys a move to the chessboard.  To do so it checks if the move
   * is valid by looking the move in all possible moves up. This methode is also
   * responsible to check if a move is a casteling. If so the movetype of the given
   * move will be changed. It also checks if the player is still in check after the
   * move. After a succesful move the current colour of the board will be
   * changed.
   *
   * @param  move The move whitch will be applyed
   * @return      Returns true if the application of the move was succesful
   */
  bool applyMove(Move *move);
  /**
   * Promotes the figure at the target of a given move to the given new figure type.
   * The responsibility to check if a move is a promotion is up to the controller.
   * The old figure will be stored in the captured chessman list to enable undo.
   * @param move The actual move for the promotion
   * @param type The figure type to whitch the figure will be promoted
   */
  void applyPromotion(Move *move, Chessman::FigureType type);
  /**
   * Undoes the last move. It is also responcible to detect casteling and promotions.
   * The last move will be deleted by this methode
   */
  void undoLastMove();
  /**
   * Checks if its check by checking if one possible move can capture the king.
   * @return True if the current player is in check
   */
  bool isCheck() const;
  /**
   * checks if its checkmate by applying each possible move to a copyed board
   * and check if its still check after the move
   * @return True if the current player is in checkmate
   */
  bool isCheckmate() const;
  /**
   * Checks if the game is a draw. The following draws are supported:
   *    - if there is no possible move for the current player
   * @return True if the game is a draw
   */
  bool isDraw() const;
  /**
   * For a given move this function looks up if this move is a promotion
   * @param  move The move that is involved in this checking
   * @return      True if its a promotion
   */
  bool isPromotion(Move *move) const;

private:
  Chessman ** *board;
  Chessman::Colour currentColour;

  /**
   * Creates a new board array and initialise this board with the starting
   * position of each chessman.
   * @return A pointer to the fresh initialised chessoard
   */
  Chessman ** *createStartBoard();
  /**
   * Doeas the actual move action to avoid code redundancy
   * @param move The move that will be applyed
   */
  void move(Move *move);
  /**
   * changes the current colour of the board.
   */
  void changeCurrentColour();

  std::list<Chessman *> capturedChessmen;
  std::list<Move *> previousMoves;

};

#endif
