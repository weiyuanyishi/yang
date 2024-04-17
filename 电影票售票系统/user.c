#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mainControl.h"
#include "user.h"
#include "administrator.h"
#include "menu.h"
#include "file.h"
#include "movie.h"

//函数功能：用户注册函数
//函数参数：
//函数返回值：注册成功或失败的结果
int user_register()
{
	int i, x = 0;
	//定义一个接收用户输入信息的information1类型变量
	information1 input;
	printf("请注册：\n");
	printf("请设置用户名：");
	scanf_s("%s",input.account_number);
	printf("请设置密码：");
	scanf_s("%s", input.password);
	//遍历所有用户，看有没有用户名对的上的，对上了就x++
	for (i = 0;i < num_user;i++)
		if (strcmp(input.account_number, user[i].account_number) == 0)
			x++;
	//x不等于0证明该用户名已经存在，故注册失败，返回0
	if (x != 0)
	{
		return 0;
	}
	//若x等于0，证明该用户还未注册过，可以注册，将输入的用户信息复制到user数组中
	//此时用户数量加1
	else
	{
		strcpy_s(user[num_user].account_number, sizeof(input.account_number), input.account_number);
		strcpy_s(user[num_user].password, sizeof(input.password), input.password);
		num_user++;
		return 1;
	}
}
//函数功能：用户登录函数
//函数参数：
//函数返回值：x(判断登录是否成功)
int user_enter()
{
	int i, x=0, choice;
	//定义一个接收用户输入信息的information1类型变量
	information1 input;
	printf("请输入用户名：");
	scanf_s("%s", input.account_number);
	printf("请输入密码：");
	scanf_s("%s", input.password);
	for (i = 0;i < num_user;i++)
		if (input.account_number == user[i].account_number && input.password == user[i].password)
			x = 1;
	return x;
}
//用户功能函数1：浏览片场信息
void user_function1()
{
	show_movie_file();
}
//用户功能函数2：查看电影售票情况
void user_function2()
{
	int x, i, choice;
	do
	{
		printf("请输入要查看电影的编号：");
		scanf_s("%d", &x);
		if (x >= 1 && x <= 5)
		{
			choice = movie[x].video_hall_number;
			printf("该电影所在放映厅为%d号厅，其售票情况如下：\n", choice);
			show_seat_array(choice);
			break;
		}
		else
			printf("输入错误，请按要求重新选择\n");
	} while (1);
}                                                                                                                                                 
//用户功能函数3：选座购票
//形式参数：用户所选电影指针
//返回值：所选电影的编号
void user_function3()
{
	do
	{
		printf("请输入要购票电影的编号：");
		scanf_s("%d", &location.movie_number);
		if (location.movie_number >= 1 && location.movie_number <= 5)
		{
			location.video_hall_number = movie[location.movie_number].video_hall_number;
			printf("该电影所在放映厅为%d号厅，其售票情况如下：\n", location.video_hall_number);
			show_seat_array(location.video_hall_number);
			break;
		}
		else
			printf("输入错误，请按要求重新选择\n");
	} while (1);
	do
	{
		printf("请选择座位\n");
		printf("请输入行标：");
		scanf_s("%d", &location.x);
		printf("请输入列标：");
		scanf_s("%d", &location.y);
		if (seat[location.video_hall_number].seat_array[location.x][location.y] != '$')
		{
			//空座位变有座位
			seat[location.video_hall_number].seat_array[location.x][location.y] = '$';
			//该电影已售加1，余票减1
			movie[location.movie_number].sold_ticket++;
			movie[location.movie_number].surplus_ticket--;
			printf("购票成功！");
			break;
		}
		else
			printf("该座位已被占用，请重新选择\n");
	} while (1);
}
//用户功能函数4：退票
void user_function4()
{
	movie[location.movie_number].sold_ticket--;
	movie[location.movie_number].surplus_ticket++;
	//重新变为空座位
	seat[location.video_hall_number].seat_array[location.x][location.y] = '-';
	printf("退票成功！");
}
