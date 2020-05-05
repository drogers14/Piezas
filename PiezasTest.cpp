/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){
    Piezas();
    } //constructor runs before each test
		virtual ~PiezasTest(){
      //reset();
    } //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, dropPieceOutOfBounds)
{
  Piezas obj;
  Piece actual = obj.dropPiece(5);
  EXPECT_EQ(actual,  '?');

  Piece actual1 = obj.dropPiece(0);
  EXPECT_EQ(actual1, 'O');

  Piece actual2 = obj.dropPiece(0);
  EXPECT_EQ(actual2, X);

  Piece actual3 = obj.dropPiece(0);
  EXPECT_EQ(actual3, 'O');

  Piece actual4 = obj.dropPiece(0);
  EXPECT_EQ(actual4, '?');
}

TEST(PiezasTest, pieceAtTest)
{
Piezas obj;
Piece actual = obj.pieceAt(3, 4);
EXPECT_EQ(actual, Invalid);

Piece actual1 = obj.pieceAt(-1, 4);
EXPECT_EQ(actual1, Invalid);

Piece actual2 = obj.pieceAt(2, 4);
EXPECT_EQ(actual2, Invalid);

Piece actual3 = obj.pieceAt(2, -1);
EXPECT_EQ(actual3, Invalid);

Piece actual4 = obj.pieceAt(2, 2);
EXPECT_EQ(actual4, Blank);

Piece testing = obj.dropPiece(0);
Piece actual5 = obj.pieceAt(0, 0);
EXPECT_EQ(actual5, X);

}

TEST(PiezasTest, gameStateTest){
  Piezas obj;
  Piece actual = obj.gameState();
  EXPECT_EQ(actual, Invalid);

}
