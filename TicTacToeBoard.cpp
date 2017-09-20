#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  Piece tempTurn;
  if(turn == X)
  {
    tempTurn = O;
  }
  else
    tempTurn = X;
  return tempTurn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if (getWinner() != Invalid)
    return turn;
  if(getPiece(row, column) != Blank)
    return getPiece(row, column);  
  else 
  {
    board[row][column] = turn;
    turn = toggleTurn();
  }
  return board[row][column];
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(row > 2 || column > 2 || row < 0 || column < 0)
    return Invalid;
  else if(board[row][column] != Blank)
    return board[row][column];
  return Blank;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  Piece place1, place2, place3;
  for(int x=0; x<BOARDSIZE; x++) // checks for rows and columns for wins
  {
    place1 = getPiece(x, 0);
    place2 = getPiece(x, 1);
    place3 = getPiece(x, 2);
    if(place1 == place2 && place2 == place3) // checks row wins
      return place1;
    place1 = getPiece(0, x);
    place2 = getPiece(1, x);
    place3 = getPiece(2, x);
    if(place1 == place2 && place2 == place3) // checks column wins
      return place1;
  }
  place1 = getPiece(1, 1);
  place2 = getPiece(0, 0);
  place3 = getPiece(2, 2);
  if(place1 == place2 && place2 == place3) // checks 0,0 to 2,2 diagonal win
      return place1;
  place2 = getPiece(0, 2);
  place3 = getPiece(2, 0);
  if(place1 == place2 && place2 == place3) // checks 0,2 to 2,0 diagonal win
      return place1;
  for(int i=0; i<BOARDSIZE; i++)
  {
    for(int j=0; j<BOARDSIZE; j++)
    {
      if(getPiece(i, j) == Blank)
        return Invalid;
    }
  }
  return Blank;
}
