#include"contact.h"


//��̬��ʼ������
//void Info(contact* pc) {
//
//	pc->sz = 0;
//	memset(pc->dete, 0, sizeof(pc->dete));
//}
//��̬��ַ��ʼ��
void Info(contact* pc) {
	pc->dete = (conInfo *)malloc(INFODETE_SE * sizeof(conInfo));
	if (pc->dete==NULL)
	{
		perror("Info");//��ӡ����
		printf("��̬��ַ�������");
		return;
	}
	pc->sz = 0;
	pc->MaxCapacity =INFODETE_SE;//�������
	LoadDete(pc);//���ر��������
}
void LoadDete(contact* pc)//����֮ǰ���������
{
	//���ļ�
	FILE* pf;
	errno_t Err;
	Err = fopen_s(&pf, "dete.dat", "r");
	if (Err == 0)
	{
		printf("�ļ��򿪳ɹ�\n");
	}
	else
	{
		printf("ʧ��\n");
	}
	//��������
	conInfo temp = {0};
	while (fread(&temp, sizeof(conInfo), 1, pf))
	{
		AddMax(pc);//����ַ����
		pc->dete[pc->sz] = temp;
		pc->sz++;
	}
	fclose(pf);
	pf = NULL;
}
//void AddContact(contact* pc)//��̬�����Ա
//{
//	if (pc->sz == MAX)
//	{
//		printf("��ͨѶ¼����\n");
//		return;
//	}
//	printf("������������");
//	scanf_s("%s", pc->dete[pc->sz].name,sizeof(pc->dete[pc->sz].name));
//	printf("�������Ա�");
//	scanf_s("%s", pc->dete[pc->sz].sex, sizeof(pc->dete[pc->sz].sex));
//	printf("��������룺");
//	scanf_s("%s", pc->dete[pc->sz].number, sizeof(pc->dete[pc->sz].number));
//	printf("�������ַ��");
//	scanf_s("%s", pc->dete[pc->sz].address, sizeof(pc->dete[pc->sz].address));
//	pc->sz++;
//	printf("��ӳɹ�\n");
//}

void SaveDete(contact* pc)//��������
{
	//���ļ�
	FILE* pf;
	errno_t Err;
	Err =fopen_s(&pf, "dete.dat", "w");
	if (Err==0)
	{
		printf("�ļ��򿪳ɹ�\n");
	}
	else
	{
		perror("SaveDete");
		printf("ʧ��\n");
		return;
	}
	
	//��������
	int i = 0;
	if (pf)
	{
		for (i = 0; i < pc->sz; i++)
		{
			fwrite(pc->dete + i, sizeof(conInfo), 1, pf);
		}
	}
	//�ر��ļ�
	
	fclose(pf);
	pf = NULL;
}

void DestroyContact(contact* pc)//�˳����ͷŶ�̬�ռ�
{
	free(pc->dete);
	pc->dete = NULL;
	pc->sz = 0;
	pc->MaxCapacity = 0;

}
void AddContact(contact* pc)//��̬�����Ա
{
	if (pc->sz == MAX)
	{
		printf("��ͨѶ¼����\n");
		return;
	}
	AddMax(pc);//��ַ����
	
	printf("������������");
	scanf_s("%s", pc->dete[pc->sz].name, sizeof(pc->dete[pc->sz].name));
	printf("�������Ա�");
	scanf_s("%s", pc->dete[pc->sz].sex, sizeof(pc->dete[pc->sz].sex));
	printf("��������룺");
	scanf_s("%s", pc->dete[pc->sz].number, sizeof(pc->dete[pc->sz].number));
	printf("�������ַ��");
	scanf_s("%s", pc->dete[pc->sz].address, sizeof(pc->dete[pc->sz].address));
	pc->sz++;
	printf("��ӳɹ�\n");
}

void AddMax(contact * pc)//��ַ����
{
	conInfo* temp = 0;
	if (pc->MaxCapacity == pc->sz)
	{
		temp = (conInfo*)realloc(pc->dete, (pc->MaxCapacity + DETEADD) * sizeof(conInfo));
		//�������ĵ�ַ
		if (temp == NULL)
		{
			perror("Info");//��ӡ����
			printf("��̬��ַ�������");
			return;
		}
		else
		{
			pc->dete = temp;
			pc->MaxCapacity += DETEADD;
			printf("���ݳɹ�\n");
		}
	}
}
void DelContact(contact* pc)//ɾ������
{
	if (pc->sz==0)
	{
		printf("ͨѶ¼Ϊ�գ�");
		return;
	}
	char name[MAX_NAME] = { 0 };
	int i = 0;
	printf("������Ҫɾ������Ա������:\n");
	scanf_s("%s", &name, sizeof(name));
	int temp = FindName(pc, name);//���ò��Һ���
	if (temp==-1)
	{
		printf("ͨѶ¼��û�д��ˣ�");
		return;
	}
	for ( i = temp; i < pc->sz -1; i++)//������ǰ���ǣ����һ��������
	{
		pc->dete[i] = pc->dete[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
	return;
}

void ModifiContact(contact* pc)//�޸�
{
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�");
		return;
	}
	char name[MAX_ADDR];
	printf("������Ҫ�޸��˵����֣�");
	scanf_s("%s", name, sizeof(name));
	int temp = FindName(pc, name);//���ò��Һ���
	if (temp == -1)
	{
		printf("ͨѶ¼��û�д��ˣ�");
		return;
	}
	printf("�������Ա�");
	scanf_s("%s", pc->dete[temp].sex, sizeof(pc->dete[temp].sex));
	printf("��������룺");
	scanf_s("%s", pc->dete[temp].number, sizeof(pc->dete[temp].number));
	printf("�������ַ��");
	scanf_s("%s", pc->dete[temp].address, sizeof(pc->dete[temp].address));
	printf("�޸ĳɹ�");
	
}
void SearchContact(contact* pc)//���������
{
	char name[MAX_ADDR];
	printf("������Ҫ���ҵ����֣�");
	scanf_s("%s", name,sizeof(name));
	int temp = FindName(pc, name);//����С����
	if (temp==-1)
	{
		printf("δ�ҵ�����\n");
		return;
	}
	printf("%-10s\t%-5s\t%-15s\t%-15s\n", "����", "�Ա�", "����", "��ַ");
	printf("%-10s\t%-5s\t%-15s\t%-15s\n", pc->dete[temp].name, pc->dete[temp].sex, pc->dete[temp].number, pc->dete[temp].address);
}
int FindName(contact* pc, char name[MAX_NAME])//����С����
{
	int i;
	for ( i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->dete[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;//û�ҵ�
}


void PrintContact(contact* pc) //��ӡͨѶ¼
{
	int i;
	printf("%-10s\t%-5s\t%-15s\t%-15s\n", "����", "�Ա�", "����", "��ַ");
	for ( i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5s\t%-15s\t%-15s\n", pc->dete[i].name, pc->dete[i].sex, pc->dete[i].number, pc->dete[i].address);
	}

}