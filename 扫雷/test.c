#include "game.h"

void menu() {
	printf("############################################\n");
	printf("################# 0  paly  #################\n");
	printf("################# 1  exit  #################\n");
	printf("############################################\n");
}
int main() {
	srand((unsigned int)time(NULL));
	char mine[ROWS][COLS];//�׵�����
	char show[ROWS][COLS];//չʾ����
	menu();
	initialize(mine, ROWS, COLS, '0');//��ʼ������ initialize����ʼ��������
	initialize(show, ROWS, COLS, '#');//��ʼ������ initialize����ʼ��չʾ����
	//dispalyboard(mine, ROW, COL);//��ӡ����
	dispalyboard(show, ROW, COL);//��ӡչʾ����
	setMine(mine, ROW, COL);//������
	findMine(mine,show, ROW, COL);//����



	
}