#include"contact.h"


//静态初始化函数
//void Info(contact* pc) {
//
//	pc->sz = 0;
//	memset(pc->dete, 0, sizeof(pc->dete));
//}
//动态地址初始化
void Info(contact* pc) {
	pc->dete = (conInfo *)malloc(INFODETE_SE * sizeof(conInfo));
	if (pc->dete==NULL)
	{
		perror("Info");//打印错误
		printf("动态地址申请错误");
		return;
	}
	pc->sz = 0;
	pc->MaxCapacity =INFODETE_SE;//最大容量
	LoadDete(pc);//加载保存的数据
}
void LoadDete(contact* pc)//加载之前保存的数据
{
	//打开文件
	FILE* pf;
	errno_t Err;
	Err = fopen_s(&pf, "dete.dat", "r");
	if (Err == 0)
	{
		printf("文件打开成功\n");
	}
	else
	{
		printf("失败\n");
	}
	//读入数据
	conInfo temp = {0};
	while (fread(&temp, sizeof(conInfo), 1, pf))
	{
		AddMax(pc);//检查地址扩容
		pc->dete[pc->sz] = temp;
		pc->sz++;
	}
	fclose(pf);
	pf = NULL;
}
//void AddContact(contact* pc)//静态添加人员
//{
//	if (pc->sz == MAX)
//	{
//		printf("该通讯录已满\n");
//		return;
//	}
//	printf("请输入姓名：");
//	scanf_s("%s", pc->dete[pc->sz].name,sizeof(pc->dete[pc->sz].name));
//	printf("请输入性别：");
//	scanf_s("%s", pc->dete[pc->sz].sex, sizeof(pc->dete[pc->sz].sex));
//	printf("请输入号码：");
//	scanf_s("%s", pc->dete[pc->sz].number, sizeof(pc->dete[pc->sz].number));
//	printf("请输入地址：");
//	scanf_s("%s", pc->dete[pc->sz].address, sizeof(pc->dete[pc->sz].address));
//	pc->sz++;
//	printf("添加成功\n");
//}

void SaveDete(contact* pc)//保存数据
{
	//打开文件
	FILE* pf;
	errno_t Err;
	Err =fopen_s(&pf, "dete.dat", "w");
	if (Err==0)
	{
		printf("文件打开成功\n");
	}
	else
	{
		perror("SaveDete");
		printf("失败\n");
		return;
	}
	
	//存入数据
	int i = 0;
	if (pf)
	{
		for (i = 0; i < pc->sz; i++)
		{
			fwrite(pc->dete + i, sizeof(conInfo), 1, pf);
		}
	}
	//关闭文件
	
	fclose(pf);
	pf = NULL;
}

void DestroyContact(contact* pc)//退出并释放动态空间
{
	free(pc->dete);
	pc->dete = NULL;
	pc->sz = 0;
	pc->MaxCapacity = 0;

}
void AddContact(contact* pc)//动态添加人员
{
	if (pc->sz == MAX)
	{
		printf("该通讯录已满\n");
		return;
	}
	AddMax(pc);//地址扩容
	
	printf("请输入姓名：");
	scanf_s("%s", pc->dete[pc->sz].name, sizeof(pc->dete[pc->sz].name));
	printf("请输入性别：");
	scanf_s("%s", pc->dete[pc->sz].sex, sizeof(pc->dete[pc->sz].sex));
	printf("请输入号码：");
	scanf_s("%s", pc->dete[pc->sz].number, sizeof(pc->dete[pc->sz].number));
	printf("请输入地址：");
	scanf_s("%s", pc->dete[pc->sz].address, sizeof(pc->dete[pc->sz].address));
	pc->sz++;
	printf("添加成功\n");
}

void AddMax(contact * pc)//地址扩容
{
	conInfo* temp = 0;
	if (pc->MaxCapacity == pc->sz)
	{
		temp = (conInfo*)realloc(pc->dete, (pc->MaxCapacity + DETEADD) * sizeof(conInfo));
		//申请更大的地址
		if (temp == NULL)
		{
			perror("Info");//打印错误
			printf("动态地址申请错误");
			return;
		}
		else
		{
			pc->dete = temp;
			pc->MaxCapacity += DETEADD;
			printf("扩容成功\n");
		}
	}
}
void DelContact(contact* pc)//删除函数
{
	if (pc->sz==0)
	{
		printf("通讯录为空！");
		return;
	}
	char name[MAX_NAME] = { 0 };
	int i = 0;
	printf("请输入要删除的人员的姓名:\n");
	scanf_s("%s", &name, sizeof(name));
	int temp = FindName(pc, name);//调用查找函数
	if (temp==-1)
	{
		printf("通讯录中没有此人！");
		return;
	}
	for ( i = temp; i < pc->sz -1; i++)//后面往前覆盖，最后一个不覆盖
	{
		pc->dete[i] = pc->dete[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");
	return;
}

void ModifiContact(contact* pc)//修改
{
	if (pc->sz == 0)
	{
		printf("通讯录为空！");
		return;
	}
	char name[MAX_ADDR];
	printf("请输入要修改人的名字：");
	scanf_s("%s", name, sizeof(name));
	int temp = FindName(pc, name);//调用查找函数
	if (temp == -1)
	{
		printf("通讯录中没有此人！");
		return;
	}
	printf("请输入性别：");
	scanf_s("%s", pc->dete[temp].sex, sizeof(pc->dete[temp].sex));
	printf("请输入号码：");
	scanf_s("%s", pc->dete[temp].number, sizeof(pc->dete[temp].number));
	printf("请输入地址：");
	scanf_s("%s", pc->dete[temp].address, sizeof(pc->dete[temp].address));
	printf("修改成功");
	
}
void SearchContact(contact* pc)//搜索大程序
{
	char name[MAX_ADDR];
	printf("请输入要查找的名字：");
	scanf_s("%s", name,sizeof(name));
	int temp = FindName(pc, name);//搜索小程序
	if (temp==-1)
	{
		printf("未找到此人\n");
		return;
	}
	printf("%-10s\t%-5s\t%-15s\t%-15s\n", "姓名", "性别", "号码", "地址");
	printf("%-10s\t%-5s\t%-15s\t%-15s\n", pc->dete[temp].name, pc->dete[temp].sex, pc->dete[temp].number, pc->dete[temp].address);
}
int FindName(contact* pc, char name[MAX_NAME])//搜索小程序
{
	int i;
	for ( i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->dete[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;//没找到
}


void PrintContact(contact* pc) //打印通讯录
{
	int i;
	printf("%-10s\t%-5s\t%-15s\t%-15s\n", "姓名", "性别", "号码", "地址");
	for ( i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5s\t%-15s\t%-15s\n", pc->dete[i].name, pc->dete[i].sex, pc->dete[i].number, pc->dete[i].address);
	}

}