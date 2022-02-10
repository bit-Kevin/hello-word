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
//静态地址
//typedef struct  contact
//{
//	conInfo dete[MAX];
//	int sz;
//
//}contact;

//动态地址
typedef struct  contact
{
	conInfo* dete;//指向动态地址的指针
	int sz;//当前存储个数
	int MaxCapacity;//最大容量

}contact;

//初始化函数
void Info(contact* pc);
void SaveDete(contact* pc);//保存数据
void LoadDete(contact * pc);//加载保存的数据
void DestroyContact(contact * pc);//退出并释放动态空间
void AddContact(contact * pc);//添加人员
void AddMax(pc);//地址扩容
void DelContact(contact * pc);//删除函数
void SearchContact(contact * pc);//搜索大程序
int FindName(contact* pc,char name[MAX_NAME]);//搜索小程序
void PrintContact(contact * pc); //打印通讯录
void ModifiContact(contact * pc);//修改


