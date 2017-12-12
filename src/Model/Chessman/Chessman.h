/**
    <h1>Chessman</h1>
    <h3>Chessman.h</h3><br>
    This abstract class representing a chessman. It contains all common functionality
    of a chessman. The virtual abstract methode getPossibleMoves() must be overided
    as well as the clone methode, witch is equivalent to a cpoy constructor.
    A chessman has a figure type and a colour. It also saves if it was moved before
    to enable the correct rules of casteling, a flag if it was captured and it's
    current position at the chessboard.

    @author Johannes Hartmann
    @version 1.0 2017-12-12
*/

#ifndef CHESSMAN_H
#define CHESSMAN_H

#include <list>

#include "Move.h"
#include "Position.h"

class Board;
class Move;

class Chessman {
public:
  enum FigureType { King, Queen, Pawn, Knight, Rook, Bishop };
  enum Colour : bool { Black, White };

  /**
   * The default construcor sets the colour and position of a chessman.
   * @param colour   of the chessman
   * @param position of the chessman
   */
  Chessman(Colour colour, Position position);
  /**
   * A virtual methode to generate a copy of the current chessman. Since chessman
   * is abstract, tis mehtode functionates as a copyconstructor.
   * @return Pointer to the new copied chessman.
   */
  virtual Chessman* clone() const = 0;
  /**
   * The default destructor for the chessman
   */
  virtual ~Chessman() = default;

  /**
   * Getter for the colour of the chessman
   * @return Colour of the chessman
   */
  Colour getColour() const;
  /**
   * Setter for the capture flag
   */
  void capture();
  /**
   * Getter for the capture flag
   * @return True if the chessman was captured
   */
  bool isCaptured() const;
  /**
   * Setter for the capture flag
   */
  void unsetCapture();
  /**
   * Checks if for a given board the given move is valid for the current chesman.
   * Internaly it calls the getPossibleMoves methode and checks if the move is
   * in the possible moves
   * @param  board to check validity on
   * @param  move  to check if its valid
   * @return       True if the move is valid
   */
  bool isMoveValid(const Board &board, const Move &move) const;
  /**
   * Getter for the figure Type
   * @return the type of the current figure
   */
  FigureType getType() const;
  /**
   * Getter for the current position of the chessman
   * @return the current position
   */
  Position getCurrentPosition() const;
  /**
   * Setter of the current position of the chessman
   * @param position to set to
   */
  void setCurrentPosition(Position position);
  /**
   * getter for the moved flag
   * @return True if the figure was moved previously
   */
  bool wasMoved() const;

  /**
   * This function holds the gamelogic of each chessman. Therefore it is abstract
   * and must be implemeted by each subclass. For a given board it calcualtes
   * all possible moves that this figure can do. If the user is still in check after
   * this move must be checked by the caller.
   * @param  board context on witch all possible moves will be calculated
   * @return       list of moves that this figure can do.
   */
  virtual std::list<Move> getPossibleMoves(const Board &board) const = 0;

protected:
  Colour colour;
  bool captured;
  bool moved;
  FigureType type;
  Position position;
};

Chessman::Colour operator!(Chessman::Colour colour);
#endif
