#include "game.h"

void menu() {
	printf("############################################\n");
	printf("################# 0  paly  #################\n");
	printf("################# 1  exit  #################\n");
	printf("############################################\n");
}
int main() {
	srand((unsigned int)time(NULL));
	char mine[ROWS][COLS];//雷的棋盘
	char show[ROWS][COLS];//展示棋盘
	menu();
	initialize(mine, ROWS, COLS, '0');//初始化函数 initialize：初始化雷棋盘
	initialize(show, ROWS, COLS, '#');//初始化函数 initialize：初始化展示棋盘
	//dispalyboard(mine, ROW, COL);//打印雷盘
	dispalyboard(show, ROW, COL);//打印展示棋盘
	setMine(mine, ROW, COL);//布置雷
	findMine(mine,show, ROW, COL);//排雷



	
}