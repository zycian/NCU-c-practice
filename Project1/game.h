#pragma once
#define ROW 9
#define COL 9

#define easy_count 10

#define ROWS ROW+2
#define COLS COL+2
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Initboard(char board[ROWS][COLS], int rows, int cols, char set);
void Displayboard(char show[ROWS][COLS], int rows, int cols);
void setmine(char board[ROWS][COLS], int rows, int cols);
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);