#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10
#define MEDIUM_COUNT 20
#define HARD_COUNT 30

void Initboard(char board[ROWS][COLS], int rows, int cols, char set);
void Displayboard(char show[ROWS][COLS], int rows, int cols);
void setmine(char board[ROWS][COLS], int rows, int cols, int mine_count);
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int mine_count);