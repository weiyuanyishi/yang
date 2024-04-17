#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mainControl.h"
#include "user.h"
#include "administrator.h"
#include "menu.h"
#include "file.h"
#include "movie.h"

//管理员登录函数
int administrator_enter()
{
	int i, x = 0;
	information2 input;
	printf("请输入姓名：");
	scanf_s("%s", input.name);
	printf("请输入密码：");
	scanf_s("%s", input.password);
	for (i = 0;i < num_administrator;i++)
		if (input.name == administrator[i].name && input.password == administrator[i].password)
			x = 1;
	return x;
}
//管理员功能1：浏览片场信息
void administrator_function1()
{
	show_movie_file();
}
//管理员功能2：添加片场信息
void administrator_function2()
{
	printf("请输入要添加片场电影的所有信息：\n");
	printf("请输入电影名：");
	scanf_s("%s", movie[num_movie].movie_title);
	printf("请输入放映时间：");
	scanf_s("%s", movie[num_movie].show_time);
	printf("请输入放映厅名：");
	scanf_s("%s", movie[num_movie].video_hall);
	printf("请输入放映厅编号：");
	scanf_s("%d", movie[num_movie].video_hall_number);
	printf("请输入票价：");
	scanf_s("%d", movie[num_movie].ticket_rate);
	//赋电影编号
	movie[num_movie].set_number = num_movie;
	//初始座位数量为64
	movie[num_movie].num_seat = 64;
	//初始已售为0
	movie[num_movie].sold_ticket = 0;
	//初始余票为64
	movie[num_movie].surplus_ticket = 64;
	//电影总数加1
	num_movie++;
}
//管理员功能3：修改片场信息
void administrator_function3(int j, int choice)
{
	char *index;
	int temp;
	switch (choice)
	{
	case 1:
		printf("请输入修改后的片名：");
		scanf_s("%s", index);
		strcpy_s(movie[j].movie_title, sizeof(index), index);
		break;
	case 2:
		printf("请输入修改后的放映时间：");
		scanf_s("%s", index);
		strcpy_s(movie[j].show_time, sizeof(index), index);
		break;
	case 3:
		printf("请输入修改后的放映厅名：");
		scanf_s("%s", index);
		strcpy_s(movie[j].video_hall, sizeof(index), index);
		break;
	case 4:
		printf("请输入修改后的放映厅编号：");
		scanf_s("%s", index);
		strcpy_s(movie[j].video_hall_number, sizeof(index), index);
		break;
	case 5:
		printf("请输入修改后的座位数量：");
		scanf_s("%d", &temp);
		movie[j].num_seat = temp;
		break;
	case 6:
		printf("请输入修改后的已售数：");
		scanf_s("%d", &temp);
		movie[j].sold_ticket = temp;
		break;
	case 7:
		printf("请输入修改后的余票数：");
		scanf_s("%d", &temp);
		movie[j].surplus_ticket = temp;
		break;
	case 8:
		printf("请输入修改后的票价：");
		scanf_s("%d", &temp);
		movie[j].ticket_rate = temp;
		break;
	}
}
//管理员功能4：删除片场信息
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
//管理员功能5：统计某部电影当天票款
void administrator_function5()
{
	int i;
	for (i = 0;i < num_movie;i++)
	{
		box_office[i].movie_number = i;
		box_office[i].money = movie[i].sold_ticket * movie[i].ticket_rate;
	}
}
//管理员功能6：票房排序
void administrator_function6(int choice)
{
	int i, k, index, temp;
	int a[20];
	switch (choice)
	{
	case 1:
		printf("从高到低排序如下：\n");
		printf("%8s%28s","票房","电影名");
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
		printf("从低到高排序如下：\n");
		printf("%8s%28s", "票房", "电影名");
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
//管理员功能7：关闭系统
void administrator_function7()
{
	printf("感谢您的使用，再见！");
}

