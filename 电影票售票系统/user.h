#ifndef _USER//�������룬��ֹ�ظ������Ĵ���
#define _USER

#include "mainControl.h"
#include "administrator.h"
#include "menu.h"
#include "file.h"
#include "movie.h"

//��ע���û���
int num_user;

typedef struct user_information//�û���¼�����ṹ�����͵Ķ��弰ȡ����
{
	char account_number[20];//�û���
	char password[10];//����
}information1;

//��¼��ע����û���Ϣ
information1 user[1000];// = { {"zhangsan","123456"},{"lisi","456789"},{"wangwu","789123"} };

int user_register();//�û�ע�ắ��
int user_enter();//�û���¼����
void user_function1();//�û����ܺ���1�����Ƭ����Ϣ
void user_function2();//�û����ܺ���2���鿴��Ӱ��Ʊ���
void user_function3();//�û����ܺ���3��ѡ����Ʊ
void user_function4();//�û����ܺ���4����Ʊ
#endif