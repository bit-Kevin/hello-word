#pragma once
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 11
#define COLS 11
#define ROW 9
#define COL 9
#define MINES 10 //雷的数量

void initialize(char board[ROWS][COLS],int rows,int cols,char set);//初始化函数 initialize：初始化棋盘
void dispalyboard(char board[ROW][COL], int row,int col );//打印棋盘
void setMine(char mine[ROWS][COLS],int row,int col);//布置雷
void findMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);//排雷

