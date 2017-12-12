/**
    <h1>Position</h1>
    <h3>Position.h</h3><br>
    This class is representing the a position on the chessboard. Is used inside the
    Move class.


    @author Johannes Hartmann
    @version 1.0 2017-12-12
*/

#ifndef POSITION_H
#define POSITION_H

#include <iostream>

class Position {
public:
  /**
   * Constructor initialses each value with -1
   */
  Position();
  /**
   * Constructor initialses each value with the given values. There is no
   * validity check for the given values
   * @param x Coordinate starting at 0
   * @param y Coordinate starting at 0
   */
  Position(int x, int y);
  /**
   * A given position string will be transforemd to the actual corresponding values.
   * There is no validity check for the given values
   * @param y Position String
   */
  Position(std::string y);
  /**
   * Copy constructor for a given Position. The default implementation is used
   * @param other Position to copy
   */
  Position(const Position &other) = default;

  /**
   * Getter for the X coordinate
   * @return Coordinate starting at 0
   */
  int getX() const;
  /**
   * Getter for the Y coordinate
   * @return Coordinate starting at 0
   */
  int getY() const;
  /**
   * Checks if the coordinates are in range [0..7]
   * @return True if position is valid
   */
  bool isValid() const;
  /**
   * Overloaded equals operator
   */
  bool operator==(const Position &toCompare);

private:
  int x, y;
};

#endif
