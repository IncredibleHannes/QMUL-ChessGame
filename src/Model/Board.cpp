#include "Board.h"

#include "Pawn.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Move.h"
#include "Position.h"


#include <cmath>
#include <iostream>

Board::Board()
  : currentColour(Chessman::Colour::White) {
  this->board = createStartBoard();
}

Board::Board(std::list<Move *> moves)
  : currentColour(Chessman::Colour::White) {
  this->board = createStartBoard();
  while (moves.size() != 0) {
    applyMove(moves.front());
    delete moves.front();
    moves.pop_front();
  }
}

Board::Board(const Board &b) {
  this->board = new Chessman**[8];

  for (int x = 0; x < 8; x++) {
    this->board[x] = new Chessman*[8];
    for (int y = 0; y < 8; y++) {
      if (b.getChessman(Position(x,y)) != nullptr) {
        this->board[x][y] = b.getChessman(Position(x,y))->clone();
      }
    }
  }
  for(Chessman* c : b.capturedChessmen) {
    this->capturedChessmen.push_back(c->clone());
  }
  for(Move* m : b.previousMoves) {
    this->previousMoves.push_back(new Move(*m));
  }
}

Board::~Board() {
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      if (this->board[x][y] != nullptr) {
        delete this->board[x][y];
      }
    }
  }
  for (int i = 0; i < 8; i++) {
    delete[] this->board[i];
  }
  delete[] this->board;
  for(Chessman* c : this->capturedChessmen) {
    delete c;
  }
  for(Move* m : this->previousMoves) {
    delete m;
  }
}

std::list<Move> Board::getAllPossibleMoves(Chessman::Colour colour) const {
  std::list<Move> list;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (this->board[i][j] != nullptr && this->board[i][j]->getColour() == colour) {
        list.splice(list.end(), this->board[i][j]->getPossibleMoves(*this));
      }
    }
  }
  return list;
}

std::list<Move*> Board::getPreviousMoves() const {
  return this->previousMoves;
}

Chessman*** Board::createStartBoard() {
  Chessman *** array2d = new Chessman **[8];

  for (int i = 0; i < 8; i++) {
    array2d[i] = new Chessman*[8];
    for (int j = 0; j < 8; j++) {
      array2d[i][j] = nullptr;
    }
  }
  for (int i = 0; i < 8; i++) {
    array2d[1][i] = new Pawn(Chessman::Colour::White, Position(1, i));
    array2d[6][i] = new Pawn(Chessman::Colour::Black, Position(6, i));
  }

  array2d[0][0] = new Rook(Chessman::Colour::White, Position(0, 0));
  array2d[0][7] = new Rook(Chessman::Colour::White, Position(0, 7));
  array2d[7][0] = new Rook(Chessman::Colour::Black, Position(7, 0));
  array2d[7][7] = new Rook(Chessman::Colour::Black, Position(7, 7));
  array2d[0][1] = new Knight(Chessman::Colour::White, Position(0, 1));
  array2d[0][6] = new Knight(Chessman::Colour::White, Position(0, 6));
  array2d[7][1] = new Knight(Chessman::Colour::Black, Position(7, 1));
  array2d[7][6] = new Knight(Chessman::Colour::Black, Position(7, 6));
  array2d[0][2] = new Bishop(Chessman::Colour::White, Position(0, 2));
  array2d[0][5] = new Bishop(Chessman::Colour::White, Position(0, 5));
  array2d[7][2] = new Bishop(Chessman::Colour::Black, Position(7, 2));
  array2d[7][5] = new Bishop(Chessman::Colour::Black, Position(7, 5));
  array2d[0][3] = new Queen(Chessman::Colour::White, Position(0, 3));
  array2d[0][4] = new King(Chessman::Colour::White, Position(0, 4));
  array2d[7][3] = new Queen(Chessman::Colour::Black, Position(7, 3));
  array2d[7][4] = new King(Chessman::Colour::Black, Position(7, 4));
  return array2d;
}

Chessman *Board::getChessman(Position position) const {
  return this->board[position.getX()][position.getY()];
}

bool Board::applyMove(Move *move) {
  Chessman *currentChessman = getChessman(move->getOrigin());
  bool isCheck = this->isCheck();

  if (currentChessman != nullptr
      && currentChessman->isMoveValid(*this, *move)
      && currentChessman->getColour() == currentColour) {
    Board::move(move);
    // check casteling
    Position *rookTarget = nullptr;
    Position *rookOrigin = nullptr;
    if (currentChessman->getType() == Chessman::FigureType::King
        && move->getOrigin().getY() - move->getTarget().getY() == 2) {
      rookTarget = new Position(move->getTarget().getX(), move->getTarget().getY() + 1);
      rookOrigin = new Position(move->getTarget().getX(), 0);
    }
    if (currentChessman->getType() == Chessman::FigureType::King
        && move->getOrigin().getY() - move->getTarget().getY() == -2) {
      rookTarget = new Position(move->getTarget().getX(), move->getTarget().getY() - 1);
      rookOrigin = new Position(move->getTarget().getX(), 7);
    }
    if (rookTarget != nullptr) {
      Move *m = new Move(*rookOrigin, *rookTarget);
      Board::move(m);
      previousMoves.back()->addType(Move::Casteling);
      delete m;
      delete rookOrigin;
      delete rookTarget;
    }


    //check if after the move the player is still in check
    if (isCheck && this->isCheck()) {
      changeCurrentColour();
      this->undoLastMove();
      return false;
    }

    changeCurrentColour();

    return true;
  }
  return false;
}

