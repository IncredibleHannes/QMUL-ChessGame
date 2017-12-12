/**
    <h1>StraightLineMover</h1>
    <h3>StraightLineMover.h</h3><br>
    This class is a subclass of a chessman, combines the rules
    of figures that can move in straight lines across the chessboard. Queen
    Bishop and Rook are straight line mover.
    The purpose of this class is to avoid code duplicates

    @author Johannes Hartmann
    @version 1.0 2017-12-12
*/
#ifndef STRAIGHTLINEMOVER_H
#define STRAIGHTLINEMOVER_H

#include "Chessman.h"
#include "Board.h"

class StraightLineMover : public Chessman {
public:
  /**
   * Constructor to create the StraightLineMover
   * @param colour   of the chessman
   * @param position of the chessman
   */
  StraightLineMover(Colour colour, Position position);
protected:
  /**
   * This methode computes all possible moves into a given direction. The direction will be
   * represented as offsets dx and dy. All moves will be stored in the given move list.
   * @param board     to calcualte the moves on
   * @param moves     list of moves to store the valid moves in
   * @param direction this flag will be set to false if there is no more possible
   *                  move in this direction
   * @param dx        X coordinate offset
   * @param dy        Y coordinate offset
   */
  void checkMove(const Board &board, std::list<Move> &moves, bool &direction, int dx, int dy) const;
};
#endif
