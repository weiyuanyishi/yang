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


//记录所有管理员的信息
information2 administrator[3];// = { {"liuche", "040910"},{"qinxinyu","050315"},{"zhangyang","050901"} };

//定义一个记录管理员数量的变量
int num_administrator = 3;

int administrator_enter();//管理员登录函数
void administrator_function1();//管理员功能函数1：浏览片场信息
void administrator_function2();//管理员功能函数2：添加片场信息
void administrator_function3(int j, int choice);//管理员功能函数3：修改片场信息
void administrator_function4(int j);//管理员功能函数4：删除片场信息
void administrator_function5();//管理员功能函数5：统计某部电影当天票款
void administrator_function6(int choice);//管理员功能函数6：票房排序
void administrator_function7();//管理员功能函数7：关闭系统
#endif