#include"public.h"
#include"register.h"
#include"database.h"
#include"lgfunc.h"
void register_main(int *page)
{
	char U[15] = { '\0' };           //6-12位，用户名
	char I[21] = { '\0' };             //18位，账号
	char P[20] = {'\0'};  //8-16位，密码
	char CP[20] = { '\0' };
	char PH[21] = {'\0'};
	int num = 0;
	int state1 = 0;
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;
	int state5 = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawregister();
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 240 && MouseX < 240 + 315 && MouseY>110 && MouseY < 140)//手机号框判定
		{
			if (mouse_press(240, 110, 240 + 315, 140) == 2)
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)//防止被重复标亮
				{
					lightbutton_signin(240, 110, 240 + 315, 140, DARKGRAY, LIGHTGRAY, 1);//color1为线颜色，color2为填充色
					num = 1;
				}
				continue;
			}
			else if (mouse_press(240, 110, 240+315, 140) == 1)      //点击手机号框
			{
				MouseS = 0;
				lightbutton_signin(240, 110, 240+315, 140, RED, LIGHTGRAY, 1);
				PH[0] = '\0';
				inputadmin(PH, 240, 110, 12, LIGHTGRAY);//后期输入函数
				if (strlen(PH) != 0)
					state1 = 1;
				else
					state1 = 0;
				continue;
			}
		}
		if (MouseX > 240 && MouseX < 240 + 315 && MouseY>150 && MouseY < 180)//用户名框判定
		{
			if (mouse_press(240, 150, 240 + 315, 180) == 2)
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)//防止被重复标亮
				{
					lightbutton_signin(240, 150, 240 + 315, 180, DARKGRAY, LIGHTGRAY, 1);//color1为线颜色，color2为填充色
					num = 2;
				}
				continue;
			}
			else if (mouse_press(240, 150, 240 + 315, 180) == 1)      //点击用户名框
			{
				MouseS = 0;
				lightbutton_signin(240, 150, 240 + 315, 180, RED, LIGHTGRAY, 1);
				U[0] = '\0';
				inputadmin(U, 240, 150, 12, LIGHTGRAY);//后期输入函数
				if (strlen(U) != 0)
					state2 = 1;
				else
					state2 = 0;
				continue;
			}
		}
		if (MouseX > 240 && MouseX < 240 + 315 && MouseY>190 && MouseY < 220)//账号框判定
		{
			if (mouse_press(240, 190, 240 + 315, 220) == 2)
			{
				MouseS = 2;
				if (num == 0 && state3 == 0)//防止被重复标亮
				{
					lightbutton_signin(240, 190, 240 + 315, 220, DARKGRAY, LIGHTGRAY, 1);//color1为线颜色，color2为填充色
					num = 3;
				}
				continue;
			}
			else if (mouse_press(240, 190, 240 + 315, 220) == 1)      //点击账号框
			{
				MouseS = 0;
				lightbutton_signin(240, 190, 240 + 315, 220, RED, LIGHTGRAY, 1);
				I[0] = '\0';
				inputadmin(I, 240, 190, 12, LIGHTGRAY);//后期输入函数
				if (strlen(I) != 0)
					state3 = 1;
				else
					state3 = 0;
				continue;
			}
		}
		if (MouseX > 240 && MouseX < 240 + 315 && MouseY>230 && MouseY < 260)//密码框判定
		{
			if (mouse_press(240, 230, 240 + 315, 260) == 2)
			{
				MouseS = 2;
				if (num == 0 && state4 == 0)//防止被重复标亮
				{
					lightbutton_signin(240, 230, 240 + 315, 260, DARKGRAY, LIGHTGRAY, 1);//color1为线颜色，color2为填充色
					num = 4;
				}
				continue;
			}
			else if (mouse_press(240, 230, 240+315, 260) == 1)     //点击密码框
			{

				lightbutton_signin(240, 230, 240+315, 260, RED, LIGHTGRAY, 2);
				MouseS = 0;
				P[0] = '\0';
				inputpassword(P, 240, 230, 16, LIGHTGRAY);//输入函数
				if (strlen(P) != 0)
					state4 = 1;
				else
					state4 = 0;
				continue;
			}
		}
		if (MouseX > 240 && MouseX < 240 + 315 && MouseY>270 && MouseY < 300)//确认密码框判定
		{
			if (mouse_press(240, 270, 240 + 315, 300) == 2)
			{
				MouseS = 2;
				if (num == 0 && state5 == 0)//防止被重复标亮
				{
					lightbutton_signin(240, 270, 240 + 315, 300, DARKGRAY, LIGHTGRAY, 1);//color1为线颜色，color2为填充色
					num = 5;
				}
				continue;
			}
			else if (mouse_press(240, 270, 240+315, 300) == 1)      //点击确认密码框
			{
				lightbutton_signin(240, 270, 240+315, 300, RED, LIGHTGRAY, 2);
				MouseS = 0;
				CP[0] = '\0';
				inputpassword(CP, 240, 270, 16, LIGHTGRAY);
				//输入函数
				if (strlen(CP) != 0)
					state5 = 1;
				else
					state5 = 0;
				continue;
			}
		}
		if (MouseX > 160 && MouseX < 500 && MouseY>350 && MouseY < 410)//立即注册框判定
		{
			if (mouse_press(160, 350, 500, 410) == 2)
			{
				if (num == 0 )
				{
					MouseS = 1;
					lightbutton_signin(160, 350, 500, 410, RED, RED, 2);//color1为线颜色，color2为填充色
					num = 6;
				}
				continue;
			}
			else if (mouse_press(160, 350, 500, 410) == 1)
			{

				if (register_complete(I, P, CP, PH, U)==1)//U6-12，P8-16，CP8-16，I9，PH11
				{
					MouseS = 0;
					*page = 1;
					return;
				}
				else
				{
					continue;
				}
				//注册判断
			}
			
		}
		if (MouseX > 0 && MouseX < 70 && MouseY>0 && MouseY < 40)//返回框判定
		{
			if (mouse_press(0, 0, 70, 40) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_signin(0, 0, 70, 40, DARKGRAY, LIGHTGRAY, 3);//color1为线颜色，color2为填充色
					num = 7;
				}
				continue;
			}
			else if (mouse_press(0, 0, 70, 40) == 1)
			{
				MouseS = 0;
				*page = 1;
				return;
			}
		}
		if (num != 0)
		{
			MouseS = 0;
			if (state1 == 0)
			{
				recoverbutton_signin(1);
			}
			if (state2 == 0)
			{
				recoverbutton_signin(2);
			}
			if (state3 == 0)
			{
				recoverbutton_signin(3);
			}
			if (state4 == 0)
			{
				recoverbutton_signin(4);
			}
			if (state5 == 0)
			{
				recoverbutton_signin(5);
			}
			if (num == 6||num==7)
			{
				recoverbutton_signin(num);
			}
			num = 0;
		}
		if (MouseS != 0)
			MouseS = 0;
	}
	
}
void drawregister()//画注册界面
{
	setbkcolor(WHITE);

	setcolor(LIGHTMAGENTA);//blibli图案
	settextstyle(0, 0, 4);
	outtextxy(200, 70, "bilibili");

	setcolor(DARKGRAY);//各输入框

	rectangle(140, 110, 240, 140);
	rectangle(240, 110, 240 + 315, 140);//手机号框

	rectangle(140, 150, 240, 180);
	rectangle(240, 150, 240 + 315, 180);//用户名框

	rectangle(140, 190, 240, 220);
	rectangle(240, 190, 240 + 315, 220);//账号框

	rectangle(140, 230, 240, 260);
	rectangle(240, 230, 240 + 315, 260);//密码框

	rectangle(140, 270, 240, 300);
	rectangle(240, 270, 240 + 315, 300);//确认密码框

	puthz(154, 118, "手机号", 16, 30, DARKGRAY);
	puthz(154, 158, "用户名", 16, 30, DARKGRAY);
	puthz(168, 198, "账号", 16, 34, DARKGRAY);
	puthz(168, 238, "密码", 16, 34, DARKGRAY);
	puthz(144, 278, "确认密码", 16, 26, DARKGRAY);

	setfillstyle(1, LIGHTMAGENTA);//立即注册框
	bar(160, 350, 500, 410);
	puthz(240, 365, "立即注册", 32, 50, WHITE);

	rectangle(0, 0, 70, 40);
	puthz(15, 13, "返回", 16, 20, RED);
}
void lightbutton_signin(int x, int y, int x1, int y1, int color1, int color2, int flag)//注册界面点亮
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
		puthz(240, 365, "立即注册", 32, 50, WHITE);
		break;
	case 3:
		puthz(15, 13, "返回", 16, 20, LIGHTRED);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}
void recoverbutton_signin(int status)
{
	clrmous(MouseX, MouseY);
	setlinestyle(SOLID_LINE, 0, 1);
	setcolor(DARKGRAY);
	setfillstyle(1, WHITE);
	switch (status)
	{
	case 1:
		bar(240, 110, 240 + 315, 140);
		rectangle(240, 110, 240 + 315, 140);
		break;
	case 2:
		bar(240, 150, 240 + 315, 180);
		rectangle(240, 150, 240 + 315, 180);
		break;
	case 3:
		bar(240, 190, 240 + 315, 220);
		rectangle(240, 190, 240 + 315, 220);
		break;
	case 4:
		bar(240, 230, 240 + 315, 260);
		rectangle(240, 230, 240 + 315, 260);
		break;
	case 5:
		bar(240, 270, 240 + 315, 300);
		rectangle(240, 270, 240 + 315, 300);
		break;
	case 6:
		setfillstyle(1, LIGHTMAGENTA);//立即注册框
		bar(160, 350, 500, 410);
		puthz(240, 365, "立即注册", 32, 50, WHITE);
		break;
	case 7:
		bar(0, 0, 70, 40);
		rectangle(0, 0, 70, 40);
		puthz(15, 13, "返回", 16, 20, RED);
	}
}

