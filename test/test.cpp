#include "gtest/gtest.h"
#include "../src/move.h"

int team;
char board[9][9] = {{'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                 {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                 {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                 {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                 {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                 {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                 {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                 {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                 {' ', 'a', '6', 'c', 'd', 'e', 'f', 'g', 'h'}};

TEST(Pawn, WhitePawn_valid)
{
    int x1 = 6, x2 = 5;
    int y1 = 4, y2 = 4;
    team = 0;
    int result = MoveCheck(x1, x2, y1, y2);
    int expected = 1;
    EXPECT_EQ(expected, result);
}

TEST(Pawn, WhitePawn_invalid)
{
    int x1 = 6, x2 = 3;
    int y1 = 4, y2 = 4;
    team = 0;
    int result = MoveCheck(x1, x2, y1, y2);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

TEST(Rook, WhiteRook_valid)
{
    board[6][1]=' ';
    int x1 = 7, x2 = 5;
    int y1 = 1, y2 = 1;
    team = 0;
    int result = MoveCheck(x1, x2, y1, y2);
    int expected = 1;
    EXPECT_EQ(expected, result);
}

TEST(Rook, WhiteRook_invalid)
{
    board[6][1]='P';
    int x1 = 7, x2 = 5;
    int y1 = 1, y2 = 1;
    team = 0;
    int result = MoveCheck(x1, x2, y1, y2);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
