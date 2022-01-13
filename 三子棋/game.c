#include "game.h"

//初始化棋盘函数
void initialize(char board[ROW][COL], int row, int col) {
	int i ;//行数循环
	int j ;//列数循环
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印函数
void dispalyboard(char board[ROW][COL], int row, int col) {
	int i;//行数循环
	int j;//列数循环
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);//打印数据
			if (j < col - 1)
				printf("|");//打印分割数据的竖线
		}
		printf("\n");//换行至分割行

		if (i < row - 1) {
			j = 0;
			for ( j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
			
	}
}


//玩家下棋
void palyerMove(char board[ROW][COL], int row, int col) {
	int x, y;
	printf("玩家下>\n");
	while (1)//判断坐标是否合法
	{
		scanf("%d%d", &y, &x);
		//判断是否
		if (x >= 1 && x <= col && y >= 1 && y <= row) {
			// //判断坐标是否被占用
			if (board[y - 1][x - 1] == ' ') {
				board[y - 1][x - 1] = '*';
				break;//合法 跳出
			}
			else {

				printf("你输入的坐标被占用，请重新输入！\n");// 坐标不合法继续循环
			}
		}
		else
		{
			printf("你输入的坐标超出范围，请重新输入！\n");//超出范围继续循环
		}
		
	}
}

//电脑下棋
void computerMove(char board[ROW][COL], int row, int col) {
	printf("电脑下>\n");
	while (1)
	{
		int x = rand() % col;//使数值小于所要求的值
		int y = rand() % row;
		if (board[y][x]==' ')
		{
			board[y][x] = '#';
			break;
		}
	}
}

//判断输赢
char isWin(char board[ROW][COL], int row, int col) {
	int i, j;
	for ( i = 0; i < row; i++)//判断行是否相同
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
			return board[i][0];
	}
	for ( j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] != ' ')
			return board[0][j];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
	{
		return board[0][0];
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')
	{
		return board[0][2];
	}
	return 'c';
}

//判断是否平局
char isDogfall(char board[ROW][COL], int row, int col) {
	int i, j;
	for ( i = 0; i < row ; i++)
	{
		for (j = 0; j < col; j++) {
			if ( board[i][j] == ' ')
			{
				return 'c';

			}
		}
	}
	return 'p';
}