#include"contact.h"
void menu() {
	printf("*****************************************************\n");
	printf("******* 1.���     2,ɾ��    3.�޸� *****************\n");
	printf("******* 4.����     5.����    6.��ӡ *****************\n");
	printf("****************** 0.�˳� ***************************\n");
	printf("*****************************************************\n");

}
//ѡ��ö�� ���������
enum option
{
	EXIT,
	ADD,
	DEL,
	MODIFI,
	SEARCH,
	SORT,
	PRINT
};

int main() {
	//��ʼ��ͨѶ¼
	contact cont;
	Info(&cont);
	int input = 0;
	do
	{
		menu();
		printf("������>\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case EXIT:
			SaveDete(&cont);//��������
			DestroyContact(&cont);//�˳����ͷŶ�̬�ռ�
			break;
		case ADD:
			AddContact(&cont);//�����Ա
			break;
		case DEL:
			DelContact(&cont);//ɾ������
			break;
		case MODIFI:
			ModifiContact(&cont);//�޸�
			break;
		case SEARCH:
			SearchContact(&cont);//����������Ա
			break;
		case SORT:
			break;
		case PRINT:
			PrintContact(&cont); //��ӡͨѶ¼
			break;
		default:
			break;
		}

	} while (input);

	return 0;
}