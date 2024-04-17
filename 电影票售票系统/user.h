#ifndef _USER//条件编译，防止重复包含的错误
#define _USER

#include "mainControl.h"
#include "administrator.h"
#include "menu.h"
#include "file.h"
#include "movie.h"

//已注册用户数
int num_user;

typedef struct user_information//用户记录所属结构体类型的定义及取别名
{
	char account_number[20];//用户名
	char password[10];//密码
}information1;

//记录已注册的用户信息
information1 user[1000];// = { {"zhangsan","123456"},{"lisi","456789"},{"wangwu","789123"} };

int user_register();//用户注册函数
int user_enter();//用户登录函数
void user_function1();//用户功能函数1：浏览片场信息
void user_function2();//用户功能函数2：查看电影售票情况
void user_function3();//用户功能函数3：选座购票
void user_function4();//用户功能函数4：退票
#endif