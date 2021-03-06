#include"public.h"
#include"login.h"
#include"lgfunc.h"
void login_main(int *page, USER *u)//登录界面主控函数
{
	int num = 0;
	int state1 = 0, state2 = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawlog();
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 240 && MouseX < 240 + 315 && MouseY>150 && MouseY < 180)//账号框判定
		{
			if (mouse_press(240, 150, 240 + 315, 180) == 2)
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)//防止被重复标亮
				{
					lightbutton_login(240, 150, 240 + 315, 180, DARKGRAY, LIGHTGRAY, 1);//color1为线颜色，color2为填充色
					num = 1;
				}
				continue;
			}
			else if (mouse_press(240, 150, 240 + 315, 180) == 1)//用户名框点击
			{
				MouseS = 0;
				lightbutton_login(240, 150, 240 + 315, 180, LIGHTRED, LIGHTGRAY, 1);
				u->user[0] = '\0';
				inputadmin(u->user, 240, 150, 12, LIGHTGRAY);
				//输入函数
				if (strlen(u->user) != 0)
					state1 = 1;
				else
					state1 = 0;
				continue;
			}
		}
		if (MouseX > 240 && MouseX < 240 + 315 && MouseY>190 && MouseY < 220)//密码框判定
		{
			if (mouse_press(240, 190, 240 + 315, 220) == 2)
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)//防止被重复标亮
				{
					lightbutton_login(240, 190, 240 + 315, 220, DARKGRAY, LIGHTGRAY, 1);//color1为线颜色，color2为填充色
					num = 2;
				}
				continue;
			}
			else if (mouse_press(240, 190, 240 + 315, 220) == 1)//密码框点击
			{
				MouseS = 0;
				lightbutton_login(240, 190, 240 + 315, 220, LIGHTRED, LIGHTGRAY, 1);
				u->password[0] = '\0';
				inputpassword(u->password, 240, 190, 16, LIGHTGRAY);
				//输入函数
				if (strlen(u->password) != 0)
					state2 = 1;
				else
					state2 = 0;
				continue;
			}
		}
		if (MouseX > 420 && MouseX < 530 && MouseY>300 && MouseY < 350)//登录框判定
		{
			if (mouse_press(420, 300, 530, 350) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(420, 300, 530, 350, RED, RED, 2);//color1为线颜色，color2为填充色
					num = 3;
				}
				continue;
			}
			else if (mouse_press(420, 300, 530, 350) == 1)
			{
				MouseS = 0;
				if (login_complete(u->user, u->password))     //信息正确
				{
					
					* page = 1;
					return;
				}
				else
				{
					continue;
				}
				//检测登录状态函数
			}
		}
		if (MouseX > 110 && MouseX < 220 && MouseY>300 && MouseY < 350)//注册框判定
		{
			if (mouse_press(110, 300, 220, 350) == 2)
			{
				if (num == 0 )
				{
					MouseS = 1;
					lightbutton_login(110, 300, 220, 350, LIGHTMAGENTA, LIGHTGRAY, 3);//color1为线颜色，color2为填充色
					num = 4;
				}
				continue;
			}
			else if (mouse_press(110, 300, 220, 350) == 1)
			{
				MouseS = 0;
				*page = 2;//前往注册界面
				return ;
			}
		}
		if (num != 0)//点亮恢复
		{
			if (state1 == 0)
			{
				recoverbutton_login(1);//恢复按钮颜色
			}
			if (state2 == 0)
			{
				recoverbutton_login(2);
			}
			if (num == 3 || num == 4 || num == 5 )
			{
				recoverbutton_login(num);
			}
			num = 0;
		}
		if (MouseS != 0)
			MouseS = 0;
	}
}

void drawlog()//画登录界面
{
	
	setbkcolor(WHITE);
	setcolor(LIGHTMAGENTA);

	rectangle(110, 300, 220, 350);//注册框
	puthz(135, 315, "注册", 24, 34, LIGHTMAGENTA);

	setfillstyle(1, LIGHTMAGENTA);//登录框
	bar(420,300, 530, 350);
	puthz(445, 315, "登录", 24, 34, WHITE);

	setcolor(DARKGRAY);  //账号密码框

	rectangle(140, 150, 240, 180);
	rectangle(240, 150, 240 + 315, 180);//账号框

	rectangle(140, 190, 240, 220);
	rectangle(240, 190, 240 + 315, 220);//密码框

	puthz(166, 160, "账号", 16, 34, DARKGRAY);
	puthz(166, 200, "密码", 16, 34, DARKGRAY);

	setcolor(LIGHTMAGENTA);//blibli图案
	settextstyle(0, 0, 4);
	
	outtextxy(200,70,"bilibili");
	
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
		puthz(445, 315, "登录", 24, 34, WHITE);
		break;
	case 3:
		puthz(135, 315, "注册", 24, 34, MAGENTA);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
	
}
void recoverbutton_login(int status)//登录界面按钮点亮恢复
{
	clrmous(MouseX, MouseY);
	switch (status)
	{
	case 1://账号框恢复
		setcolor(DARKGRAY);
		setfillstyle(1, WHITE);
		setlinestyle(SOLID_LINE, 0, 3);
		rectangle(240, 150, 240 + 315, 180);
		bar(240, 150, 240 + 315, 180);
		break;
	case 2://密码框恢复
		setcolor(DARKGRAY);
		setfillstyle(1, WHITE);
		setlinestyle(SOLID_LINE, 0, 3);
		rectangle(240, 190, 240 + 315, 220);
		bar(240, 190, 240 + 315, 220);
		break;
	case 3://登录框恢复
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(420, 300, 530, 350);
		puthz(445, 315, "登录", 24, 34, WHITE);
		break;
	case 4://注册框恢复
		setcolor(LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		setfillstyle(1, WHITE);
		bar(110, 300, 220, 350);
		rectangle(110, 300, 220, 350);
		puthz(135, 315, "注册", 24, 34, LIGHTMAGENTA);
	}
}
