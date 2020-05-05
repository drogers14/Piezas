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
  EXPECT_EQ(actual2, 'X');

/*  Piece actual3 = obj.dropPiece(0);
  EXPECT_EQ(actual3, 'O');

  Piece actual4 = obj.dropPiece(0);
  EXPECT_EQ(actual4, '?');
  */
}
