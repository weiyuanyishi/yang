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
	printf("$ 用户登录 $\n");
	printf("是否已经注册账号：\n");
	printf("【1】已注册\n【2】未注册\n");
	printf("请选择：");
	scanf_s("%d", &x);
	while (x < 1 || x>2)
	{
		printf("输入有误，请根据要求输入");
		printf("是否已经注册账号：");
		printf("【1】已注册\n【2】未注册");
		scanf_s("%d", &x);
	}
	if (x == 1)
	{
		printf("请登录：\n");
		printf("用户名：");
		gets(input.account_number);
		printf("密码：");
		gets(input.password);
	}
	else
	{
		printf("请注册：\n");
		printf("请设置用户名：");
		gets(input.account_number);
		for (i = 0;i < 3;i++)
		{
			if (strcmp(input.account_number, user[i].account_number) == 0)
			{
				printf("该用户名已存在，请重新设置：");
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
	printf("$ 管理员登录 $\n");
	printf("姓名：");
	scanf_s("%s",input.name,sizeof(input.name));
	printf("密码：");
	scanf_s("%s",input.password,sizeof(input.password));
	printf("%s",input.password);
	for (i = 0;i < 3;i++)
		if (strcmp(input.name , administrator[i].name)==0 && strcmp(input.password , administrator[i].password)==0)
			x = 1;
	if (x == 0)
	{
		printf("信息错误，请选择是否重新输入\n");
		printf("【1】重新输入\n【2】退回到上一步\n");
		printf("请选择：");
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
	printf("$ 电影院售票系统 $\n  【1】用户登录\n  【2】管理员登录\n  【0】关闭系统\n");
	printf("-------------------------\n");
	printf("请选择：");
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
		printf("关闭系统");
		break;
	default:
		printf("输入有误，请重新选择\n");
		menu();
	}
}
int main()
{
	menu();
}