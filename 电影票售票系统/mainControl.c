#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mainControl.h"
#include "user.h"
#include "administrator.h"
#include "menu.h"
#include "file.h"
#include "movie.h"
//函数功能：主函数，读取各个文件信息，进入第一步
//函数参数：无
//函数返回值：返回0
int main()
{
	//调用读取文件函数
	run_read_file();
	//开始程序
	run_identity_choose();
	//调用保存文件函数
	run_save_file();

	return 0;
}
//读文件
void run_read_file()
{
	//打开对应文件获取已注册用户的信息和用户数num_user
	num_user = read_user_file(user);
	//打开对应文件获取管理员的信息
	read_administrator_file(administrator);
	//打开对应文件获取电影的信息和在片场电影数
	num_movie = read_movie_file(movie);
	//打开对应文件获取放映厅座位信息
	read_seat_file(seat);
}
//存文件
void run_save_file()
{
	//存用户
	save_user_file(user, num_user);
	//存管理员
	save_administrator_file(administrator, num_administrator);
	//存电影
	save_movie_file(movie, num_movie);
	//存座位
	save_seat_file();
}
//函数功能：身份选择函数
//函数参数：无
//函数返回值：返回0
void run_identity_choose()
{
	//以choice接收输入值选择不同身份登录
	int choice;
	do
	{
		//召唤顶层菜单
		menu();
		printf("请选择：");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			//进入用户选择界面
			run_user_choose();
			break;
		case 2:
			//进入管理员登录界面
			run_administrator_enter();
			break;
		case 0:
			//退出系统
			break;
		default:
			printf("输入有误，请重新选择\n");
		}
	} while (1);
}
//函数功能：用户选择注册或登录
//函数参数：
//函数返回值：无
void run_user_choose()
{
	int choice;
	do
	{
		menuUser_choose();
		printf("请选择：");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			//用户注册
			run_user_register();
			break;
		case 2:
			//用户登录
			run_user_enter();
			break;
		case 0:
			//返回上级菜单
			main();
			break;
		default:
			printf("输入错误，请按要求重新选择\n");
		}
	} while (1);
}
//函数功能：用户注册函数
//函数参数：
//函数返回值：无
void run_user_register()
{
	int choice, user_number;
	//注册,用choice接收注册成功或失败的结果
	choice = user_register();
	user_number = choice;
	switch (choice)
	{
	case 0:
		//注册失败（原因只能是用户名已存在）
		printf("该用户名已存在！\n");
		//调用注册失败函数
		run_user_fail_register();
		break;
	case 1:
		//注册成功
		printf("您已注册成功！");
		//调用注册成功函数
		run_user_succeed_register();
		break;
	}
}
//函数功能：用户注册失败函数
//函数参数：
//函数返回值：
void run_user_fail_register()
{
	int choice;
	do
	{
		//召唤注册失败菜单
		menuUser_fregister();
		printf("请选择：");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			//重新注册
			run_user_register();
			break;
		case 0:
			//返回用户选择进入方式菜单
			run_user_choose();
			break;
		default:
			printf("输入错误，请按要求重新选择\n");
		}
	} while (1);
}
//函数功能：用户注册成功函数
//函数参数：
//函数返回值：
void run_user_succeed_register()
{
	int choice;
	do
	{
		//召唤注册成功菜单
		menuUser_sregister();
		printf("请选择：");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			//登录
			run_user_enter();
			break;
		case 0:
			//返回用户选择进入方式菜单
			run_user_choose();
			break;
		default:
			printf("输入错误，请按要求重新选择\n");
		}
	} while (1);
}
//函数功能：用户登录函数
//函数参数：
//函数返回值：无
void run_user_enter()
{
	int choice;
	choice = user_enter();
	switch (choice)
	{
	case 1:
		printf("登录成功！");
		//进入用户选择功能函数
		run_user_choose_function();
		break;
	case 0:
		printf("您的用户名或密码有误！\n");
		//进入用户登录失败函数
		run_user_fail_enter();
		break;
	}
}
//函数功能：用户登录失败函数
//函数参数：
//函数返回值：无
void run_user_fail_enter()
{
	int choice;
	do
	{
		//召唤用户登录失败菜单
		menuUser_fenter();
		printf("请选择：");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			//重新登录
			run_user_enter();
			break;
		case 0:
			//返回上级菜单
			run_user_choose();
			break;
		default:
			printf("输入错误，请按要求重新选择\n");
		}
	} while (1);
}
//函数功能：用户选择功能函数
//函数参数：
//函数返回值：无
void run_user_choose_function()
{
	int choice;
	do
	{
		menuUser_function();
		printf("请选择：");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			//浏览片场信息
			run_user_function1();
			break;
		case 2:
			//查看放映厅售票情况
			run_user_function2();
			break;
		case 3:
			//选座购票
			run_user_function3();
			break;
		case 4:
			//退票
			run_user_function4();
			break;
		case 5:
			//关闭系统
			run_user_function5();
			break;
		case 0:
			//返回上级菜单
			run_user_choose();
			break;
		default:
			printf("输入错误，请按要求重新选择\n");
		}
	} while (1);
}
//用户功能1：浏览片场信息
void run_user_function1()
{
	user_function1();
	run_user_choose_function();
}
//用户功能2：查看放映厅售票情况
void run_user_function2()
{
	user_function2();
	run_user_choose_function();
}
//用户功能3：选座购票
void run_user_function3(user_movie)
{
	user_function3(user_movie);
	run_user_choose_function();
}
//用户功能4：退票
void run_user_function4(user_movie)
{
	user_function4(user_movie);
	run_user_choose_function();
}
//用户功能5：关闭系统
void run_user_function5()
{
	printf("感谢您的使用，再见！");
}
//函数功能：管理员登录函数
//函数参数：
//函数返回值：无
void run_administrator_enter()
{
	int choice;
	choice = administrator_enter();
	switch (choice)
	{
	case 1:
		printf("登录成功！");
		//进入管理员选择功能函数
		run_user_choose_function();
		break;
	case 0:
		printf("您的用户名或密码有误！\n");
		//进入管理员登录失败函数
		run_administrator_fail_enter();
		break;
	}
}
//管理员登录失败函数
void run_administrator_fail_enter()
{
	int choice;
	do
	{
		//召唤管理员登录失败菜单
		menuUser_fenter();
		printf("请选择：");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			//重新登录
			run_administrator_enter();
			break;
		case 0:
			//返回上级菜单
			run_identity_choose();
			break;
		default:
			printf("输入错误，请按要求重新选择\n");
		}
	} while (1);
}
//管理员选择功能函数
void run_administrator_choose_function()
{
	int choice;
	do
	{
		menuAdministrator_function();
		printf("请选择：");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			//浏览片场信息
			run_administrator_function1();
			break;
		case 2:
			//添加片场信息
			run_administrator_function2();
			break;
		case 3:
			//修改片场信息
			run_administrator_function3();
			break;
		case 4:
			//删除片场信息
			run_administrator_function4();
			break;
		case 5:
			//统计某部电影当天票款
			run_administrator_function5();
			break;
		case 6:
			//票房排序
			run_administrator_function6();
			break;
		case 7:
			//关闭系统
			run_administrator_function7();
			break;
		case 0:
			//返回上级菜单
			run_administrator_choose();
			break;
		default:
			printf("输入错误，请按要求重新选择\n");
		}
	} while (1);
}
//管理员功能1：浏览片场信息
void run_administrator_function1()
{
	administrator_function1();
	run_administrator_choose_function();
}
//管理员功能2：添加片场信息
void run_administrator_function2()
{
	administrator_function2();
	run_administrator_choose_function();
}
//管理员功能3：修改片场信息
void run_administrator_function3()
{
	int j, choice;
	do
	{
		printf("请输入要修改电影的编号：");
		scanf_s("%d", &j);
		if (j >= 0 && j < num_movie)
			break;
		else
			printf("输入错误，请按要求重新选择\n");
	} while (1);
	printf("所选电影的信息如下：\n");
	printf("%9d%28s%20s%14s%10d%8d%8d%6d\n",
		movie[j].set_number, movie[j].movie_title, movie[j].show_time, movie[j].video_hall, movie[j].num_seat, movie[j].sold_ticket, movie[j].surplus_ticket, movie[j].ticket_rate);
	do
	{
		menuAdministrator_change_function();
		printf("选择修改项目：\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			administrator_function3(j, choice);
			printf("已修改");
		case 0:
			printf("修改已完成！");
			break;
		default:
			printf("输入错误，请按要求重新选择\n");
		}
	} while (1);
	run_administrator_choose_function();
}
//管理员功能4：删除片场信息
void run_administrator_function4()
{
	int j;
	do
	{
		printf("请输入要删除电影的编号：");
		scanf_s("%d", &j);
		if (j >= 0 && j < num_movie)
			break;
		else
			printf("输入错误，请按要求重新选择\n");
	} while (1);
	printf("所选电影的信息如下：\n");
	printf("%9d%28s%20s%14s%10d%8d%8d%6d\n",
		movie[j].set_number, movie[j].movie_title, movie[j].show_time, movie[j].video_hall, movie[j].num_seat, movie[j].sold_ticket, movie[j].surplus_ticket, movie[j].ticket_rate);
	administrator_function4(j);
	printf("已删除所选电影片场信息！");
	run_administrator_choose_function();
}
//管理员功能5：统计某部电影当天票款
void run_administrator_function5()
{
	//先调用管理员功能5函数，求出所有电影的票房
	administrator_function5();
	int j;
	do
	{
		printf("请输入要查看票房电影的编号：");
		scanf_s("%d", &j);
		if (j >= 0 && j < num_movie)
			break;
		else
			printf("输入错误，请按要求重新选择\n");
	} while (1);
	printf("所选电影今日的票房为%d：",box_office[j]);
	run_administrator_choose_function();
}
//管理员功能6：票房排序
void run_administrator_function6()
{
	int choice;
	do
	{
		menuAdministrator_choose_sort();
		printf("请选择排序方式：");
		scanf_s("%d", &choice);
		if (choice >= 1 && choice <= 2)
			break;
		else
			printf("输入错误，请按要求重新选择\n");
	} while (1);
	administrator_function6(choice);
	run_administrator_choose_function();
}
//管理员功能7：关闭系统
void run_administrator_function7()
{
	administrator_function7();
}