#ifndef _MOVIE
#define _MOVIE

#include "mainControl.h"
#include "user.h"
#include "administrator.h"
#include "menu.h"
#include "file.h"

//在片场电影数
int num_movie;

//记录电影票房
typedef struct box_office
{
	int movie_number;
	int money;
}box;

box box_office[20];

//定义一个用于记录电影信息的结构体
typedef struct Movie
{
	int set_number;//电影编号
	char movie_title[40];//片名
	char show_time[20];//放映时间
	char video_hall[20];//放映厅名
	int video_hall_number;//放映厅编号
	int num_seat;//座位数量
	int sold_ticket;//已售
	int surplus_ticket;//余票
	int ticket_rate;//票价
}Movie;

//定义一个Movie类型数组变量记录所有在片场电影的信息
Movie movie[20];/*= {
	{0,"你想活出怎样的人生","2024-05-01^09:30","2号激光厅",2,64,8,56,39},8
	{1,"哥斯拉大战金刚2：帝国崛起","2024-05-01^16:25","1号激光厅",1,64,3,61,36},3
	{2,"功夫熊猫4","2024-05-01^17:05","0号激光厅",0,64,5,59,33},5
	{3,"周处除三害","2024-05-01^16:35","4号激光厅",4,64,6,58,47},6
	{4,"沙丘2","2024-05-01^20:00","3号激光厅",3,64,10,54,55}10
};*/ 

//定义一个用于记录座位的结构体
typedef struct Seat
{
	char seat_array[9][9];
}Seat;

//定义一个Seat类型的数组记录5个放映厅的座位
Seat seat[5];

//定义一个以行列定位座位的结构体变量
typedef struct Location
{
	int movie_number;
	int video_hall_number;
	int x;
	int y;
}Location;

//定义一个记录用户所选座位的变量
Location location;

void show_seat_array(int n);//展示n号激光厅的座位情况
void show_movie_file();//显示所有片场信息
#endif