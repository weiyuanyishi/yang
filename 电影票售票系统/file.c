#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mainControl.h"
#include "user.h"
#include "administrator.h"
#include "menu.h"
#include "file.h"
#include "movie.h"
//读用户
int read_user_file(information1 *user)
{
	//fopen_s函数用法：
	//FILE *fp;
	//fopen_s(&fp,"文件路径","打开方式");
	//fopen_s函数的返回值与fopen不同。正确打开返回0，不正确返回非0。
	//要定义一个变量err来接收fopen_s函数的返回值，即：
	//errno_t err;
	//通过判断err的值是否为0，可以知道打开文件成功与否
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, "D:\\movieFile\\user_register_file.txt", "rb")) != 0)
	{
		printf("无法打开此文件！\n");
		exit(0);
	}
	int i=0;
	while (!feof(fp))
	{
		fread(&user[i], sizeof(information1), 1, fp);
		i++;
	}
	fclose(fp);
	return i-1;
}
//读管理员
void read_administrator_file(information2 *administrator)
{
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, "D:\\movieFile\\administrator_register_file.txt", "rb")) != 0)
	{
		printf("无法打开此文件！\n");
		exit(0);
	}
	int i = 0;
	while (!feof(fp))
	{
		fread(&administrator[i], sizeof(information2), 1, fp);
		i++;
	}
	fclose(fp);
}
//读电影
int read_movie_file(Movie *movie)
{
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, "D:\\movieFile\\movie_information_file.txt", "rb")) != 0)
	{
		printf("无法打开此文件！\n");
		exit(0);
	}
	int i = 0;
	while (!feof(fp))
	{
		fread(&movie[i], sizeof(Movie), 1, fp);
		i++;
	}
	fclose(fp);
	return i - 1;
}
//读座位
void read_seat_file(Seat *seat)
{
	FILE* fp;
	errno_t err;
	//0厅
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall0.txt", "rb")) != 0)
	{
		printf("无法打开此文件！\n");
		exit(0);
	}
	fread(&seat[0], sizeof(Seat), 1, fp);
	fclose(fp);
	//1厅
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall1.txt", "rb")) != 0)
	{
		printf("无法打开此文件！\n");
		exit(0);
	}
	fread(&seat[1], sizeof(Seat), 1, fp);
	fclose(fp);
	//2厅
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall2.txt", "rb")) != 0)
	{
		printf("无法打开此文件！\n");
		exit(0);
	}
	fread(&seat[2], sizeof(Seat), 1, fp);
	fclose(fp);
	//3厅
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall3.txt", "rb")) != 0)
	{
		printf("无法打开此文件！\n");
		exit(0);
	}
	fread(&seat[3], sizeof(Seat), 1, fp);
	fclose(fp);
	//4厅
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall4.txt", "rb")) != 0)
	{
		printf("无法打开此文件！\n");
		exit(0);
	}
	fread(&seat[4], sizeof(Seat), 1, fp);
	fclose(fp);
}
//存用户
void save_user_file(information1 *user,int num_user)
{
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, "D:\\movieFile\\user_register_file.txt", "wb")) != 0)
	{
		printf("无法打开此文件！\n");
		exit(0);
	}
	fwrite(user, sizeof(information1), num_user, fp);
	fclose(fp);
}
//存管理员
void save_administrator_file(information2 *administrator, int num_administrator)
{
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, "D:\\movieFile\\administrator_register_file.txt", "wb")) != 0)
	{
		printf("无法打开此文件！\n");
		exit(0);
	}
	fwrite(administrator, sizeof(information2), num_administrator, fp);
	fclose(fp);
}
//存电影
void save_movie_file(Movie *movie,int num_movie)
{
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, "D:\\movieFile\\movie_information_file.txt", "wb")) != 0)
	{
		printf("无法打开此文件！\n");
		exit(0);
	}
	fwrite(movie, sizeof(Movie), num_movie, fp);
	fclose(fp);
}
//存座位
void save_seat_file()
{
	FILE* fp;
	errno_t err;
	//0厅
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall0.txt", "wb")) != 0)
	{
		printf("无法打开此文件！\n");
		exit(0);
	}
	fwrite(&seat[0], sizeof(Seat), 1, fp);
	fclose(fp);
	//1厅
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall1.txt", "wb")) != 0)
	{
		printf("无法打开此文件！\n");
		exit(0);
	}
	fwrite(&seat[1], sizeof(Seat), 1, fp);
	fclose(fp);
	//2厅
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall2.txt", "wb")) != 0)
	{
		printf("无法打开此文件！\n");
		exit(0);
	}
	fwrite(&seat[2], sizeof(Seat), 1, fp);
	fclose(fp);
	//3厅
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall3.txt", "wb")) != 0)
	{
		printf("无法打开此文件！\n");
		exit(0);
	}
	fwrite(&seat[3], sizeof(Seat), 1, fp);
	fclose(fp);
	//4厅
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall4.txt", "wb")) != 0)
	{
		printf("无法打开此文件！\n");
		exit(0);
	}
	fwrite(&seat[4], sizeof(Seat), 1, fp);
	fclose(fp);
}
//追加注册用户
void add_user_register_file(information1 *user)
{
	//fopen_s函数用法：
	//FILE *fp;
	//fopen_s(&fp,"文件路径","打开方式");
	//fopen_s函数的返回值与fopen不同。正确打开返回0，不正确返回非0。
	//要定义一个变量err来接收fopen_s函数的返回值，即：
	//errno_t err;
	//通过判断err的值是否为0，可以知道打开文件成功与否
	FILE* fp;
	errno_t err;
	//追加二进制文件用ab
	if ((err = fopen_s(&fp, "D:\\movieFile\\user_register_file.txt", "ab")) != 0)
	{
		printf("无法打开此文件！\n");
		exit(0);
	}
	fwrite(user, sizeof(information1), 1, fp);
	fclose(fp);
}
