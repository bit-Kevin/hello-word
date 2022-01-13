#pragma once

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include<stdlib.h>



//符号定义
#define ROW 3
#define COL 3

//函数定义
void initialize(char board[ROW][COL], int row, int col);//初始化棋盘
void dispalyboard(char board[ROW][COL], int row, int col);//打印棋盘
void palyerMove(char board[ROW][COL], int row, int col);//玩家下棋
void computerMove(char board[ROW][COL], int row, int col);//电脑下棋
char isWin(char board[ROW][COL], int row, int col);//判断输赢
char isDogfall(char board[ROW][COL], int row, int col);//判断是否平局
