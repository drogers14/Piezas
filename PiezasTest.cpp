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

  obj.dropPiece(0); //does this run?
  obj.dropPiece(0);
  obj.dropPiece(0);

  Piece actual1 = obj.gameState();
  EXPECT_EQ(actual1, Invalid);
  obj.dropPiece(1);
  obj.dropPiece(1);
  obj.dropPiece(1);

  Piece actual2 = obj.gameState();
  EXPECT_EQ(actual2, Invalid);
  obj.dropPiece(2);
  obj.dropPiece(2);
  obj.dropPiece(2);

  Piece actual3 = obj.gameState();
  EXPECT_EQ(actual3, Invalid);
  obj.dropPiece(3);
  obj.dropPiece(3);
  obj.dropPiece(3);


  Piece tie = obj.gameState();
  EXPECT_EQ(tie, Blank);

}

TEST(PiezasTest, xWin)
{
  Piezas obj;

  obj.dropPiece(0);
  obj.dropPiece(0);
  obj.dropPiece(1);
  obj.dropPiece(0);
  obj.dropPiece(2);
  obj.dropPiece(1);

  obj.dropPiece(3);
  obj.dropPiece(1);
  obj.dropPiece(2);
  obj.dropPiece(3);
  obj.dropPiece(2);
  obj.dropPiece(3);

  Piece xWin = obj.gameState();
  EXPECT_EQ(xWin, X);
}


TEST(PiezasTest, oWin)
{
  Piezas obj;

  obj.dropPiece(0);//x
  obj.dropPiece(0);
  obj.dropPiece(1);
  obj.dropPiece(1);
  obj.dropPiece(0);
  obj.dropPiece(2);
  obj.dropPiece(1);
  obj.dropPiece(2);
  obj.dropPiece(3);//x
  obj.dropPiece(3);//o
  obj.dropPiece(2);
  obj.dropPiece(3);


  Piece oWin = obj.gameState();
  EXPECT_EQ(oWin, O);
}


TEST(PiezasTest, xwin)
{
  Piezas obj;

  obj.dropPiece(0);//x
  obj.dropPiece(3);//o
  obj.dropPiece(1);//x
  obj.dropPiece(2);//o
  obj.dropPiece(0);//x
  obj.dropPiece(1);//o
  obj.dropPiece(0);//x
  obj.dropPiece(2);//o
  obj.dropPiece(3);//x
  obj.dropPiece(1);//o
  obj.dropPiece(2);//x
  Piece test =  obj.dropPiece(3);//o


  EXPECT_EQ(test, Blank);

  Piece xWin = obj.gameState();
  EXPECT_EQ(xWin, X);
}
