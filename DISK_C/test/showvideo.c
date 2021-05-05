#include"showvideo.h"
#include<string.h>
void show(int* page,char* vn,USER *u,BH*b)
{
	char STK_ADR6[50] = { '\0' };
	char time_of_now[10];
	FILE* fp;
	int i = 1;
	int num = 0;
	int state = 0;//0为播放中，1为暂停中
	char dbm[18] = "\0";
	char number[3] = "\0";	
	unsigned char h, m, d;
	struct time t[1];//bc内置结构体
	setwritemode(1);
	gettime(t);
	d = t[0].ti_day;
	h = t[0].ti_hour;
	m = t[0].ti_min;
	/*char* ta[] = { "Alarge\\a.dat","Alarge\\b.dat","Alarge\\c.dat","Alarge\\d.dat","Alarge\\f.dat","Alarge\\g.dat" };
	char* tb[] = { "Blarge\\1.dat","Blarge\\2.dat", "Blarge\\3.dat", "Blarge\\4.dat", "Blarge\\5.dat", "Blarge\\6.dat", "Blarge\\7.dat", "Blarge\\8.dat", "Blarge\\9.dat", "Blarge\\10.dat", "Blarge\\11.dat", "Blarge\\12.dat", "Blarge\\13.dat", "Blarge\\14.dat", "Blarge\\15.dat", "Blarge\\16.dat", "Blarge\\17.dat",
		"Blarge\\18.dat","Blarge\\19.dat","Blarge\\20.dat","Blarge\\21.dat","Blarge\\22.dat","Blarge\\23.dat","Blarge\\24.dat","Blarge\\25.dat","Blarge\\26.dat",
		"Blarge\\27.dat","Blarge\\28.dat","Blarge\\29.dat","Blarge\\30.dat","Blarge\\31.dat","Blarge\\32.dat","Blarge\\33.dat","Blarge\\34.dat","Blarge\\35.dat","Blarge\\36.dat",
		"Blarge\\37.dat","Blarge\\38.dat","Blarge\\39.dat","Blarge\\40.dat","Blarge\\41.dat","Blarge\\42.dat","Blarge\\43.dat","Blarge\\44.dat","Blarge\\45.dat","Blarge\\46.dat",
		"Blarge\\47.dat","Blarge\\48.dat","Blarge\\49.dat","Blarge\\50.dat","Blarge\\51.dat","Blarge\\52.dat","Blarge\\53.dat","Blarge\\54.dat","Blarge\\55.dat",
		"Blarge\\56.dat","Blarge\\57.dat","Blarge\\58.dat","Blarge\\59.dat","Blarge\\60.dat","Blarge\\61.dat","Blarge\\62.dat","Blarge\\63.dat","Blarge\\64.dat",
		"Blarge\\65.dat","Blarge\\66.dat","Blarge\\67.dat","Blarge\\68.dat","Blarge\\69.dat","Blarge\\70.dat","Blarge\\71.dat","Blarge\\72.dat","Blarge\\73.dat",
		"Blarge\\74.dat","Blarge\\75.dat","Blarge\\76.dat","Blarge\\77.dat","Blarge\\78.dat","Blarge\\79.dat","Blarge\\80.dat","Blarge\\81.dat","Blarge\\82.dat",
		"Blarge\\83.dat","Blarge\\84.dat","Blarge\\85.dat","Blarge\\86.dat","Blarge\\87.dat","Blarge\\88.dat","Blarge\\89.dat","Blarge\\90.dat","Blarge\\91.dat",
		"Blarge\\92.dat","Blarge\\93.dat","Blarge\\94.dat","Blarge\\95.dat","Blarge\\96.dat","Blarge\\97.dat","Blarge\\98.dat","Blarge\\99.dat","Blarge\\100.dat","Blarge\\101.dat","Blarge\\102.dat","Blarge\\103.dat","Blarge\\104.dat",
		"Blarge\\105.dat","Blarge\\106.dat","Blarge\\107.dat","Blarge\\108.dat","Blarge\\109.dat",
	"Blarge\\110.dat", "Blarge\\111.dat", "Blarge\\112.dat", "Blarge\\113.dat", "Blarge\\114.dat", "Blarge\\115.dat", "Blarge\\116.dat", "Blarge\\117.dat", "Blarge\\118.dat", "Blarge\\119.dat", "Blarge\\120.dat" };*/
	clrmous(MouseX, MouseY);
	
	delay(100);
	cleardevice();
	drawshow();
	if (strlen(u->user) != 0)
	{
		strcat(STK_ADR6, "Database\\USER\\");
		strcat(STK_ADR6, u->user);
		strcat(STK_ADR6, "history.dat");
		if ((fp = fopen(STK_ADR6, "rb+")) == NULL)//建立数据库
		{
			printf("cannot open file");
			delay(3000);
			exit(1);
		}
		if ((b = (BH*)malloc(sizeof(BH))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		memset(b, '\0', sizeof(BH));
		strcpy(b->name, vn);
		strcpy(b->BH_of_day, d);
		strcpy(b->BH_of_hour, h);
		strcpy(b->BH_of_min, min);
		fseek(fp, 0, SEEK_END);//跳转至文件末尾
		fwrite(b, sizeof(BH), 1, fp);//把用户信息写入文件 余额默认为0
	}
	
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (state == 0)
		{
			strcat(dbm, vn);
			strcat(dbm, "\\");
			itoa(i, number, 10);
			strcat(dbm, number);
			strcat(dbm, ".dat");
			i++;
			show_dbm(80, 80, dbm);
			delay(40);
			strcpy(dbm, "\0");
			strcpy(number, "\0");
			if (i > 686)
			{
				i = 1;
				state = 1;
			}
		}
		if (((MouseX-315)*(MouseX - 315)+(MouseY-430)*(MouseY - 430))<=1600)//播放暂停按钮
		{
			if (mouse_press(280, 395, 350, 465) == 2)
			{
				MouseS = 1;
				if (state == 0 && num==0 )
				{
					lightbutton_show(BLUE, LIGHTGRAY, 1);//color1为线颜色，color2为填充色
					num = 1;
				}
				if (state == 1 && num==0 )
				{
					lightbutton_show(BLUE, LIGHTGRAY, 2);
					num = 2;
				}
				continue;
			}
			else if (mouse_press(280, 395, 350, 465) == 1)
			{
				MouseS = 0;
				if (state == 0)
				{
					lightbutton_show(BLUE, LIGHTGRAY, 2);
					state = 1;
					num = 2;
					delay(100);
					continue;
				}
				if (state == 1)
				{
					lightbutton_show(BLUE, LIGHTGRAY, 1);
					state = 0;
					num = 1;
					delay(100);
				}
			}
		}
		if (MouseX > 590 && MouseX < 640 && MouseY>0 && MouseY < 50)//返回按钮
		{
			if (mouse_press(590, 0, 640, 50) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_show(RED, LIGHTGRAY, 3);
					num = 3;
				}
				continue;
			}
			else if (mouse_press(590, 0, 640, 50) == 1)
			{
				MouseS = 0;
				*page = 0;
				return;
			}
		}
		if (MouseX > 450 && MouseX < 540 && MouseY>390 && MouseY < 430)//收藏按钮
		{
			if (mouse_press(450, 390, 540, 430) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_show(RED, RED, 4);
					num = 4;
				}
				continue;
			}
			else if (mouse_press(450, 590, 540, 430) == 1)
			{

			}
		}
		if (MouseX > 100 && MouseX < 200 && MouseY>380 && MouseY < 420)//发弹幕按钮
		{
			if (mouse_press(100, 380, 200, 420) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_show(RED, RED, 5);
					num = 5;
				}
				continue;
			}
			else if (mouse_press(100, 380, 200, 420) == 1)
			{

			}
		}
		if (MouseX > 100 && MouseX < 200 && MouseY>435 && MouseY < 475)//评论按钮
		{
			if (mouse_press(100, 435, 200, 475) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_show(RED, RED, 6);
					num = 6;
				}
				continue;
			}
			else if (mouse_press(100, 435, 200, 475) == 1)
			{

			}
		}
		if (num != 0)
		{
			if (state == 0)
				recoverbutton_show(1);
			if (state == 1)
				recoverbutton_show(2);
			if (num == 3 || num == 4 || num == 5 || num == 6)
				recoverbutton_show(num);
			num = 0;
		}
		if (MouseS != 0)
			MouseS = 0;
	}
}
void drawshow()
{
	setcolor(BLUE);

	circle(315, 430, 40);

	line(300, 405, 300, 455);//播放时
	line(330, 405, 330, 455);

	//line(300, 405, 300, 455);//暂停时
	//line(300, 405, 340, 430);
	//line(300, 455, 340, 430);

	setfillstyle(1, LIGHTMAGENTA);//收藏
	bar(450, 390, 540, 430);
	puthz(468, 399, "收藏", 24, 30, WHITE);

	bar(100, 380, 200, 420);//发弹幕
	puthz(116, 388, "发弹幕", 24, 24, WHITE);

	bar(100, 435, 200, 475);//评论
	puthz(123, 443, "评论", 24, 30, WHITE);

	setcolor(RED);//返回按钮
	rectangle(590, 0, 640, 50);
	line(590, 0, 640, 50);
	line(640, 0, 590, 50);
}
void lightbutton_show( int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setfillstyle(1, color2);
	switch (flag)
	{
	case 1://播放时
		pieslice(315, 430, 0, 360, 40);
		/*setcolor(WHITE);
		line(315, 430, 355, 430);*/
		setcolor(color1);
		line(300, 405, 300, 455);
		line(330, 405, 330, 455);
		break;
	case 2:
		pieslice(315, 430, 0, 360, 40);
		line(300, 405, 300, 455);//暂停时
	    line(300, 405, 340, 430);
	    line(300, 455, 340, 430);
		break;
	case 3:
		bar(590, 0, 640, 50);
		rectangle(590, 0, 640, 50);
		line(590, 0, 640, 50);
		line(640, 0, 590, 50);
		break;
	case 4://收藏按钮
		bar(450, 390, 540, 430);
		puthz(468, 399, "收藏", 24, 30, WHITE);
		break;
	case 5://发弹幕
		bar(100, 380, 200, 420);
		puthz(116, 388, "发弹幕", 24, 24, WHITE);
		break;
	case 6://评论
		bar(100, 435, 200, 475);
		puthz(123, 443, "评论", 24, 30, WHITE);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}
void recoverbutton_show(int status)
{
	clrmous(MouseX, MouseY);
	switch (status)
	{
	case 1:
		setcolor(WHITE);
		setfillstyle(1, WHITE);
		pieslice(315, 430, 0, 360, 40);
		line(315, 430, 355, 430);
		setcolor(BLUE);
		circle(315, 430, 40);
		line(300, 405, 300, 455);//播放时
		line(330, 405, 330, 455);
		break;
	case 2:
		setcolor(BLUE);
		setfillstyle(1, WHITE);
		pieslice(315, 430, 0, 360, 40);
		circle(315, 430, 40);
		line(300, 405, 300, 455);//暂停时
		line(300, 405, 340, 430);
		line(300, 455, 340, 430);
		break;
	case 3:
		setcolor(RED);
		setfillstyle(1, WHITE);
		bar(590, 0, 640, 50);
		rectangle(590, 0, 640, 50);
		line(590, 0, 640, 50);
		line(640, 0, 590, 50);
		break;
	case 4:
		setfillstyle(1, LIGHTMAGENTA);//收藏
		bar(450, 390, 540, 430);
		puthz(468, 399, "收藏", 24, 30, WHITE);
		break;
	case 5:
		setfillstyle(1, LIGHTMAGENTA);
		bar(100, 380, 200, 420);//发弹幕
		puthz(116, 388, "发弹幕", 24, 24, WHITE);
		break;
	case 6:
		setfillstyle(1, LIGHTMAGENTA);
		bar(100, 435, 200, 475);//评论
		puthz(123, 443, "评论", 24, 30, WHITE);
		break;
	}
}