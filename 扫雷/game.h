#pragma once
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 11
#define COLS 11
#define ROW 9
#define COL 9
#define MINES 10 //�׵�����

void initialize(char board[ROWS][COLS],int rows,int cols,char set);//��ʼ������ initialize����ʼ������
void dispalyboard(char board[ROW][COL], int row,int col );//��ӡ����
void setMine(char mine[ROWS][COLS],int row,int col);//������
void findMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);//����

