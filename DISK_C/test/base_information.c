#include"public.h"
void main_base(int *page,USER* u)
{
	int num = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();//库函数
	base_draw_information(u);
	base_draw_my_information(u);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 420 && MouseX < 530 && MouseY>300 && MouseY < 350)//返回首页判定
		{
			if (mouse_press(420, 300, 530, 350) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					base_lightbutton_login_information(420, 300, 530, 350, RED, RED, 4);//color1为线颜色，color2为填充色
					num = 4;
				}
				continue;
			}
			else if (mouse_press(420, 300, 530, 350) == 1)
			{
				MouseS = 0;
				*page = 3;//现在默认0首页
				return;
			}
		}
		if (num != 0)//点亮恢复
		{
			if (num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7)
			{
				base_recoverbutton_login_information(num);
			}
			num = 0;
		}
		if (MouseS != 0)
			MouseS = 0;
	}
}
void base_draw_information(USER* u)
{
	setbkcolor(WHITE);
	setcolor(LIGHTMAGENTA);//blibli图案
	settextstyle(0, 0, 3);

	puthz(24*4, 0, "我的名称", 24, 24 + 4, LIGHTMAGENTA);
	puthz(24*4, 24*2, "我的账号", 24, 24 + 4, LIGHTMAGENTA);
	puthz(24 * 4, 24*4, "绑定手机", 24, 24 + 4, LIGHTMAGENTA);
	

	outtextxy(110+24*4, 0, u->user);//
	outtextxy(110+24*4, 24*2, u->ID);//
	outtextxy(110+24*4, 24*4, u->phone);//


}
void base_draw_my_information(USER* u)
{

	setbkcolor(WHITE);
	setcolor(LIGHTMAGENTA);
	setfillstyle(1,LIGHTMAGENTA);


	bar(420, 300, 530, 350);//返回
	puthz(425, 315, "返回", 24, 4 + 24, WHITE);

}
void base_lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag)//按钮点亮
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
		puthz(425, 115, "稍后再看", 24, 4 + 24, WHITE);
		break;
	case 3:
		puthz(425, 215, "我的动态", 24, 4 + 24, WHITE);
		break;
	case 4:
		puthz(425, 315, "返回", 24, 4 + 24, WHITE);
		break;
	case 5:
		puthz(115, 115, "基本信息", 24, 4 + 24, MAGENTA);
		break;
	case 6:
		puthz(115, 215, "历史记录", 24, 4 + 24, MAGENTA);
		break;
	case 7:
		puthz(115, 315, "我的收藏", 24, 4 + 24, MAGENTA);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}

}


void base_recoverbutton_login_information(int status)//恢复
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
		puthz(425, 315, "返回", 24, 28, WHITE);
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