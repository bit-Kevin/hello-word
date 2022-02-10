#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>   
#include <sys/stat.h>

#define MAX 200
#define MAX_NAME 20
#define MAX_SEX 6
#define MAX_NUMBER 11
#define MAX_ADDR 20
#define INFODETE_SE 3
#define DETEADD 2

typedef struct book
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char number[MAX_NUMBER];
	char address[MAX_ADDR];
}conInfo;
//��̬��ַ
//typedef struct  contact
//{
//	conInfo dete[MAX];
//	int sz;
//
//}contact;

//��̬��ַ
typedef struct  contact
{
	conInfo* dete;//ָ��̬��ַ��ָ��
	int sz;//��ǰ�洢����
	int MaxCapacity;//�������

}contact;

//��ʼ������
void Info(contact* pc);
void SaveDete(contact* pc);//��������
void LoadDete(contact * pc);//���ر��������
void DestroyContact(contact * pc);//�˳����ͷŶ�̬�ռ�
void AddContact(contact * pc);//�����Ա
void AddMax(pc);//��ַ����
void DelContact(contact * pc);//ɾ������
void SearchContact(contact * pc);//���������
int FindName(contact* pc,char name[MAX_NAME]);//����С����
void PrintContact(contact * pc); //��ӡͨѶ¼
void ModifiContact(contact * pc);//�޸�


