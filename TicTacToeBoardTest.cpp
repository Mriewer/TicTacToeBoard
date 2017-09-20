/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, willToggle)
{
	TicTacToeBoard test;
	Piece asserted = O;
	Piece toggledTo = test.toggleTurn();
	EXPECT_TRUE(toggledTo == asserted);
}

TEST(TicTacToeBoardTest, willToggle2)
{
	TicTacToeBoard test;
	Piece asserted = O;
	Piece toggledTo = test.placePiece(0,0);
	toggledTo = test.placePiece(0,1);
	EXPECT_TRUE(toggledTo == asserted);
}

TEST(TicTacToeBoardTest, canPlace1)
{
	TicTacToeBoard test;
	Piece placed = test.placePiece(0,0);
	EXPECT_TRUE(placed == test.getPiece(0,0));
}

TEST(TicTacToeBoardTest, cannotPlaceColumn)
{
	TicTacToeBoard test;
	Piece asserted = Invalid;
	Piece placed = test.placePiece(0,3);
	EXPECT_TRUE(placed == asserted);
}

TEST(TicTacToeBoardTest, cannotPlaceRow)
{
	TicTacToeBoard test;
	Piece asserted = Invalid;
	Piece placed = test.placePiece(3,0);
	EXPECT_TRUE(placed == asserted);
}	

TEST(TicTacToeBoardTest, cannotPlaceNegativeColumn)
{	
	TicTacToeBoard test;
	Piece asserted = Invalid;
	Piece placed = test.placePiece(0, -1);
	EXPECT_TRUE(placed == asserted);
}

TEST(TicTacToeBoardTest, cannotPlaceNegativeRow)
{	
	TicTacToeBoard test;
	Piece asserted = Invalid;
	Piece placed = test.placePiece(-1, 0);
	EXPECT_TRUE(placed == asserted);
}

// This test will fail due to the board not being filled even though X has won My 'bug'
TEST(TicTacToeBoardTest, seeWin)
{
	TicTacToeBoard test;
	Piece asserted = X;
	test.placePiece(0, 0); //place X
	test.placePiece(0, 1);
	test.placePiece(1, 0); //place X
	test.placePiece(2, 2);
	test.placePiece(2, 0); //place X
	EXPECT_TRUE(test.getWinner() == asserted);
}

/**
 * This tests for the fowards diagonal 0,0 to 2,2
**/
TEST(TicTacToeBoardTest, seeWin2)
{
	TicTacToeBoard test;
	Piece asserted = Blank;

	test.placePiece(0, 0); //X
	test.placePiece(0, 1); //O
	test.placePiece(0, 2); //X
	
	test.placePiece(1, 1); //O
	test.placePiece(1, 0); //X
	test.placePiece(1, 2); //O

	test.placePiece(2, 1); //X
	test.placePiece(2, 0); //O
	test.placePiece(2, 2); //X
	EXPECT_TRUE(test.getWinner() == asserted);
}

/**
 * This tests for the backwards diagonal 0,2 to 2,0
**/
TEST(TicTacToeBoardTest, seeWin3)
{
	TicTacToeBoard test;
	Piece asserted = O;

	test.placePiece(0, 0); //X
	test.placePiece(0, 2); //O
	test.placePiece(0, 1); //X
	
	test.placePiece(1, 1); //O
	test.placePiece(1, 0); //X
	test.placePiece(1, 2); //O

	test.placePiece(2, 1); //X
	test.placePiece(2, 0); //O
	test.placePiece(2, 2); //X
	EXPECT_TRUE(test.getWinner() == asserted);
}

/**
 * This tests for a straight up+down win
**/
TEST(TicTacToeBoardTest, seeWin4)
{
	TicTacToeBoard test;
	Piece asserted = Invalid;
	
	
	EXPECT_TRUE(test.getWinner() == asserted);
}
