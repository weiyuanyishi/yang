#ifndef _MAINCONTROL
#define _MAINCONTROL

#include "user.h"
#include "administrator.h"
#include "menu.h"
#include "file.h"
#include "movie.h"

void run_read_file();//���ļ�
void run_save_file();//���ļ�
void run_identity_choose();//ѡ�����
void run_user_choose();//�û�ѡ��ע����¼
void run_user_register();//�û�ע�ắ��
void run_user_fail_register();//�û�ע��ʧ�ܺ���
void run_user_succeed_register();//�û�ע��ɹ�����
void run_user_enter();//�û���¼����
void run_user_fail_enter();//�û���¼ʧ�ܺ��� 
void run_user_choose_function();//�û�ѡ���ܺ���
void run_user_function1();//�û�����1�����Ƭ����Ϣ
void run_user_function2();//�û�����2���鿴��ӳ����Ʊ���
void run_user_function3(user_movie);//�û�����3��ѡ����Ʊ
void run_user_function4(user_movie);//�û�����4����Ʊ
void run_user_function5();//�û�����5���ر�ϵͳ
void run_administrator_enter();//����Ա��¼����
void run_administrator_fail_enter();//����Ա��¼ʧ�ܺ���
void run_administrator_choose_function();//����Աѡ���ܺ���
void run_administrator_function1();//����Ա����1�����Ƭ����Ϣ
void run_administrator_function2();//����Ա����2�����Ƭ����Ϣ
void run_administrator_function3();//����Ա����3���޸�Ƭ����Ϣ
void run_administrator_function4();//����Ա����4��ɾ��Ƭ����Ϣ
void run_administrator_function5();//����Ա����5��ͳ��ĳ����Ӱ����Ʊ��
void run_administrator_function6();//����Ա����6��Ʊ������
void run_administrator_function7();//����Ա����7���ر�ϵͳ
#endif