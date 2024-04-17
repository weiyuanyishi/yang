#ifndef _MAINCONTROL
#define _MAINCONTROL

#include "user.h"
#include "administrator.h"
#include "menu.h"
#include "file.h"
#include "movie.h"

void run_read_file();//读文件
void run_save_file();//存文件
void run_identity_choose();//选择身份
void run_user_choose();//用户选择注册或登录
void run_user_register();//用户注册函数
void run_user_fail_register();//用户注册失败函数
void run_user_succeed_register();//用户注册成功函数
void run_user_enter();//用户登录函数
void run_user_fail_enter();//用户登录失败函数 
void run_user_choose_function();//用户选择功能函数
void run_user_function1();//用户功能1：浏览片场信息
void run_user_function2();//用户功能2：查看放映厅售票情况
void run_user_function3(user_movie);//用户功能3：选座购票
void run_user_function4(user_movie);//用户功能4：退票
void run_user_function5();//用户功能5：关闭系统
void run_administrator_enter();//管理员登录函数
void run_administrator_fail_enter();//管理员登录失败函数
void run_administrator_choose_function();//管理员选择功能函数
void run_administrator_function1();//管理员功能1：浏览片场信息
void run_administrator_function2();//管理员功能2：添加片场信息
void run_administrator_function3();//管理员功能3：修改片场信息
void run_administrator_function4();//管理员功能4：删除片场信息
void run_administrator_function5();//管理员功能5：统计某部电影当天票款
void run_administrator_function6();//管理员功能6：票房排序
void run_administrator_function7();//管理员功能7：关闭系统
#endif