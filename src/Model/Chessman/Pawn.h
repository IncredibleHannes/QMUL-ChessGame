/**
    <h1>Pawn</h1>
    <h3>Pawn.h</h3><br>
    This class represents a pawn at the chess game.

    @author Johannes Hartmann
    @version 1.0 2017-12-12
*/
#ifndef PAWN_H
#define PAWN_H

#include "Chessman.h"

class Pawn : public Chessman {
public:
  /**
   * Constructor to create the chessman
   * @param colour   of the chessman
   * @param position of the chessman
   */
  Pawn(Chessman::Colour colour, Position position);
  /**
   * This function replaces the copyconstructor.
   * @return a pointer to the new cloend chessman
   */
  virtual Chessman* clone() const;
  /**
   * For a given board this function returns all possible moves for this figure.
   * @param  board to calculate the moves on
   * @return       list of all possible moves
   */
  virtual std::list<Move> getPossibleMoves(const Board &board) const;
};

#endif
