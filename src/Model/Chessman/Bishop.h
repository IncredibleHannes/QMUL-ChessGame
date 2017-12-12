/**
    <h1>Bishop</h1>
    <h3>Bishop.h</h3><br>
    This class represents a bishop at the chess game. The bishop is a StraightLineMover,
    and therefore subclass of it.

    @author Johannes Hartmann
    @version 1.0 2017-12-12
*/
#ifndef BISHOP_H
#define BISHOP_H

#include "StraightLineMover.h"

class Bishop : public StraightLineMover {
public:
  /**
   * Constructor to create the chessman
   * @param colour   of the chessman
   * @param position of the chessman
   */
  Bishop(Chessman::Colour colour, Position position);
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
