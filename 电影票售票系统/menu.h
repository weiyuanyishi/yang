#ifndef _MENU
#define _MENU

#include "mainControl.h"
#include "user.h"
#include "administrator.h"
#include "file.h"
#include "movie.h"

void menu();//����˵�����
void menuUser_choose();//�û�ѡ����뷽ʽ�˵�����
void menuUser_fregister();//�û�ע��ʧ�ܲ˵�����
void menuUser_sregister();//�û�ע��ɹ��˵�����
void menuUser_fenter();//�û���¼ʧ�ܲ˵�����
void menuUser_function();//�û����ܲ˵�����
void menuAdministrator_fail_enter();//����Ա��¼ʧ�ܲ˵�
void menuAdministrator_function();//����Ա���ܲ˵�����
void menuAdministrator_change_function();//����Ա�޸ĵ�Ӱ��Ϣѡ��˵�
void menuAdministrator_choose_sort();//����Աѡ������ʽ�˵�
#endif