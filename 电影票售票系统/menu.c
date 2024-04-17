#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mainControl.h"
#include "user.h"
#include "administrator.h"
#include "menu.h"
#include "file.h"
#include "movie.h"
//顶层菜单函数
void menu()
{
	printf("-------------电影院售票系统-------------\n");
	printf("【1】用户登录\n");
	printf("【2】管理员登录\n");
	printf("【0】退出系统\n");
	printf("--------------------------------------\n");
}
//用户选择进入方式菜单函数
void menuUser_choose()
{
	printf("---------------用户登录---------------\n");
	printf("【1】注册\n");
	printf("【2】登录\n");
	printf("【0】返回上级菜单\n");
	printf("-------------------------------------\n");
}
//用户注册失败菜单函数
void menuUser_fregister()
{
	printf("---------------注册失败---------------\n");
	printf("【1】重新注册\n");
	printf("【0】返回上级菜单\n");
	printf("-------------------------------------\n");
}
//用户注册成功菜单函数
void menuUser_sregister()
{
	printf("---------------注册成功---------------\n");
	printf("【1】登录\n");
	printf("【0】返回上级菜单\n");
	printf("-------------------------------------\n");
}
//用户登录失败菜单函数
void menuUser_fenter()
{
	printf("---------------登录失败---------------\n");
	printf("【1】重新登录\n");
	printf("【0】返回上级菜单\n");
	printf("-------------------------------------\n");
}
//用户功能菜单函数
void menuUser_function()
{
	printf("-----------------功能-----------------\n");
	printf("【1】浏览片场信息\n");
	printf("【2】查看放映厅售票情况\n");
	printf("【3】选座购票\n");
	printf("【4】退票\n");
	printf("【5】关闭系统\n");
	printf("【0】返回上级菜单\n");
	printf("-------------------------------------\n");
}
//管理员登录失败菜单
void menuAdministrator_fail_enter()
{
	printf("---------------管理员登录失败---------------\n");
	printf("【1】重新登录\n");
	printf("【0】返回上级菜单\n");
	printf("------------------------------------------\n");
}
//管理员功能菜单函数
void menuAdministrator_function()
{
	printf("-----------------功能-----------------\n");
	printf("【1】浏览片场信息\n");
	printf("【2】添加片场信息\n");
	printf("【3】修改片场信息\n");
	printf("【4】删除片场信息\n");
	printf("【5】统计某部电影当天票款\n");
	printf("【6】票房排序\n");
	printf("【7】关闭系统\n");
	printf("【0】返回上级菜单\n");
	printf("-------------------------------------\n");
}
//管理员修改电影信息选项菜单
void menuAdministrator_change_function()
{
	printf("-----------------修改项目-----------------\n");
	printf("【1】片名\n");
	printf("【2】放映时间\n");
	printf("【3】放映厅名\n");
	printf("【4】放映厅编号\n");
	printf("【5】座位数量\n");
	printf("【6】已售\n");
	printf("【7】余票\n");
	printf("【8】票价\n");
	printf("【0】修改完毕\n");
	printf("---------------------------------------------\n");
}
//管理员选择排序方式菜单
void menuAdministrator_choose_sort()
{
	printf("-----------------排序方式-----------------\n");
	printf("【1】从高票房到低票房\n");
	printf("【2】从低票房到高票房\n");
	printf("-----------------------------------------\n");
}
