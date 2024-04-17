#include <stdio.h>
#include <string.h>



typedef struct User_information
{
	char account_number[20];
	char password[3];
}information1;

typedef struct Administrator_information
{
	char name[20];
	char password[6];
}information2;

information1 user[100] = { {"zhangsan","123"},{"lisi","456"},{"wangwu","789"} };
information2 administrator[3] = { {"liuche", "040910"},{"qinxinyu","050315"},{"zhangyang","050901"} };

void First_step();

void menuUser()
{
	int x, i;
	char temporary_number[20];
	information1 input;
	printf("-------------------------\n");
	printf("$ �û���¼ $\n");
	printf("�Ƿ��Ѿ�ע���˺ţ�\n");
	printf("��1����ע��\n��2��δע��\n");
	printf("��ѡ��");
	scanf_s("%d", &x);
	while (x < 1 || x>2)
	{
		printf("�������������Ҫ������");
		printf("�Ƿ��Ѿ�ע���˺ţ�");
		printf("��1����ע��\n��2��δע��");
		scanf_s("%d", &x);
	}
	if (x == 1)
	{
		printf("���¼��\n");
		printf("�û�����");
		gets(input.account_number);
		printf("���룺");
		gets(input.password);
	}
	else
	{
		printf("��ע�᣺\n");
		printf("�������û�����");
		gets(input.account_number);
		for (i = 0;i < 3;i++)
		{
			if (strcmp(input.account_number, user[i].account_number) == 0)
			{
				printf("���û����Ѵ��ڣ����������ã�");
				gets(temporary_number);
				strcpy_s(input.account_number,20,temporary_number);
			}
		}
	}
}

void menuAdministrator()
{
	int i, x = 0, y;
	information2 input;
	printf("-------------------------\n");
	printf("$ ����Ա��¼ $\n");
	printf("������");
	scanf_s("%s",input.name,sizeof(input.name));
	printf("���룺");
	scanf_s("%s",input.password,sizeof(input.password));
	printf("%s",input.password);
	for (i = 0;i < 3;i++)
		if (strcmp(input.name , administrator[i].name)==0 && strcmp(input.password , administrator[i].password)==0)
			x = 1;
	if (x == 0)
	{
		printf("��Ϣ������ѡ���Ƿ���������\n");
		printf("��1����������\n��2���˻ص���һ��\n");
		printf("��ѡ��");
		scanf_s("%d", &y);
		if (y == 1)
			Administrator();
		else
			if (y == 2)
				menu();
	}
	else
	{

	}
}
void menu()
{
	int x;
	printf("-------------------------\n");
	printf("$ ��ӰԺ��Ʊϵͳ $\n  ��1���û���¼\n  ��2������Ա��¼\n  ��0���ر�ϵͳ\n");
	printf("-------------------------\n");
	printf("��ѡ��");
	scanf_s("%d", &x);
	switch (x)
	{
	case 1:
		User();
		break;
	case 2:
		Administrator();
		break;
	case 0:
		printf("�ر�ϵͳ");
		break;
	default:
		printf("��������������ѡ��\n");
		menu();
	}
}
int main()
{
	menu();
}