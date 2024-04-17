#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mainControl.h"
#include "user.h"
#include "administrator.h"
#include "menu.h"
#include "file.h"
#include "movie.h"

//����Ա��¼����
int administrator_enter()
{
	int i, x = 0;
	information2 input;
	printf("������������");
	scanf_s("%s", input.name);
	printf("���������룺");
	scanf_s("%s", input.password);
	for (i = 0;i < num_administrator;i++)
		if (input.name == administrator[i].name && input.password == administrator[i].password)
			x = 1;
	return x;
}
//����Ա����1�����Ƭ����Ϣ
void administrator_function1()
{
	show_movie_file();
}
//����Ա����2�����Ƭ����Ϣ
void administrator_function2()
{
	printf("������Ҫ���Ƭ����Ӱ��������Ϣ��\n");
	printf("�������Ӱ����");
	scanf_s("%s", movie[num_movie].movie_title);
	printf("�������ӳʱ�䣺");
	scanf_s("%s", movie[num_movie].show_time);
	printf("�������ӳ������");
	scanf_s("%s", movie[num_movie].video_hall);
	printf("�������ӳ����ţ�");
	scanf_s("%d", movie[num_movie].video_hall_number);
	printf("������Ʊ�ۣ�");
	scanf_s("%d", movie[num_movie].ticket_rate);
	//����Ӱ���
	movie[num_movie].set_number = num_movie;
	//��ʼ��λ����Ϊ64
	movie[num_movie].num_seat = 64;
	//��ʼ����Ϊ0
	movie[num_movie].sold_ticket = 0;
	//��ʼ��ƱΪ64
	movie[num_movie].surplus_ticket = 64;
	//��Ӱ������1
	num_movie++;
}
//����Ա����3���޸�Ƭ����Ϣ
void administrator_function3(int j, int choice)
{
	char *index;
	int temp;
	switch (choice)
	{
	case 1:
		printf("�������޸ĺ��Ƭ����");
		scanf_s("%s", index);
		strcpy_s(movie[j].movie_title, sizeof(index), index);
		break;
	case 2:
		printf("�������޸ĺ�ķ�ӳʱ�䣺");
		scanf_s("%s", index);
		strcpy_s(movie[j].show_time, sizeof(index), index);
		break;
	case 3:
		printf("�������޸ĺ�ķ�ӳ������");
		scanf_s("%s", index);
		strcpy_s(movie[j].video_hall, sizeof(index), index);
		break;
	case 4:
		printf("�������޸ĺ�ķ�ӳ����ţ�");
		scanf_s("%s", index);
		strcpy_s(movie[j].video_hall_number, sizeof(index), index);
		break;
	case 5:
		printf("�������޸ĺ����λ������");
		scanf_s("%d", &temp);
		movie[j].num_seat = temp;
		break;
	case 6:
		printf("�������޸ĺ����������");
		scanf_s("%d", &temp);
		movie[j].sold_ticket = temp;
		break;
	case 7:
		printf("�������޸ĺ����Ʊ����");
		scanf_s("%d", &temp);
		movie[j].surplus_ticket = temp;
		break;
	case 8:
		printf("�������޸ĺ��Ʊ�ۣ�");
		scanf_s("%d", &temp);
		movie[j].ticket_rate = temp;
		break;
	}
}
//����Ա����4��ɾ��Ƭ����Ϣ
void administrator_function4(int j)
{
	int i;
	for (i = j;i < num_movie;i++)
	{
		strcpy_s(movie[i].movie_title, sizeof(movie[i + 1].movie_title), movie[i + 1].movie_title);
		strcpy_s(movie[i].show_time, sizeof(movie[i + 1].show_time), movie[i + 1].show_time);
		strcpy_s(movie[i].video_hall, sizeof(movie[i + 1].video_hall), movie[i + 1].video_hall);
		movie[i].video_hall_number = movie[i + 1].video_hall_number;
		movie[i].sold_ticket = movie[i + 1].sold_ticket;
		movie[i].surplus_ticket = movie[i + 1].surplus_ticket;
		movie[i].ticket_rate = movie[i + 1].ticket_rate;
	}
	num_movie--;
}
//����Ա����5��ͳ��ĳ����Ӱ����Ʊ��
void administrator_function5()
{
	int i;
	for (i = 0;i < num_movie;i++)
	{
		box_office[i].movie_number = i;
		box_office[i].money = movie[i].sold_ticket * movie[i].ticket_rate;
	}
}
//����Ա����6��Ʊ������
void administrator_function6(int choice)
{
	int i, k, index, temp;
	int a[20];
	switch (choice)
	{
	case 1:
		printf("�Ӹߵ����������£�\n");
		printf("%8s%28s","Ʊ��","��Ӱ��");
		for (i = 0;i < num_movie;i++)
			a[i] = box_office[i].money;
		for (k = 0;k < num_movie - 1;k++)
		{
			index = k;
			for (i = k + 1;i < num_movie;i++)
				if (a[i] > a[index])
					index = i;
			if (index != k)
			{
				temp = a[index];
				a[index] = a[k];
				a[k] = temp;
			}
		}
		for (k = 0;k < num_movie;k++)
		{
			for (i = 0;i < num_movie;i++)
			{
				if (box_office[i].money == a[k])
				{
					printf("%8d%28s\n", box_office[i].money, movie[box_office[i].movie_number].movie_title);
				}
			}
		}
	case 2:
		printf("�ӵ͵����������£�\n");
		printf("%8s%28s", "Ʊ��", "��Ӱ��");
		for (i = 0;i < num_movie;i++)
			a[i] = box_office[i].money;
		for (k = 0;k < num_movie - 1;k++)
		{
			index = k;
			for (i = k + 1;i < num_movie;i++)
				if (a[i] < a[index])
					index = i;
			if (index != k)
			{
				temp = a[index];
				a[index] = a[k];
				a[k] = temp;
			}
		}
		for (k = 0;k < num_movie;k++)
		{
			for (i = 0;i < num_movie;i++)
			{
				if (box_office[i].money == a[k])
				{
					printf("%8d%28s\n", box_office[i].money, movie[box_office[i].movie_number].movie_title);
				}
			}
		}
	}
}
//����Ա����7���ر�ϵͳ
void administrator_function7()
{
	printf("��л����ʹ�ã��ټ���");
}

