#include"public.h"
#include"database.h"
#include"my_information"
void my_information(int *page,char *ID)//page  5:基本信息 6：历史记录7：我的收藏 8：稍后再看 9：我的动态 0：首页
{
	FILE* fp;
	USER* u1;
	int num = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();//库函数
	if ((fp = fopen("Database\\UserData.dat", "rb+")) == NULL)
	{
		printf("cannot open file UserData.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0L, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	for (i = 0; i < len; i++)
	{
		j = i * sizeof(USER);
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, j, SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(ID, u->ID) == 0)//账号匹配
		{
			u1 = u;
		}
	}
	draw_my_information(u1,ID);
	while (1)
	{
		if (MouseX > 110 && MouseX < 220 && MouseY>100 && MouseY < 150)//基本信息判定
		{
			if (mouse_press(110, 100, 220, 150) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(110, 100, 220, 150, LIGHTMAGENTA, LIGHTGRAY, 5);//color1为线颜色，color2为填充色
					num = 5;
				}
				continue;
			}
			else if (mouse_press(110, 100, 220, 150) == 1)
			{
				MouseS = 0;
				*page = 5;//现在默认5为我的基本信息页
				return;
			}
		}

		if (MouseX > 110 && MouseX < 220 && MouseY>200 && MouseY < 250)//历史记录判定
		{
			if (mouse_press(110, 200, 220, 250) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(110, 200, 220, 250, LIGHTMAGENTA, LIGHTGRAY, 6);//color1为线颜色，color2为填充色
					num = 6;
				}
				continue;
			}
			else if (mouse_press(110, 200, 220, 250) == 1)
			{
				MouseS = 0;
				*page = 6;//
				return;
			}
		}

		if (MouseX > 110 && MouseX < 220 && MouseY>300 && MouseY < 350)//我的收藏判定
		{
			if (mouse_press(110, 300, 220, 350) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(110, 300, 220, 350, LIGHTMAGENTA, LIGHTGRAY, 7);//color1为线颜色，color2为填充色
					num = 7;
				}
				continue;
			}
			else if (mouse_press(110, 300, 220, 350) == 1)
			{
				MouseS = 0;
				*page = 7;//
				return;
			}
		}

		if (MouseX > 420 && MouseX < 530 && MouseY>100 && MouseY < 150)//稍后再看判定
		{
			if (mouse_press(420, 100, 530, 150) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(420, 100, 530, 150, RED, RED, 2);//color1为线颜色，color2为填充色
					num = 2;
				}
				continue;
			}
			else if (mouse_press(420, 100, 530, 150) == 1)
			{
				MouseS = 0;
				*page = 8;//
				return;
			}
		}

		if (MouseX > 420 && MouseX < 530 && MouseY>200 && MouseY < 250)//我的动态判定
		{
			if (mouse_press(420, 200, 530, 250) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(420, 200, 530, 250, RED, RED, 5);//color1为线颜色，color2为填充色
					num = 3;
				}
				continue;
			}
			else if (mouse_press(420, 200, 530, 250) == 1)
			{
				MouseS = 0;
				*page = 9;//
				return;
			}
		}

		if (MouseX > 420 && MouseX < 530 && MouseY>300 && MouseY < 350)//返回首页判定
		{
			if (mouse_press(420, 300, 530, 350) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(420, 300, 530, 350, RED, RED, 5);//color1为线颜色，color2为填充色
					num = 4;
				}
				continue;
			}
			else if (mouse_press(420, 300, 530, 350) == 1)
			{
				MouseS = 0;
				*page = 0;//现在默认0首页
				return;
			}
		}



		if (num != 0)//点亮恢复
		{
			if (num==2||num == 3 || num == 4 || num == 5||num==6||num==7)
			{
				recoverbutton_login(num);
			}
			num = 0;
		}
		if (MouseS != 0)
			MouseS = 0;
	}

}
void draw_my_information(USER*u,char *ID)
{

	setbkcolor(WHITE);
	setcolor(LIGHTMAGENTA);

	rectangle(110, 100, 220, 150);//基本信息
	puthz(115, 115, "基本信息", 24, 4, LIGHTMAGENTA);

	rectangle(110, 200, 220, 250);//历史记录
	puthz(115, 215, "历史记录", 24, 4, LIGHTMAGENTA);

	rectangle(110, 300, 220, 350);//我的收藏
	puthz(115, 315, "我的收藏", 24, 4, LIGHTMAGENTA);


	setfillstyle(1, LIGHTMAGENTA);//稍后再看
	bar(420, 100, 530, 150);
	puthz(425, 115, "稍后再看", 24, 4, WHITE);

	bar(420, 200, 530, 250);//我的动态
	puthz(425, 215, "我的动态", 24, 4, WHITE);

	bar(420, 300, 530, 350);//返回
	puthz(425, 315, "返回首页", 24, 4, WHITE);



	
	setcolor(LIGHTMAGENTA);//blibli图案
	settextstyle(0, 0, 1);

	puthz(0, 0, "我的名称", 20, 23, LIGHTMAGENTA);
	puthz(0, 20, "我的账号", 20, 23, LIGHTMAGENTA);


	outtextxy(100, 0, u->users);//
	outtextxy(100, 20, u->ID);//
		

	

	
}
void lightbutton_login(int x, int y, int x1, int y1, int color1, int color2, int flag)//登录界面按钮点亮
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框
	switch (flag)
	{
	case 1:
		break;
	case 2:
		puthz(425, 115, "稍后再看", 24, 4, WHITE);
		break;
	case 3:
		puthz(425, 215, "我的动态", 24, 4, WHITE);
		break;
	case 4:
		puthz(425, 315, "返回首页", 24, 4, WHITE);
		break;
	case 5:
		puthz(115, 115, "基本信息", 24, 4, MAGENTA);
		break;
	case 6:
		puthz(115, 215, "历史记录", 24, 4, MAGENTA);
		break;
	case 7:
		puthz(115, 315, "我的收藏", 24, 4, MAGENTA);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}

}
void recoverbutton_login(int status)//恢复
{
	clrmous(MouseX, MouseY);
	switch (status)
	{
	case 3://稍后再看恢复
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(420, 100, 530, 150);
		puthz(425, 115, "稍后再看", 24, 4, WHITE);
		break;
	case 3://我的动态恢复
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(420, 200, 530, 250);
		puthz(425, 215, "我的动态", 24, 4, WHITE);
		break;
	case 3://登录框恢复
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(420, 300, 530, 350);
		puthz(425, 315, "返回首页", 24, 4, WHITE);
		break;
	case 5://基本信息恢复
		setcolor(LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		setfillstyle(1, WHITE);
		bar(110, 100, 220, 150);
		rectangle(110, 100, 220, 150);
		puthz(115, 115, "基本信息", 24, 4, LIGHTMAGENTA);
	case 6://历史记录恢复
		setcolor(LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		setfillstyle(1, WHITE);
		bar(110, 200, 220, 250);
		rectangle(110, 200, 220, 250);
		puthz(115, 125, "历史记录", 24, 4, LIGHTMAGENTA);
	case 7://我的收藏恢复
		setcolor(LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		setfillstyle(1, WHITE);
		bar(110, 300, 220, 350);
		rectangle(110, 300, 220, 350);
		puthz(115, 315, "我的收藏", 24, 4, LIGHTMAGENTA);
	}
}