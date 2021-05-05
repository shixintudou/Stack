#include"public.h"

void my_information(int* page, USER* u)//page  5:基本信息 6：历史记录7：我的收藏 8：稍后再看 9：我的动态 0：首页
{
	/*FILE* fp;
	USER* u1;*/
	int judge;
	int num = 0;
	judge = control_judge(u);
	if (judge == 0)
	{
		cpop(judge);
		*page = 1;
		return;
	}
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();//库函数
	
	draw_my_information(u);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 110 && MouseX < 220 && MouseY>100 && MouseY < 150)//基本信息判定
		{
			if (mouse_press(110, 100, 220, 150) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login_information(110, 100, 220, 150, LIGHTMAGENTA, LIGHTGRAY, 5);//color1为线颜色，color2为填充色
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
					lightbutton_login_information(110, 200, 220, 250, LIGHTMAGENTA, LIGHTGRAY, 6);//color1为线颜色，color2为填充色
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
					lightbutton_login_information(110, 300, 220, 350, LIGHTMAGENTA, LIGHTGRAY, 7);//color1为线颜色，color2为填充色
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
					lightbutton_login_information(420, 100, 530, 150, RED, RED, 2);//color1为线颜色，color2为填充色
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
					lightbutton_login_information(420, 200, 530, 250, RED, RED, 3);//color1为线颜色，color2为填充色
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
					lightbutton_login_information(420, 300, 530, 350, RED, RED, 4);//color1为线颜色，color2为填充色
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
				recoverbutton_login_information(num);
			}
			num = 0;
		}
		if (MouseS != 0)
			MouseS = 0;
	}

}
void draw_my_information(USER*u)
{

	setbkcolor(WHITE);
	setcolor(LIGHTMAGENTA);

	rectangle(110, 100, 220, 150);//基本信息
	puthz(115, 115, "基本信息", 24, 4+24, LIGHTMAGENTA);

	rectangle(110, 200, 220, 250);//历史记录
	puthz(115, 215, "历史记录", 24, 4+24, LIGHTMAGENTA);

	rectangle(110, 300, 220, 350);//我的收藏
	puthz(115, 315, "我的收藏", 24, 4+24, LIGHTMAGENTA);


	setfillstyle(1, LIGHTMAGENTA);//稍后再看
	bar(420, 100, 530, 150);
	puthz(425, 115, "稍后再看", 24, 4+24, WHITE);

	bar(420, 200, 530, 250);//我的动态
	puthz(425, 215, "我的动态", 24, 4+24, WHITE);

	bar(420, 300, 530, 350);//返回
	puthz(425, 315, "返回首页", 24, 4+24, WHITE);



	
	setcolor(LIGHTMAGENTA);//blibli图案
	settextstyle(0, 0, 3);

	/*puthz(200, 0, "", 24, 24+4, LIGHTMAGENTA);*/
	/*puthz(0, 24, "我的账号", 24, 24+4, LIGHTMAGENTA);

	
	outtextxy(110, 0, u->user);//*/
	outtextxy(220, 50, "bilibili");//
		

	

	
}
void lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag)//按钮点亮
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
		puthz(425, 115, "稍后再看", 24, 4+24, WHITE);
		break;
	case 3:
		puthz(425, 215, "我的动态", 24, 4+24, WHITE);
		break;
	case 4:
		puthz(425, 315, "返回首页", 24, 4+24, WHITE);
		break;
	case 5:
		puthz(115, 115, "基本信息", 24, 4+24, MAGENTA);
		break;
	case 6:
		puthz(115, 215, "历史记录", 24, 4+24, MAGENTA);
		break;
	case 7:
		puthz(115, 315, "我的收藏", 24, 4+24, MAGENTA);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}

}
void recoverbutton_login_information(int status)//恢复
{
	clrmous(MouseX, MouseY);
	switch (status)
	{
	case 2://稍后再看恢复
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(420, 100, 530, 150);
		puthz(425, 115, "稍后再看", 24, 28, WHITE);
		break;
	case 3://我的动态恢复
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(420, 200, 530, 250);
		puthz(425, 215, "我的动态", 24, 28, WHITE);
		break;
	case 4://登录框恢复
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(420, 300, 530, 350);
		puthz(425, 315, "返回首页", 24, 28, WHITE);
		break;
	case 5://基本信息恢复
		setcolor(LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		setfillstyle(1, WHITE);
		bar(110, 100, 220, 150);
		rectangle(110, 100, 220, 150);
		puthz(115, 115, "基本信息", 24, 28, LIGHTMAGENTA);
	case 6://历史记录恢复
		setcolor(LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		setfillstyle(1, WHITE);
		bar(110, 200, 220, 250);
		rectangle(110, 200, 220, 250);
		puthz(115, 215, "历史记录", 24, 28, LIGHTMAGENTA);
	case 7://我的收藏恢复
		setcolor(LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		setfillstyle(1, WHITE);
		bar(110, 300, 220, 350);
		rectangle(110, 300, 220, 350);
		puthz(115, 315, "我的收藏", 24, 28, LIGHTMAGENTA);
	}
}
int control_judge(USER* u)
{
	setfillstyle(1, LIGHTGRAY);
	bar(560, 1, 640, 23);          //遮盖
	if (strlen(u->user) == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void cpop(int i)
{
	clrmous(MouseX, MouseY);
	if (i == 0)
	{
		setfillstyle(SOLID_FILL, LIGHTMAGENTA);
		bar(180, 150, 460, 330);
		setfillstyle(SOLID_FILL, LIGHTMAGENTA);
		bar(200, 170, 440, 310);
		puthz(250, 200, "请先登录", 16, 20, WHITE);
		puthz(250, 260, "将在", 16, 20, WHITE);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(2, HORIZ_DIR, 6);
		setcolor(WHITE);
		outtextxy(295, 260, "3");
		puthz(310, 260, "秒后调转", 16, 20, WHITE);
		delay(1000);
		setfillstyle(SOLID_FILL, LIGHTMAGENTA);
		bar(295, 260, 308, 273);
		outtextxy(295, 260, "2");
		delay(1000);
		bar(295, 260, 308, 273);
		outtextxy(295, 260, "1");
		delay(1000);
	}
}