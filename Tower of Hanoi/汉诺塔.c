#include <stdio.h>
void move(char pos1, char pos2) {
	printf(" %c -> %c \n" , pos1, pos2);
}
//ֻ��Ҫ�ݲ���Ҫ��
void hanoi(int sum, char pos1, char pos2, char pos3) {
	if (sum == 1)
	{
		//��һ�������Ƶ�����������
		move(pos1, pos3);
	}
	else {
		//����ʼ��1�ţ����ӵ��ϲ����ƶ����ڶ��������ݴ�
		hanoi(sum - 1, pos1, pos3, pos2);
		//����ʼ��1�ţ����ӵ��²����ƶ���Ŀ�����ӣ�3�ţ�
		move(pos1, pos3);
		//���ݴ�������ʣ����Ϊ�´εݵ���ʼ���ӣ��������Ѿ������ʼ������Ϊ�´εݵ��ݴ����ӣ�Ŀ�����Ӳ���
		hanoi(sum - 1, pos2, pos1, pos3);//�´εݴ��θ�ʽ{��ʼ���� �� �ݴ����� �� Ŀ������}
	}
}

void main() {
	char pos1 = 'A';
	char pos2 = 'B';
	char pos3 = 'C';
	int sum = 5;
	hanoi(sum, pos1, pos2, pos3);
}