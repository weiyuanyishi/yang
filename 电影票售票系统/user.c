#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mainControl.h"
#include "user.h"
#include "administrator.h"
#include "menu.h"
#include "file.h"
#include "movie.h"

//�������ܣ��û�ע�ắ��
//����������
//��������ֵ��ע��ɹ���ʧ�ܵĽ��
int user_register()
{
	int i, x = 0;
	//����һ�������û�������Ϣ��information1���ͱ���
	information1 input;
	printf("��ע�᣺\n");
	printf("�������û�����");
	scanf_s("%s",input.account_number);
	printf("���������룺");
	scanf_s("%s", input.password);
	//���������û�������û���û����Ե��ϵģ������˾�x++
	for (i = 0;i < num_user;i++)
		if (strcmp(input.account_number, user[i].account_number) == 0)
			x++;
	//x������0֤�����û����Ѿ����ڣ���ע��ʧ�ܣ�����0
	if (x != 0)
	{
		return 0;
	}
	//��x����0��֤�����û���δע���������ע�ᣬ��������û���Ϣ���Ƶ�user������
	//��ʱ�û�������1
	else
	{
		strcpy_s(user[num_user].account_number, sizeof(input.account_number), input.account_number);
		strcpy_s(user[num_user].password, sizeof(input.password), input.password);
		num_user++;
		return 1;
	}
}
//�������ܣ��û���¼����
//����������
//��������ֵ��x(�жϵ�¼�Ƿ�ɹ�)
int user_enter()
{
	int i, x=0, choice;
	//����һ�������û�������Ϣ��information1���ͱ���
	information1 input;
	printf("�������û�����");
	scanf_s("%s", input.account_number);
	printf("���������룺");
	scanf_s("%s", input.password);
	for (i = 0;i < num_user;i++)
		if (input.account_number == user[i].account_number && input.password == user[i].password)
			x = 1;
	return x;
}
//�û����ܺ���1�����Ƭ����Ϣ
void user_function1()
{
	show_movie_file();
}
//�û����ܺ���2���鿴��Ӱ��Ʊ���
void user_function2()
{
	int x, i, choice;
	do
	{
		printf("������Ҫ�鿴��Ӱ�ı�ţ�");
		scanf_s("%d", &x);
		if (x >= 1 && x <= 5)
		{
			choice = movie[x].video_hall_number;
			printf("�õ�Ӱ���ڷ�ӳ��Ϊ%d����������Ʊ������£�\n", choice);
			show_seat_array(choice);
			break;
		}
		else
			printf("��������밴Ҫ������ѡ��\n");
	} while (1);
}                                                                                                                                                 
//�û����ܺ���3��ѡ����Ʊ
//��ʽ�������û���ѡ��Ӱָ��
//����ֵ����ѡ��Ӱ�ı��
void user_function3()
{
	do
	{
		printf("������Ҫ��Ʊ��Ӱ�ı�ţ�");
		scanf_s("%d", &location.movie_number);
		if (location.movie_number >= 1 && location.movie_number <= 5)
		{
			location.video_hall_number = movie[location.movie_number].video_hall_number;
			printf("�õ�Ӱ���ڷ�ӳ��Ϊ%d����������Ʊ������£�\n", location.video_hall_number);
			show_seat_array(location.video_hall_number);
			break;
		}
		else
			printf("��������밴Ҫ������ѡ��\n");
	} while (1);
	do
	{
		printf("��ѡ����λ\n");
		printf("�������б꣺");
		scanf_s("%d", &location.x);
		printf("�������б꣺");
		scanf_s("%d", &location.y);
		if (seat[location.video_hall_number].seat_array[location.x][location.y] != '$')
		{
			//����λ������λ
			seat[location.video_hall_number].seat_array[location.x][location.y] = '$';
			//�õ�Ӱ���ۼ�1����Ʊ��1
			movie[location.movie_number].sold_ticket++;
			movie[location.movie_number].surplus_ticket--;
			printf("��Ʊ�ɹ���");
			break;
		}
		else
			printf("����λ�ѱ�ռ�ã�������ѡ��\n");
	} while (1);
}
//�û����ܺ���4����Ʊ
void user_function4()
{
	movie[location.movie_number].sold_ticket--;
	movie[location.movie_number].surplus_ticket++;
	//���±�Ϊ����λ
	seat[location.video_hall_number].seat_array[location.x][location.y] = '-';
	printf("��Ʊ�ɹ���");
}
