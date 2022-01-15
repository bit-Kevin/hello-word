#include "game.h"

void initialize(char board[ROWS][COLS], int rows, int cols, char set)//初始化函数 initialize：初始化棋盘
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++) {
			board[i][j] = set;
		}
	}
}
void dispalyboard(char board[ROWS][COLS], int row, int col)//打印棋盘
{
	int i, j;
	printf("----------------------扫雷游戏-----------------------\n");
	for ( j = 0; j <=col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------------------扫雷游戏-----------------------\n");

}
void setMine(char mine[ROWS][COLS], int row, int col)//布置雷
{
	int count = MINES;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y]=='0')
		{
			mine[x][y] = '1';
			count--;
		}

	}
}
static int find_mine_count( char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
		mine[x][y - 1] + mine[x][y + 1] +
		mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}
//打印全部雷盘
void dispalyAll(char mine[ROWS][COLS], int row, int col) {
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++) {
			printf("%C ", mine[i][j]);
		}
		printf("\n");
	}
}
void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//排雷
{
	int win = ROW * COL - MINES;
	while (win)
	{
		int x, y,j,z;
		char LinShi;
		printf("请输入排查位置>\n");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("恭喜你你被炸死了\n");
				dispalyboard(mine, ROW, COL);
				break;
			}
			else
			{
				int count= find_mine_count(mine,x,y);
				LinShi = count+'0';
				if ( show[x][y]!= LinShi)
				{
					show[x][y] = LinShi;
					dispalyboard(show, ROW, COL);
					win--;
				}
				else
				{
					printf("该位置已被排过，请重新输入\n");
				}
				
				printf("\n");
				
			}
		}
		else
		{
			printf("你输入的坐标不合法，请重试\n");
		}

	}
	if (win == 0)
	{
		printf("你赢了!\n");
		dispalyboard(mine, ROW, COL);//打印雷盘
	}
}
