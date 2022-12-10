#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define EASY 80
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

void Initboard(char board[ROWS][COLS], int rows, int cols, char set);

void Displayboard(char board[ROWS][COLS], int row, int col);

void Setmine(char mine[ROWS][COLS], int row, int col);

void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
