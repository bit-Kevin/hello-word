#include <stdio.h>
void move(char pos1, char pos2) {
	printf(" %c -> %c \n" , pos1, pos2);
}
//只需要递不需要归
void hanoi(int sum, char pos1, char pos2, char pos3) {
	if (sum == 1)
	{
		//第一个柱子移到第三个柱子
		move(pos1, pos3);
	}
	else {
		//把起始（1号）柱子的上部分移动到第二个柱子暂存
		hanoi(sum - 1, pos1, pos3, pos2);
		//把起始（1号）柱子的下部分移动到目标柱子（3号）
		move(pos1, pos3);
		//把暂存柱子里剩下作为下次递的起始柱子，把这轮已经清空起始柱子作为下次递的暂存柱子，目标柱子不变
		hanoi(sum - 1, pos2, pos1, pos3);//下次递传参格式{起始柱子 ； 暂存柱子 ； 目标柱子}
	}
}

void main() {
	char pos1 = 'A';
	char pos2 = 'B';
	char pos3 = 'C';
	int sum = 5;
	hanoi(sum, pos1, pos2, pos3);
}