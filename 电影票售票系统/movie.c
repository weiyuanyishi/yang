#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mainControl.h"
#include "user.h"
#include "administrator.h"
#include "menu.h"
#include "file.h"
#include "movie.h"

//��ʾ��λ
void show_seat_array(int n)
{
	int i, j, k = 0;
	for (i = 0;i < 9;i++)
		for (j = 0;j < 9;j++)
		{
			printf("%c", seat[n].seat_array[i][j]);
			k++;
			if (k % 9 == 0)
				printf("\n");
		}
	printf("���ۣ�$   δ�ۣ�-");
}
//��ʾƬ����Ϣ
void show_movie_file()
{
	int j;
	printf("%9s%28s%20s%14s%10s%8s%8s%6s\n",
		"��Ӱ���", "Ƭ��", "��ӳʱ��", "��ӳ��", "��λ����", "����", "��Ʊ", "Ʊ��");
	for (j = 0;j < num_movie;j++)
	{
		//%3d%10s%6s%20s%6s%6d%4d%4d%6d
		printf("%9d%28s%20s%14s%10d%8d%8d%6d\n",
			movie[j].set_number, movie[j].movie_title, movie[j].show_time, movie[j].video_hall, movie[j].num_seat, movie[j].sold_ticket, movie[j].surplus_ticket, movie[j].ticket_rate);
	}
}