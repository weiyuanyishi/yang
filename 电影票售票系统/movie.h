#ifndef _MOVIE
#define _MOVIE

#include "mainControl.h"
#include "user.h"
#include "administrator.h"
#include "menu.h"
#include "file.h"

//��Ƭ����Ӱ��
int num_movie;

//��¼��ӰƱ��
typedef struct box_office
{
	int movie_number;
	int money;
}box;

box box_office[20];

//����һ�����ڼ�¼��Ӱ��Ϣ�Ľṹ��
typedef struct Movie
{
	int set_number;//��Ӱ���
	char movie_title[40];//Ƭ��
	char show_time[20];//��ӳʱ��
	char video_hall[20];//��ӳ����
	int video_hall_number;//��ӳ�����
	int num_seat;//��λ����
	int sold_ticket;//����
	int surplus_ticket;//��Ʊ
	int ticket_rate;//Ʊ��
}Movie;

//����һ��Movie�������������¼������Ƭ����Ӱ����Ϣ
Movie movie[20];/*= {
	{0,"����������������","2024-05-01^09:30","2�ż�����",2,64,8,56,39},8
	{1,"��˹����ս���2���۹�����","2024-05-01^16:25","1�ż�����",1,64,3,61,36},3
	{2,"������è4","2024-05-01^17:05","0�ż�����",0,64,5,59,33},5
	{3,"�ܴ�������","2024-05-01^16:35","4�ż�����",4,64,6,58,47},6
	{4,"ɳ��2","2024-05-01^20:00","3�ż�����",3,64,10,54,55}10
};*/ 

//����һ�����ڼ�¼��λ�Ľṹ��
typedef struct Seat
{
	char seat_array[9][9];
}Seat;

//����һ��Seat���͵������¼5����ӳ������λ
Seat seat[5];

//����һ�������ж�λ��λ�Ľṹ�����
typedef struct Location
{
	int movie_number;
	int video_hall_number;
	int x;
	int y;
}Location;

//����һ����¼�û���ѡ��λ�ı���
Location location;

void show_seat_array(int n);//չʾn�ż���������λ���
void show_movie_file();//��ʾ����Ƭ����Ϣ
#endif