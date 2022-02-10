#include"contact.h"
void menu() {
	printf("*****************************************************\n");
	printf("******* 1.添加     2,删除    3.修改 *****************\n");
	printf("******* 4.查找     5.排序    6.打印 *****************\n");
	printf("****************** 0.退出 ***************************\n");
	printf("*****************************************************\n");

}
//选择枚举 后面个逗号
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
	//初始化通讯录
	contact cont;
	Info(&cont);
	int input = 0;
	do
	{
		menu();
		printf("请输入>\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case EXIT:
			SaveDete(&cont);//保存数据
			DestroyContact(&cont);//退出并释放动态空间
			break;
		case ADD:
			AddContact(&cont);//添加人员
			break;
		case DEL:
			DelContact(&cont);//删除函数
			break;
		case MODIFI:
			ModifiContact(&cont);//修改
			break;
		case SEARCH:
			SearchContact(&cont);//搜索单个人员
			break;
		case SORT:
			break;
		case PRINT:
			PrintContact(&cont); //打印通讯录
			break;
		default:
			break;
		}

	} while (input);

	return 0;
}