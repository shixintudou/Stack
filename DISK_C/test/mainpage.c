#include"mainpage.h"
#include<string.h>
#include"input.h"
#include"public.h"
void main_page(int *page,char* vn)
{
	int num = 0;
	int vi[4] = { 1,1,1,1 };
	char number[4] = "\0";
	char dbm[18] = "\0";
	//int p = 0;
	//char* t[] = { "Alittle\\a.dat","Alittle\\b.dat","Alittle\\c.dat","Alittle\\d.dat","Alittle\\f.dat","Alittle\\g.dat" };
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawpage();
	//putbmp(0, 0, "Alittle\\1.bmp");
	show_dbm(96, 100, "a160\\3.dat");
	show_dbm(384, 100, "b160\\3.dat");
	show_dbm(96, 290, "c160\\3.dat");
	show_dbm(384, 290, "d160\\10.dat");
	while (1)
	{
		/*putbmp(100, 100, t[i % 6]);
		i++;
		if(i%6==0)
		drawpage();*/
		newmouse(&MouseX, &MouseY, &press);
		/*puthz(p, 240, "哈哈哈", 16, 20, BLUE);
		delay(50);
		setfillstyle(1, WHITE);
		bar(p, 220, 640, 260);
		p += 16;*/
		strcat(dbm, "a160\\");
		itoa(vi[0], number, 10);
		strcat(dbm, number);
		strcat(dbm, ".dat");
		show_dbm(96, 100, dbm);
		delay(10);
		vi[0]++;
		strcpy(dbm, "\0");
		strcpy(number, "\0");
		if (vi[0] > 686)
		{
			vi[0] = 1;
		}

		strcat(dbm, "b160\\");
		itoa(vi[1], number, 10);
		strcat(dbm, number);
		strcat(dbm, ".dat");
		show_dbm(384, 100, dbm);
		vi[1]++;
		strcpy(dbm, "\0");
		strcpy(number, "\0");
		if (vi[1] > 686)
		{
			vi[1] = 1;
		}

		strcat(dbm, "c160\\");
		itoa(vi[2], number, 10);
		strcat(dbm, number);
		strcat(dbm, ".dat");
		show_dbm(96, 290, dbm);
		delay(10);
		vi[2]++;
		strcpy(dbm, "\0");
		strcpy(number, "\0");
		if (vi[2] > 686)
		{
			vi[2] = 1;
		}

		strcat(dbm, "d160\\");
		itoa(vi[3], number, 10);
		strcat(dbm, number);
		strcat(dbm, ".dat");
		show_dbm(384, 290, dbm);
		delay(10);
		vi[3]++;
		strcpy(dbm, "\0");
		strcpy(number, "\0");
		if (vi[3] > 686)
		{
			vi[3] = 1;
		}
		if (MouseX > 96 && MouseX < 256 && MouseY>100 && MouseY < 190)//"视频A"框判定
		{
			if (mouse_press(96, 100, 256, 190) == 2)
			{
				
			}
			else if (mouse_press(96, 100, 256, 190) == 1)
			{
				MouseS = 0;
				*page = 4;
				strcpy(vn, "a");
				return;
			}
		}
		if (MouseX > 384 && MouseX < 544 && MouseY>100 && MouseY < 190)//"视频B"框判定
		{
			if (mouse_press(384, 100, 544, 190) == 2)
			{
				
			}
			else if (mouse_press(384, 100, 544, 190) == 1)
			{
				MouseS = 0;
				*page = 4;
				strcpy(vn, "b");
				return;
			}
		}
		if (MouseX > 96 && MouseX < 256 && MouseY>290 && MouseY < 380)//"视频C"框判定
		{
			if (mouse_press(96, 290, 256, 380) == 2)
			{
				
			}
			else if (mouse_press(96, 290, 256, 380) == 1)
			{
				MouseS = 0;
				*page = 4;
				strcpy(vn, "c");
				return;
			}
		}
		if (MouseX > 384 && MouseX < 544 && MouseY>290 && MouseY < 380)//"视频D"框判定
		{
			if (mouse_press(384, 290, 544, 380) == 2)
			{
				
			}
			else if (mouse_press(384, 290, 544, 380) == 1)
			{
				MouseS = 0;
				*page = 4;
				strcpy(vn, "d");
				return;
			}
		}
		if (MouseX > 480 && MouseX < 600 && MouseY>400 && MouseY < 470)//"我的"框判定
		{
			if (mouse_press(480, 400, 600, 470) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_mainpage(480, 400, 600, 470, LIGHTMAGENTA, LIGHTGRAY, 1);//color1为线颜色，color2为填充色
					num = 1;
				}
				continue;
			}
			else if (mouse_press(480, 400, 600, 470) == 1)
			{
				MouseS = 0;
				*page = 3;
				return;
			}
		}
		if (MouseX > 590 && MouseX < 640 && MouseY>0 && MouseY < 50)//返回按钮
		{
			if (mouse_press(590, 0, 640, 50) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_mainpage(590, 0, 640, 50, RED, LIGHTGRAY, 2);
					num = 2;
				}
				continue;
			}
			else if (mouse_press(590, 0, 640, 50) == 1)
			{
				MouseS = 0;
				delay(100);
				exit(1);
			}
		}
		if (MouseX > 205 && MouseX < 290 && MouseY>35 && MouseY < 75)//推荐
		{
			if (mouse_press(205, 35, 290, 75) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_mainpage(205, 35, 290, 75, LIGHTRED, LIGHTGRAY, 3);
					num = 3;
				}
				continue;
			}
			else if (mouse_press(205, 35, 290, 75) == 1)
			{
				MouseS = 0;
				*page = 11;
				return;
			}
		}
		if (MouseX > 315 && MouseX < 400 && MouseY>35 && MouseY < 75)//番剧
		{
			if (mouse_press(315, 35, 400, 75) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_mainpage(315, 35, 400, 75, LIGHTRED, LIGHTGRAY, 4);
					num = 4;
				}
				continue;
			}
			else if (mouse_press(315, 35, 400, 75) == 1)
			{
				MouseS = 0;
				*page = 12;
				return;
			}
		}
		if (MouseX > 435 && MouseX < 520 && MouseY>35 && MouseY < 75)//热门
		{
			if (mouse_press(435, 35, 520, 75) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_mainpage(435, 35, 520, 75, LIGHTRED, LIGHTGRAY, 5);
					num = 5;
				}
				continue;
			}
			else if (mouse_press(435, 35, 520, 75) == 1)
			{
				MouseS = 0;
				*page = 13;
				return;
			}
		}
		if (num != 0)
		{
			recoverbutton_mainpage(num);
			num = 0;
		}
		if (MouseS != 0)
			MouseS = 0;
	}
}
void drawpage()
{
	setbkcolor(WHITE);
	setcolor(LIGHTMAGENTA);

	rectangle(480, 400, 600, 470);//"我的"框
	puthz(500, 420, "我的", 32, 50, LIGHTMAGENTA);

	rectangle(40, 400, 160, 470);//主页框
	setfillstyle(1, LIGHTMAGENTA);
	bar(40, 400, 160, 470);
	puthz(60, 420, "主页", 32, 50, WHITE);

	setcolor(LIGHTRED);
	settextstyle(0, 0, 3);
	outtextxy(165, 200, "a");
	outtextxy(453, 200, "b");
	outtextxy(165, 390, "c");
	outtextxy(453, 390, "d");

	setfillstyle(1, LIGHTGRAY);
	bar(95, 35, 180, 75);
	setcolor(LIGHTRED);
	rectangle(95, 35, 180, 75);
	puthz(100, 40, "全部", 32, 45, LIGHTRED);
	puthz(210, 40, "推荐", 32, 45, LIGHTRED);
	puthz(320, 40, "番剧", 32, 45, LIGHTRED);
	puthz(440, 40, "热门", 32, 45, LIGHTRED);

	setcolor(RED);//返回按钮
	rectangle(590, 0, 640, 50);
	line(590, 0, 640, 50);
	line(640, 0, 590, 50);
}
void lightbutton_mainpage(int x, int y, int x1, int y1, int color1, int color2, int flag)
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
	
	case 1://我的
		puthz(500, 420, "我的", 32, 50, LIGHTMAGENTA);
		break;
	case 2://返回
		line(590, 0, 640, 50);
		line(640, 0, 590, 50);
		break;
	case 3://推荐
		puthz(210, 40, "推荐", 32, 45, LIGHTRED);
		break;
	case 4://番剧
		puthz(320, 40, "番剧", 32, 45, LIGHTRED);
		break;
	case 5://热门
		puthz(440, 40, "热门", 32, 45, LIGHTRED);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}
