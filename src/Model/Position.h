#ifndef POSITION_H
#define POSITION_H

#include <iostream>

class Position {
public:
  // Constructors
  Position();
  Position(int x, int y);
  Position(std::string y);
  Position(const Position &other) = default;

  int getX() const;
  int getY() const;

  bool isValid() const;

  bool operator==(const Position &toCompare);

private:
  int x, y;
};

#endif
