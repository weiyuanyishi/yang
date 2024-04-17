#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mainControl.h"
#include "user.h"
#include "administrator.h"
#include "menu.h"
#include "file.h"
#include "movie.h"
//���û�
int read_user_file(information1 *user)
{
	//fopen_s�����÷���
	//FILE *fp;
	//fopen_s(&fp,"�ļ�·��","�򿪷�ʽ");
	//fopen_s�����ķ���ֵ��fopen��ͬ����ȷ�򿪷���0������ȷ���ط�0��
	//Ҫ����һ������err������fopen_s�����ķ���ֵ������
	//errno_t err;
	//ͨ���ж�err��ֵ�Ƿ�Ϊ0������֪�����ļ��ɹ����
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, "D:\\movieFile\\user_register_file.txt", "rb")) != 0)
	{
		printf("�޷��򿪴��ļ���\n");
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
//������Ա
void read_administrator_file(information2 *administrator)
{
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, "D:\\movieFile\\administrator_register_file.txt", "rb")) != 0)
	{
		printf("�޷��򿪴��ļ���\n");
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
//����Ӱ
int read_movie_file(Movie *movie)
{
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, "D:\\movieFile\\movie_information_file.txt", "rb")) != 0)
	{
		printf("�޷��򿪴��ļ���\n");
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
//����λ
void read_seat_file(Seat *seat)
{
	FILE* fp;
	errno_t err;
	//0��
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall0.txt", "rb")) != 0)
	{
		printf("�޷��򿪴��ļ���\n");
		exit(0);
	}
	fread(&seat[0], sizeof(Seat), 1, fp);
	fclose(fp);
	//1��
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall1.txt", "rb")) != 0)
	{
		printf("�޷��򿪴��ļ���\n");
		exit(0);
	}
	fread(&seat[1], sizeof(Seat), 1, fp);
	fclose(fp);
	//2��
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall2.txt", "rb")) != 0)
	{
		printf("�޷��򿪴��ļ���\n");
		exit(0);
	}
	fread(&seat[2], sizeof(Seat), 1, fp);
	fclose(fp);
	//3��
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall3.txt", "rb")) != 0)
	{
		printf("�޷��򿪴��ļ���\n");
		exit(0);
	}
	fread(&seat[3], sizeof(Seat), 1, fp);
	fclose(fp);
	//4��
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall4.txt", "rb")) != 0)
	{
		printf("�޷��򿪴��ļ���\n");
		exit(0);
	}
	fread(&seat[4], sizeof(Seat), 1, fp);
	fclose(fp);
}
//���û�
void save_user_file(information1 *user,int num_user)
{
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, "D:\\movieFile\\user_register_file.txt", "wb")) != 0)
	{
		printf("�޷��򿪴��ļ���\n");
		exit(0);
	}
	fwrite(user, sizeof(information1), num_user, fp);
	fclose(fp);
}
//�����Ա
void save_administrator_file(information2 *administrator, int num_administrator)
{
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, "D:\\movieFile\\administrator_register_file.txt", "wb")) != 0)
	{
		printf("�޷��򿪴��ļ���\n");
		exit(0);
	}
	fwrite(administrator, sizeof(information2), num_administrator, fp);
	fclose(fp);
}
//���Ӱ
void save_movie_file(Movie *movie,int num_movie)
{
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, "D:\\movieFile\\movie_information_file.txt", "wb")) != 0)
	{
		printf("�޷��򿪴��ļ���\n");
		exit(0);
	}
	fwrite(movie, sizeof(Movie), num_movie, fp);
	fclose(fp);
}
//����λ
void save_seat_file()
{
	FILE* fp;
	errno_t err;
	//0��
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall0.txt", "wb")) != 0)
	{
		printf("�޷��򿪴��ļ���\n");
		exit(0);
	}
	fwrite(&seat[0], sizeof(Seat), 1, fp);
	fclose(fp);
	//1��
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall1.txt", "wb")) != 0)
	{
		printf("�޷��򿪴��ļ���\n");
		exit(0);
	}
	fwrite(&seat[1], sizeof(Seat), 1, fp);
	fclose(fp);
	//2��
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall2.txt", "wb")) != 0)
	{
		printf("�޷��򿪴��ļ���\n");
		exit(0);
	}
	fwrite(&seat[2], sizeof(Seat), 1, fp);
	fclose(fp);
	//3��
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall3.txt", "wb")) != 0)
	{
		printf("�޷��򿪴��ļ���\n");
		exit(0);
	}
	fwrite(&seat[3], sizeof(Seat), 1, fp);
	fclose(fp);
	//4��
	if ((err = fopen_s(&fp, "D:\\movieFile\\video_hall_seat\\hall4.txt", "wb")) != 0)
	{
		printf("�޷��򿪴��ļ���\n");
		exit(0);
	}
	fwrite(&seat[4], sizeof(Seat), 1, fp);
	fclose(fp);
}
//׷��ע���û�
void add_user_register_file(information1 *user)
{
	//fopen_s�����÷���
	//FILE *fp;
	//fopen_s(&fp,"�ļ�·��","�򿪷�ʽ");
	//fopen_s�����ķ���ֵ��fopen��ͬ����ȷ�򿪷���0������ȷ���ط�0��
	//Ҫ����һ������err������fopen_s�����ķ���ֵ������
	//errno_t err;
	//ͨ���ж�err��ֵ�Ƿ�Ϊ0������֪�����ļ��ɹ����
	FILE* fp;
	errno_t err;
	//׷�Ӷ������ļ���ab
	if ((err = fopen_s(&fp, "D:\\movieFile\\user_register_file.txt", "ab")) != 0)
	{
		printf("�޷��򿪴��ļ���\n");
		exit(0);
	}
	fwrite(user, sizeof(information1), 1, fp);
	fclose(fp);
}
