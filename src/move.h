#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

extern char board[9][9];
extern int team;

void move();
int MoveCheck(int x1, int x2, int y1, int y2);
int CheckFriend(int x2, int y2);

#endif
