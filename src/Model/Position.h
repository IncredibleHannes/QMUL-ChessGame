#ifndef POSITION_H
#define POSITION_H

class Position {
public:
  // Constructors
  Position(int x, int y);
  Position(const Position& other) = default;

  int getX() const;
  int getY() const;

private:
  int x, y;
};

#endif
