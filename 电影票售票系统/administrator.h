#ifndef _ADMINISTRATOR
#define _ADMINISTRATOR

#include "mainControl.h"
#include "user.h"
#include "menu.h"
#include "file.h"
#include "movie.h"

/*
typedef struct administrator_information
{
	char name[20];
	char password[10];
}information2;
*/

struct administrator_information
{
	char name[20];
	char password[10];
};

typedef struct administrator_information information2;


//��¼���й���Ա����Ϣ
information2 administrator[3];// = { {"liuche", "040910"},{"qinxinyu","050315"},{"zhangyang","050901"} };

//����һ����¼����Ա�����ı���
int num_administrator = 3;

int administrator_enter();//����Ա��¼����
void administrator_function1();//����Ա���ܺ���1�����Ƭ����Ϣ
void administrator_function2();//����Ա���ܺ���2�����Ƭ����Ϣ
void administrator_function3(int j, int choice);//����Ա���ܺ���3���޸�Ƭ����Ϣ
void administrator_function4(int j);//����Ա���ܺ���4��ɾ��Ƭ����Ϣ
void administrator_function5();//����Ա���ܺ���5��ͳ��ĳ����Ӱ����Ʊ��
void administrator_function6(int choice);//����Ա���ܺ���6��Ʊ������
void administrator_function7();//����Ա���ܺ���7���ر�ϵͳ
#endif