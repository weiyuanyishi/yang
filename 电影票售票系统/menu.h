#ifndef _MENU
#define _MENU

#include "mainControl.h"
#include "user.h"
#include "administrator.h"
#include "file.h"
#include "movie.h"

void menu();//顶层菜单函数
void menuUser_choose();//用户选择进入方式菜单函数
void menuUser_fregister();//用户注册失败菜单函数
void menuUser_sregister();//用户注册成功菜单函数
void menuUser_fenter();//用户登录失败菜单函数
void menuUser_function();//用户功能菜单函数
void menuAdministrator_fail_enter();//管理员登录失败菜单
void menuAdministrator_function();//管理员功能菜单函数
void menuAdministrator_change_function();//管理员修改电影信息选项菜单
void menuAdministrator_choose_sort();//管理员选择排序方式菜单
#endif