void recoverbutton_mainpage(int status)
{
	clrmous(MouseX, MouseY);
	switch (status)
	{

	case 1:
		setfillstyle(1, WHITE);
		setcolor(LIGHTMAGENTA);
		bar(480, 400, 600, 470);
		rectangle(480, 400, 600, 470);//"我的"框;
		puthz(500, 420, "我的", 32, 50, LIGHTMAGENTA);
		break;
	case 2:
		setfillstyle(1, WHITE);
		setcolor(RED);//返回按钮
		bar(590, 0, 640, 50);
		rectangle(590, 0, 640, 50);
		line(590, 0, 640, 50);
		line(640, 0, 590, 50);
		break;
	case 3:
		setfillstyle(1, WHITE);
		bar(205, 35, 290, 75);
		puthz(210, 40, "推荐", 32, 45, LIGHTRED);
		break;
	case 4:
		setfillstyle(1, WHITE);
		bar(315, 35, 400, 75);
		puthz(320, 40, "番剧", 32, 45, LIGHTRED);
		break;
	case 5:
		setfillstyle(1, WHITE);
		bar(435, 35, 520, 75);
		puthz(440, 40, "热门", 32, 45, LIGHTRED);
		break;
	default:
		closegraph();
		printf("something runs wrong in recoverbutton");
		exit(1);
	}
}