void Board::move(Move *move) {

  Position origin = move->getOrigin();
  Position target = move->getTarget();
  Chessman *currentChessman = this->board[origin.getX()][origin.getY()];
  this->board[origin.getX()][origin.getY()] = nullptr;

  Chessman *targetChessman = this->board[target.getX()][target.getY()];
  if (targetChessman != nullptr) {
    targetChessman->capture();
    move->setCaptureMove(targetChessman);
    capturedChessmen.push_back(targetChessman);
  }
  this->board[target.getX()][target.getY()] = currentChessman;
  currentChessman->setCurrentPosition(target);
  this->previousMoves.push_back(new Move(*move));
}

void Board::applyPromotion(Move *move, Chessman::FigureType type) {
    Chessman *currentChessman = getChessman(move->getTarget());
    move->addType(Move::Promotion);
    int x = move->getTarget().getX();
    int y = move->getTarget().getY();
    switch(type) {
      case Chessman::Queen :
        board[x][y] = new Queen(currentChessman->getColour(), Position(x,y));
        break;
      case Chessman::Rook :
        board[x][y] = new Rook(currentChessman->getColour(), Position(x,y));
        break;
      case Chessman::Bishop :
        board[x][y] = new Bishop(currentChessman->getColour(), Position(x,y));
        break;
      case Chessman::Knight :
        board[x][y] = new Knight(currentChessman->getColour(), Position(x,y));
        break;
      default:
        break;
    }
    Move *m = previousMoves.back();
    previousMoves.pop_back();
    delete m;
    previousMoves.push_back(new Move(*move));
    capturedChessmen.push_back(currentChessman);
    delete move;
}

void Board::undoLastMove() {
  if (previousMoves.size() == 0) {
    return;
  }
  Move *m = previousMoves.back();
  previousMoves.pop_back();

  Position origin = m->getOrigin();
  Position target = m->getTarget();
  Chessman *currentChessman = this->board[target.getX()][target.getY()];
  if (m->hasType(Move::Promotion)) {
    delete currentChessman;
    currentChessman = capturedChessmen.back();
    capturedChessmen.pop_back();
  }

  if (m->hasType(Move::Capture)) {
    this->board[target.getX()][target.getY()] = m->getCapturedChessman()->clone();
    this->board[target.getX()][target.getY()]->unsetCapture();
  } else {
    this->board[target.getX()][target.getY()] = nullptr;
  }
  this->board[origin.getX()][origin.getY()] = currentChessman;
  currentChessman->setCurrentPosition(origin);

  if (m->hasType(Move::Casteling)) {
    undoLastMove();
  }
  this->changeCurrentColour();
  delete m;
}

void Board::changeCurrentColour() {
  if (this->currentColour == Chessman::Colour::White) {
    this->currentColour = Chessman::Colour::Black;
  } else {
    this->currentColour = Chessman::Colour::White;
  }
}

bool Board::isCheck() const {
  std::list<Move> moves = getAllPossibleMoves(!this->currentColour);
  for (Move m : moves) {
    Chessman *target = board[m.getTarget().getX()][m.getTarget().getY()];
    if (target != nullptr
        && target->getType() == Chessman::FigureType::King
        && target->getColour() == this->currentColour) {
      return true;
    }
  }
  return false;
}

bool Board::isCheckmate() const {
  if (!this->isCheck()) {
    return false;
  }
  std::list<Move> moves = getAllPossibleMoves(this->currentColour);
  Board *b = new Board(*this);
  for (Move m : moves) {
    Move *m2 = new Move(m);
    if (b->applyMove(m2)) {
      delete b;
      delete m2;
      return false;
    }
    delete m2;
    b->undoLastMove();
  }
  return true;
}

bool Board::isDraw() const {
  if (!this->isCheck() && getAllPossibleMoves(!this->currentColour).size() == 0) {
    return true;
  }
  return false;
}

bool Board::isPromotion(Move *move) const {
  Chessman *currentChessman = getChessman(move->getTarget());
  if (currentChessman == nullptr) {
    return false;
  }
  if (currentChessman->getType() != Chessman::Pawn) {
    return false;
  }
  if (move->getTarget().getX() == 0 || move->getTarget().getX() == 7) {
    move->addType(Move::Promotion);
    return true;
  }
  return false;
}
