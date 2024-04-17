#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mainControl.h"
#include "user.h"
#include "administrator.h"
#include "menu.h"
#include "file.h"
#include "movie.h"
//�������ܣ�����������ȡ�����ļ���Ϣ�������һ��
//������������
//��������ֵ������0
int main()
{
	//���ö�ȡ�ļ�����
	run_read_file();
	//��ʼ����
	run_identity_choose();
	//���ñ����ļ�����
	run_save_file();

	return 0;
}
//���ļ�
void run_read_file()
{
	//�򿪶�Ӧ�ļ���ȡ��ע���û�����Ϣ���û���num_user
	num_user = read_user_file(user);
	//�򿪶�Ӧ�ļ���ȡ����Ա����Ϣ
	read_administrator_file(administrator);
	//�򿪶�Ӧ�ļ���ȡ��Ӱ����Ϣ����Ƭ����Ӱ��
	num_movie = read_movie_file(movie);
	//�򿪶�Ӧ�ļ���ȡ��ӳ����λ��Ϣ
	read_seat_file(seat);
}
//���ļ�
void run_save_file()
{
	//���û�
	save_user_file(user, num_user);
	//�����Ա
	save_administrator_file(administrator, num_administrator);
	//���Ӱ
	save_movie_file(movie, num_movie);
	//����λ
	save_seat_file();
}
//�������ܣ����ѡ����
//������������
//��������ֵ������0
void run_identity_choose()
{
	//��choice��������ֵѡ��ͬ��ݵ�¼
	int choice;
	do
	{
		//�ٻ�����˵�
		menu();
		printf("��ѡ��");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			//�����û�ѡ�����
			run_user_choose();
			break;
		case 2:
			//�������Ա��¼����
			run_administrator_enter();
			break;
		case 0:
			//�˳�ϵͳ
			break;
		default:
			printf("��������������ѡ��\n");
		}
	} while (1);
}
//�������ܣ��û�ѡ��ע����¼
//����������
//��������ֵ����
void run_user_choose()
{
	int choice;
	do
	{
		menuUser_choose();
		printf("��ѡ��");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			//�û�ע��
			run_user_register();
			break;
		case 2:
			//�û���¼
			run_user_enter();
			break;
		case 0:
			//�����ϼ��˵�
			main();
			break;
		default:
			printf("��������밴Ҫ������ѡ��\n");
		}
	} while (1);
}
//�������ܣ��û�ע�ắ��
//����������
//��������ֵ����
void run_user_register()
{
	int choice, user_number;
	//ע��,��choice����ע��ɹ���ʧ�ܵĽ��
	choice = user_register();
	user_number = choice;
	switch (choice)
	{
	case 0:
		//ע��ʧ�ܣ�ԭ��ֻ�����û����Ѵ��ڣ�
		printf("���û����Ѵ��ڣ�\n");
		//����ע��ʧ�ܺ���
		run_user_fail_register();
		break;
	case 1:
		//ע��ɹ�
		printf("����ע��ɹ���");
		//����ע��ɹ�����
		run_user_succeed_register();
		break;
	}
}
//�������ܣ��û�ע��ʧ�ܺ���
//����������
//��������ֵ��
void run_user_fail_register()
{
	int choice;
	do
	{
		//�ٻ�ע��ʧ�ܲ˵�
		menuUser_fregister();
		printf("��ѡ��");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			//����ע��
			run_user_register();
			break;
		case 0:
			//�����û�ѡ����뷽ʽ�˵�
			run_user_choose();
			break;
		default:
			printf("��������밴Ҫ������ѡ��\n");
		}
	} while (1);
}
//�������ܣ��û�ע��ɹ�����
//����������
//��������ֵ��
void run_user_succeed_register()
{
	int choice;
	do
	{
		//�ٻ�ע��ɹ��˵�
		menuUser_sregister();
		printf("��ѡ��");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			//��¼
			run_user_enter();
			break;
		case 0:
			//�����û�ѡ����뷽ʽ�˵�
			run_user_choose();
			break;
		default:
			printf("��������밴Ҫ������ѡ��\n");
		}
	} while (1);
}
//�������ܣ��û���¼����
//����������
//��������ֵ����
void run_user_enter()
{
	int choice;
	choice = user_enter();
	switch (choice)
	{
	case 1:
		printf("��¼�ɹ���");
		//�����û�ѡ���ܺ���
		run_user_choose_function();
		break;
	case 0:
		printf("�����û�������������\n");
		//�����û���¼ʧ�ܺ���
		run_user_fail_enter();
		break;
	}
}
//�������ܣ��û���¼ʧ�ܺ���
//����������
//��������ֵ����
void run_user_fail_enter()
{
	int choice;
	do
	{
		//�ٻ��û���¼ʧ�ܲ˵�
		menuUser_fenter();
		printf("��ѡ��");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			//���µ�¼
			run_user_enter();
			break;
		case 0:
			//�����ϼ��˵�
			run_user_choose();
			break;
		default:
			printf("��������밴Ҫ������ѡ��\n");
		}
	} while (1);
}
//�������ܣ��û�ѡ���ܺ���
//����������
//��������ֵ����
void run_user_choose_function()
{
	int choice;
	do
	{
		menuUser_function();
		printf("��ѡ��");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			//���Ƭ����Ϣ
			run_user_function1();
			break;
		case 2:
			//�鿴��ӳ����Ʊ���
			run_user_function2();
			break;
		case 3:
			//ѡ����Ʊ
			run_user_function3();
			break;
		case 4:
			//��Ʊ
			run_user_function4();
			break;
		case 5:
			//�ر�ϵͳ
			run_user_function5();
			break;
		case 0:
			//�����ϼ��˵�
			run_user_choose();
			break;
		default:
			printf("��������밴Ҫ������ѡ��\n");
		}
	} while (1);
}
//�û�����1�����Ƭ����Ϣ
void run_user_function1()
{
	user_function1();
	run_user_choose_function();
}
//�û�����2���鿴��ӳ����Ʊ���
void run_user_function2()
{
	user_function2();
	run_user_choose_function();
}
//�û�����3��ѡ����Ʊ
void run_user_function3(user_movie)
{
	user_function3(user_movie);
	run_user_choose_function();
}
//�û�����4����Ʊ
void run_user_function4(user_movie)
{
	user_function4(user_movie);
	run_user_choose_function();
}
//�û�����5���ر�ϵͳ
void run_user_function5()
{
	printf("��л����ʹ�ã��ټ���");
}
//�������ܣ�����Ա��¼����
//����������
//��������ֵ����
void run_administrator_enter()
{
	int choice;
	choice = administrator_enter();
	switch (choice)
	{
	case 1:
		printf("��¼�ɹ���");
		//�������Աѡ���ܺ���
		run_user_choose_function();
		break;
	case 0:
		printf("�����û�������������\n");
		//�������Ա��¼ʧ�ܺ���
		run_administrator_fail_enter();
		break;
	}
}
//����Ա��¼ʧ�ܺ���
void run_administrator_fail_enter()
{
	int choice;
	do
	{
		//�ٻ�����Ա��¼ʧ�ܲ˵�
		menuUser_fenter();
		printf("��ѡ��");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			//���µ�¼
			run_administrator_enter();
			break;
		case 0:
			//�����ϼ��˵�
			run_identity_choose();
			break;
		default:
			printf("��������밴Ҫ������ѡ��\n");
		}
	} while (1);
}
//����Աѡ���ܺ���
void run_administrator_choose_function()
{
	int choice;
	do
	{
		menuAdministrator_function();
		printf("��ѡ��");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			//���Ƭ����Ϣ
			run_administrator_function1();
			break;
		case 2:
			//���Ƭ����Ϣ
			run_administrator_function2();
			break;
		case 3:
			//�޸�Ƭ����Ϣ
			run_administrator_function3();
			break;
		case 4:
			//ɾ��Ƭ����Ϣ
			run_administrator_function4();
			break;
		case 5:
			//ͳ��ĳ����Ӱ����Ʊ��
			run_administrator_function5();
			break;
		case 6:
			//Ʊ������
			run_administrator_function6();
			break;
		case 7:
			//�ر�ϵͳ
			run_administrator_function7();
			break;
		case 0:
			//�����ϼ��˵�
			run_administrator_choose();
			break;
		default:
			printf("��������밴Ҫ������ѡ��\n");
		}
	} while (1);
}
//����Ա����1�����Ƭ����Ϣ
void run_administrator_function1()
{
	administrator_function1();
	run_administrator_choose_function();
}
//����Ա����2�����Ƭ����Ϣ
void run_administrator_function2()
{
	administrator_function2();
	run_administrator_choose_function();
}
//����Ա����3���޸�Ƭ����Ϣ
void run_administrator_function3()
{
	int j, choice;
	do
	{
		printf("������Ҫ�޸ĵ�Ӱ�ı�ţ�");
		scanf_s("%d", &j);
		if (j >= 0 && j < num_movie)
			break;
		else
			printf("��������밴Ҫ������ѡ��\n");
	} while (1);
	printf("��ѡ��Ӱ����Ϣ���£�\n");
	printf("%9d%28s%20s%14s%10d%8d%8d%6d\n",
		movie[j].set_number, movie[j].movie_title, movie[j].show_time, movie[j].video_hall, movie[j].num_seat, movie[j].sold_ticket, movie[j].surplus_ticket, movie[j].ticket_rate);
	do
	{
		menuAdministrator_change_function();
		printf("ѡ���޸���Ŀ��\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			administrator_function3(j, choice);
			printf("���޸�");
		case 0:
			printf("�޸�����ɣ�");
			break;
		default:
			printf("��������밴Ҫ������ѡ��\n");
		}
	} while (1);
	run_administrator_choose_function();
}
//����Ա����4��ɾ��Ƭ����Ϣ
void run_administrator_function4()
{
	int j;
	do
	{
		printf("������Ҫɾ����Ӱ�ı�ţ�");
		scanf_s("%d", &j);
		if (j >= 0 && j < num_movie)
			break;
		else
			printf("��������밴Ҫ������ѡ��\n");
	} while (1);
	printf("��ѡ��Ӱ����Ϣ���£�\n");
	printf("%9d%28s%20s%14s%10d%8d%8d%6d\n",
		movie[j].set_number, movie[j].movie_title, movie[j].show_time, movie[j].video_hall, movie[j].num_seat, movie[j].sold_ticket, movie[j].surplus_ticket, movie[j].ticket_rate);
	administrator_function4(j);
	printf("��ɾ����ѡ��ӰƬ����Ϣ��");
	run_administrator_choose_function();
}
//����Ա����5��ͳ��ĳ����Ӱ����Ʊ��
void run_administrator_function5()
{
	//�ȵ��ù���Ա����5������������е�Ӱ��Ʊ��
	administrator_function5();
	int j;
	do
	{
		printf("������Ҫ�鿴Ʊ����Ӱ�ı�ţ�");
		scanf_s("%d", &j);
		if (j >= 0 && j < num_movie)
			break;
		else
			printf("��������밴Ҫ������ѡ��\n");
	} while (1);
	printf("��ѡ��Ӱ���յ�Ʊ��Ϊ%d��",box_office[j]);
	run_administrator_choose_function();
}
//����Ա����6��Ʊ������
void run_administrator_function6()
{
	int choice;
	do
	{
		menuAdministrator_choose_sort();
		printf("��ѡ������ʽ��");
		scanf_s("%d", &choice);
		if (choice >= 1 && choice <= 2)
			break;
		else
			printf("��������밴Ҫ������ѡ��\n");
	} while (1);
	administrator_function6(choice);
	run_administrator_choose_function();
}
//����Ա����7���ر�ϵͳ
void run_administrator_function7()
{
	administrator_function7();
}