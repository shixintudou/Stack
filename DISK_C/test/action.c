#include"public.h"
#include"action.h"
void action_base(int *page,USER* u)
{
	int num = 0;
	
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();//
	base_draw_action(u);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		/*if (MouseX > 100 && MouseX < 400 && MouseY>50 && MouseY < 75)//点赞番剧
		{
			if (mouse_press(100, 50, 400, 75) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					base_action_lightbutton_login_information(100, 50, 400, 75, RED, RED, 2);//color1
					num = 2;
				}
				continue;
			}
			else if (mouse_press(100, 50, 400, 75) == 1)
			{
				MouseS = 0;
				*page = 3;//
				return;
			}
		}*/
		
		
		
		
		if (MouseX > 100 && MouseX < 400 && MouseY>125 && MouseY < 150)//我的评论
		{
			if (mouse_press(100, 125, 400, 150) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					base_action_lightbutton_login_information(100, 125, 400, 150, RED, RED, 3);//color1
					num = 3;
				}
				continue;
			}
			else if (mouse_press(100, 125, 400, 150) == 1)
			{
				MouseS = 0;
				*page = 23;
				return;
			}
		}
		
		
		if (MouseX > 100 && MouseX < 400 && MouseY>200 && MouseY < 225)//我的弹幕
		{
			if (mouse_press(100, 200, 400, 225) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					base_action_lightbutton_login_information(100, 200, 400, 225, RED, RED, 4);//color1
					num = 4;
				}
				continue;
			}
			else if (mouse_press(100, 200, 400, 225) == 1)
			{
				MouseS = 0;
				*page = 24;//
				return;
			}
		}
		
		
		
		if (MouseX > 420 && MouseX < 530 && MouseY>300 && MouseY < 350)//返回
		{
			if (mouse_press(420, 300, 530, 350) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					base_action_lightbutton_login_information(420, 300, 530, 350, RED, RED, 5);//边框，填充
					num = 5;
				}
				continue;
			}
			else if (mouse_press(420, 300, 530, 350) == 1)
			{
				MouseS = 0;
				*page = 3;//
				return;
			}
		}
		if (num != 0)//
		{
			if (num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7)
			{
				base_action_recoverbutton_login_information(num);
			}
			num = 0;
		}
		if (MouseS != 0)
			MouseS = 0;
	}
}

void base_draw_action(USER* u)
{

	setbkcolor(WHITE);
	setcolor(LIGHTMAGENTA);
	setfillstyle(1, LIGHTMAGENTA);//

	
	/*bar(100, 50, 400, 75);//
	puthz(110, 50 ,"点赞番剧", 24, 24+ 4 + 24, WHITE);//*/
	
	bar(100, 125, 400, 150);//
	puthz(110, 125, "我的评论", 24, 24+ 4 + 24, WHITE);
	
	bar(100, 200, 400, 225);//
	puthz(110, 200, "我的弹幕", 24, 24+ 4 + 24, WHITE);


	bar(420, 300, 530, 350);//
	puthz(425, 315, "返回", 24, 4 + 24, WHITE);

}
void base_action_lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag)//点亮
{

	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);
	switch (flag)
	{
	case 1:
		break;
	/*case 2:
		puthz(110, 50 ,"点赞番剧", 24, 4 + 24+24, WHITE);
		break;*/
	case 3:
		puthz(110, 125, "我的评论", 24, 4 + 24+24, WHITE);
		break;
	case 4:
		puthz(110, 200, "我的弹幕", 24, 4 + 24+24, WHITE);
		break;
	case 5:
		puthz(425, 315, "返回", 24, 4 + 24, WHITE);
		break;
	
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}

}


void base_action_recoverbutton_login_information(int status)//恢复
{
	clrmous(MouseX, MouseY);
	switch (status)
	{
		
	/*case 2://
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(100, 50, 400, 75);//
		rectangle(100, 50, 400, 75);
		puthz(110, 50 ,"点赞番剧", 24, 4 + 24+24, WHITE);
		break;*/
	case 3://
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(100, 125, 400, 150);//
		rectangle(100, 125, 400, 150);
		puthz(110, 125, "我的评论", 24, 4 + 24+24, WHITE);
		break;
	case 4://
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(100, 200, 400, 225);//
		rectangle(100, 200, 400, 225);
		puthz(110, 200, "我的弹幕", 24, 4 + 24+24, WHITE);
		
	case 5://
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(420, 300, 530, 350);
		rectangle(420, 300, 530, 350);
		puthz(425, 315, "返回", 24, 28, WHITE);
		break;
	}
}