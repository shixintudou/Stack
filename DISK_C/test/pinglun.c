#include"pinglun.h"

void pinglun_main(USER* u, int* number, char* vn,int* state)
{
	int num = 0;
	char dbm[22] = "\0";//视频文件
	char pnumber[4] = "\0";
	int len = 0;
	int head = 0;
	int tail = 3;
	//int isinput = 0;//是否输入过，0为未输入过，1为输入过
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	len = getlen(vn);
	draw_pinglun();
	showpinglun_start(vn, head, tail);
	strcat(dbm, vn);
	strcat(dbm, "160\\");
	itoa(*number, pnumber, 10);
	strcat(dbm, pnumber);
	strcat(dbm, ".dat");
	show_dbm(240, 15, dbm);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (*state == 0)
		{
			strcpy(dbm, "\0");
			strcpy(pnumber, "\0");
			strcat(dbm, vn);
			strcat(dbm, "160\\");
			itoa(*number, pnumber, 10);
			strcat(dbm, pnumber);
			strcat(dbm, ".dat");
			*number += 1;
			show_dbm(240, 15, dbm);
			/*outtextxy(20, 20, pnumber);
			outtextxy(30, 30, dbm);
			delay(1000);
			cleardevice();*/
			delay(30);
			if (*number > 686)
			{
				*number = 1;
				*state = 1;
			}
		}
		if (MouseX > 590 && MouseX < 640 && MouseY>0 && MouseY < 50)//返回按钮
		{
			if (mouse_press(590, 0, 640, 50) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_pinglun(590, 0, 640, 50, RED, LIGHTGRAY, 1);
					num = 1;
				}
				continue;
			}
			else if (mouse_press(590, 0, 640, 50) == 1)
			{
				MouseS = 0;
				cleardevice();
				drawshow();
				delay(100);
				return;
			}
		}
		if (MouseX > 0 && MouseX < 100 && MouseY>110 && MouseY < 150)//发评论
		{
			if (mouse_press(0, 110, 100, 150) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_pinglun(0, 110, 100, 150, RED, RED, 2);
					num = 2;
				}
				continue;
			}
			else if (mouse_press(0, 110, 100, 150) == 1)
			{
				if (strlen(u->user) == 0)
				{
					pleaselog();
					cleardevice();
					draw_pinglun();					
					showpinglun_start(vn, head, tail);
				}
				else
				{
					drawinput_pinglun();
					getpinglun(u, vn);
					len = getlen(vn);
					cleardevice();
					draw_pinglun();
					showpinglun_start(vn, head, tail);
				}
			}
		}
		if (MouseX > 290 && MouseX < 350 && MouseY> 150 && MouseY < 170)//上翻
		{
			if (mouse_press(290, 150, 350, 170) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_pinglun(290, 150, 350, 170, LIGHTMAGENTA, LIGHTGRAY, 3);
					num = 3;
				}
				continue;
			}
			else if (mouse_press(290, 150, 350, 170) == 1)
			{
				if (head > 0 && len > 4)
				{
					head--;
					tail--;
					cleardevice();
					draw_pinglun();
					showpinglun_start(vn, head, tail);
				}
				delay(100);
			}
		}
		if (MouseX > 290 && MouseX < 350 && MouseY>460 && MouseY < 480)//下翻
		{
			if (mouse_press(290, 460, 350, 480) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_pinglun(290, 460, 350, 480, LIGHTMAGENTA, LIGHTGRAY, 4);
					num = 4;
				}
				continue;
			}
			else if (mouse_press(290, 460, 350, 480) == 1)
			{
				if (tail < len - 1 && len > 4)
				{
					head++;
					tail++;
					cleardevice();
					draw_pinglun();
					showpinglun_start(vn, head, tail);
				}
				delay(100);
			}
		}
		if (num != 0)
		{
			recoverbutton_pinglun(num);
			num = 0;
		}
		if (MouseS != 0)
			MouseS = 0;
	}
}
void draw_pinglun()
{
	setcolor(LIGHTMAGENTA);
	moveto(0, 120);
	lineto(640, 120);
	moveto(0, 136);
	lineto(640, 136);

	setcolor(RED);//返回按钮
	rectangle(590, 0, 640, 50);
	line(590, 0, 640, 50);
	line(640, 0, 590, 50);

	setfillstyle(1, LIGHTMAGENTA);
	bar(0, 110, 100, 150);
	puthz(3, 117, "发评论", 24, 30, WHITE);

	setcolor(LIGHTMAGENTA);//翻页按钮
	line(320, 150, 290, 170);
	line(320, 150, 350, 170);
	line(320, 480, 290, 460);
	line(320, 480, 350, 460);
}
void lightbutton_pinglun(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框
	switch (flag)
	{
	case 1://返回键
		line(590, 0, 640, 50);
		line(640, 0, 590, 50);
		break;
	case 2://发评论
		puthz(3, 117, "发评论", 24, 30, WHITE);
		break;
	case 3://上翻
		setcolor(LIGHTMAGENTA);
		line(320, 150, 290, 170);
		line(320, 150, 350, 170);
		break;
	case 4://下翻
		setcolor(LIGHTMAGENTA);
		line(320, 480, 290, 460);
		line(320, 480, 350, 460);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}
void recoverbutton_pinglun(int status)
{
	clrmous(MouseX, MouseY);
	switch (status)
	{
	case 1:
		setfillstyle(1, WHITE);
		setcolor(RED);//返回按钮
		bar(590, 0, 640, 50);
		rectangle(590, 0, 640, 50);
		line(590, 0, 640, 50);
		line(640, 0, 590, 50);
		break;
	case 2:
		setfillstyle(1, LIGHTMAGENTA);
		bar(0, 110, 100, 150);
		puthz(3, 117, "发评论", 24, 30, WHITE);
		break;
	case 3:
		setfillstyle(1, WHITE);
		bar(290, 150, 350, 170);
		setcolor(LIGHTMAGENTA);
		line(320, 150, 290, 170);
		line(320, 150, 350, 170);
		break;
	case 4:
		setfillstyle(1, WHITE);
		bar(290, 460, 350, 480);
		setcolor(LIGHTMAGENTA);
		line(320, 480, 290, 460);
		line(320, 480, 350, 460);
		break;
	default:
		closegraph();
		printf("something runs wrong in recoverbutton");
		exit(1);
	}
}
void getpinglun(USER* u,char* vn)
{
	
	int LEN=0;
	char aaa[3]="\0";
	
	char user[20] = "\0";
	char fname[25] = "\0";
	char SKT[50]="\0";
	char pinglun[100] = "\0";
	time_t timep;
	int h, min;
	char mins[10] = "\0";
	char hs[10] = "\0";
	struct tm* t;
	time(&timep);
	t = localtime(&timep);
	h = t->tm_hour;
	min = t->tm_min;
	itoa(h, hs, 10);
	itoa(min, mins, 10);//获取时间
	

	strcpy(SKT, "Database\\USER\\");     
	strcat(SKT, u->user);
	strcat(SKT, "\\PLUN.dat");
	
	strcat(fname, "videos\\pinglun");
	strcat(fname, vn);
	strcat(fname, ".dat");
	strcpy(user, u->user);

	
	LEN = hz_input(120, 110, 240, 150, pinglun, LEN, WHITE);
	settextjustify(0, 2);
	if (LEN != 0)
	{
		FILE* fp4;
		FILE*fp6;
		
		if ((fp6 = fopen(SKT, "rb+")) == NULL)//打开评论文件
		{
			printf("can't open pinglun file");
			exit(1);
		}
		
		fseek(fp6, 0L, SEEK_END);
		fwrite(vn, sizeof(aaa), 1, fp6);
		fwrite(hs, sizeof(hs), 1, fp6);
		fwrite(mins, sizeof(mins), 1, fp6);
		fwrite(pinglun, sizeof(pinglun), 1, fp6);
		
		if (fclose(fp6) != 0)
		{
			printf("\n cannot close Database.");
			delay(3000);
			exit(1);
		}
		
		
		
		
		
		if ((fp4 = fopen(fname, "rb+")) == NULL)//打开评论文件
		{
			closegraph();
			printf("can't open pinglun file");
			exit(1);
		}
		
		fseek(fp4, 0L, SEEK_END);
		fwrite(user, sizeof(user), 1, fp4);
		fwrite(pinglun, sizeof(pinglun), 1, fp4);
		fwrite(hs, sizeof(hs), 1, fp4);
		fwrite(mins, sizeof(mins), 1, fp4);
		if (fclose(fp4) == -1)
		{
			closegraph();
			printf("close file error in input_data\n");
		}
		
		
		
		
		
		//puthz(40, 180 + 1 * 60, pinglun, 16, 20, LIGHTMAGENTA);
		//getch();
		//input_data(fname, user, pinglun, hs, mins);
	}
	
	/*setcolor(LIGHTMAGENTA);
	outtextxy(40, 160 +  60, user);
	puthz(40, 180 +  60, pinglun, 16, 20, LIGHTMAGENTA);
	outtextxy(40, 200 + 60, hs);
	puthz(55, 200 +  60, "时", 16, 16, LIGHTMAGENTA);
	outtextxy(80, 200 +  60, mins);
	puthz(105, 200 +  60, "分", 16, 16, LIGHTMAGENTA);
	delay(2000);*/
}
void showpinglun_start(char* vn, int head, int tail)
{
	char fname[25] = "\0";
	long move = 0L;
	FILE* fp5;
	int i = 0;
	int j = 0;
	int len = 0;
	char user[20] = "\0";
	char pinglun[100] = "\0";
	char time_hs[10] = "\0";
	char time_mins[10] = "\0";
	strcat(fname, "videos\\pinglun");
	strcat(fname, vn);
	strcat(fname, ".dat");
	if ((fp5 = fopen(fname, "rb+")) == NULL)//打开评论文件
	{
		closegraph();
		printf("can't open pinglun file");
		exit(1);
	}
	fseek(fp5, 0L, SEEK_END);
	len = ftell(fp5) / (sizeof(user) + sizeof(pinglun) + sizeof(time_hs) + sizeof(time_mins));
	fseek(fp5, 0L, SEEK_SET);
	if (len < 1)
	{
		fclose(fp5);
		return;
	}
	if (len <= 4)
	{
		for (i = 0; i < (len < 4 ? len : 4); i++)
		{
			fread(user, sizeof(user), 1, fp5);
			fread(pinglun, sizeof(pinglun), 1, fp5);
			fread(time_hs, sizeof(time_hs), 1, fp5);
			fread(time_mins, sizeof(time_mins), 1, fp5);
			//setviewport(0, 0, 640, 480, 0);
			setcolor(LIGHTMAGENTA);
			settextstyle(0, 0, 2);
			outtextxy(40, 160 + i * 70, user);
			outtextxy(40, 200 + i * 70, time_hs);
			outtextxy(90, 200 + i * 70, time_mins);
			puthz(40, 180 + i * 70, pinglun, 16, 20, LIGHTMAGENTA);
			puthz(72, 200 + i * 70, "时", 16, 16, LIGHTMAGENTA);
			puthz(125, 200 + i * 70, "分", 16, 16, LIGHTMAGENTA);
			strcpy(user, "\0");
			strcpy(pinglun, "\0");
			strcpy(time_hs, "\0");
			strcpy(time_mins, "\0");
		}
	}
	else if (len > 4)
	{
		move = head * 140;
		fseek(fp5, move, SEEK_SET);
		for (j = head,i=0; j <= tail; j++)
		{
			fread(user, sizeof(user), 1, fp5);
			fread(pinglun, sizeof(pinglun), 1, fp5);
			fread(time_hs, sizeof(time_hs), 1, fp5);
			fread(time_mins, sizeof(time_mins), 1, fp5);
			//setviewport(0, 0, 640, 480, 0);
			setcolor(LIGHTMAGENTA);
			settextstyle(0, 0, 2);
			outtextxy(40, 160 + i * 70, user);
			outtextxy(40, 200 + i * 70, time_hs);
			outtextxy(90, 200 + i * 70, time_mins);
			puthz(40, 180 + i * 70, pinglun, 16, 20, LIGHTMAGENTA);
			puthz(72, 200 + i * 70, "时", 16, 16, LIGHTMAGENTA);
			puthz(125, 200 + i * 70, "分", 16, 16, LIGHTMAGENTA);
			strcpy(user, "\0");
			strcpy(pinglun, "\0");
			strcpy(time_hs, "\0");
			strcpy(time_mins, "\0");
			i++;
		}
	}
	if (fclose(fp5) == -1)
	{
		closegraph();
		printf("close file error in show\n");
	}
}
void input_data(char* fname,char* user, char* pinglun, char* hs, char* mins)
{
	FILE* fp4;
	if ((fp4 = fopen(fname, "rb+")) == NULL)//打开评论文件
	{
		closegraph();
		printf("can't open pinglun file");
		exit(1);
	}
	/*setcolor(LIGHTMAGENTA);
	outtextxy(40, 160 + 60, user);
	puthz(40, 180 + 60, pinglun, 16, 20, LIGHTMAGENTA);
	outtextxy(40, 200 + 60, hs);
	puthz(55, 200 + 60, "时", 16, 16, LIGHTMAGENTA);
	outtextxy(80, 200 + 60, mins);
	puthz(105, 200 + 60, "分", 16, 16, LIGHTMAGENTA);
	delay(2000);*/
	fseek(fp4, 0L, SEEK_END);
	fwrite(user, sizeof(user), 1, fp4);
	fwrite(pinglun, sizeof(pinglun), 1, fp4);
	fwrite(hs, sizeof(hs), 1, fp4);
	fwrite(mins, sizeof(mins), 1, fp4);
	if (fclose(fp4) == -1)
	{
		closegraph();
		printf("close file error in input_data\n");
	}
}
void drawinput_pinglun()
{
	setfillstyle(1, WHITE);
	bar(0, 110, 640, 150);
	setfillstyle(1, LIGHTGRAY);
	bar(140, 110, 500, 150);
	setcolor(DARKGRAY);
	rectangle(120, 110, 240, 150);
}
//void showpinglun_afterinput(char* vn, int head, int tail)
//{
//	char fname[25] = "\0";
//	long move = 0L;
//	FILE* fp5;
//	int i = 0;
//	int j = 0;
//	int len = 0;
//	char user[20] = "\0";
//	char pinglun[100] = "\0";
//	char time_hs[10] = "\0";
//	char time_mins[10] = "\0";
//	strcat(fname, "videos\\pinglun");
//	strcat(fname, vn);
//	strcat(fname, ".dat");
//	if ((fp5 = fopen(fname, "rb+")) == NULL)//打开评论文件
//	{
//		closegraph();
//		printf("can't open pinglun file");
//		exit(1);
//	}
//	fseek(fp5, 0L, SEEK_END);
//	len = ftell(fp5) / (sizeof(user) + sizeof(pinglun) + sizeof(time_hs) + sizeof(time_mins));
//	fseek(fp5, 0L, SEEK_SET);
//	if (len < 1)
//	{
//		fclose(fp5);
//		return;
//	}
//	if (len <= 4)
//	{
//		for (i = 0; i < (len < 4 ? len : 4); i++)
//		{
//			fread(user, sizeof(user), 1, fp5);
//			fread(pinglun, sizeof(pinglun), 1, fp5);
//			fread(time_hs, sizeof(time_hs), 1, fp5);
//			fread(time_mins, sizeof(time_mins), 1, fp5);
//			//setviewport(0, 0, 640, 480, 0);
//			setcolor(LIGHTMAGENTA);
//			settextstyle(0, 0, 2);
//			outtextxy(40, 169 + i * 70, user);
//			outtextxy(40, 209 + i * 70, time_hs);
//			outtextxy(90, 209 + i * 70, time_mins);
//			puthz(40, 180 + i * 70, pinglun, 16, 20, LIGHTMAGENTA);
//			puthz(72, 200 + i * 70, "时", 16, 16, LIGHTMAGENTA);
//			puthz(125, 200 + i * 70, "分", 16, 16, LIGHTMAGENTA);
//			strcpy(user, "\0");
//			strcpy(pinglun, "\0");
//			strcpy(time_hs, "\0");
//			strcpy(time_mins, "\0");
//		}
//	}
//	else if (len > 4)
//	{
//		move = head * 140;
//		fseek(fp5, move, SEEK_SET);
//		for (j = head, i = 0; j <= tail; j++)
//		{
//			fread(user, sizeof(user), 1, fp5);
//			fread(pinglun, sizeof(pinglun), 1, fp5);
//			fread(time_hs, sizeof(time_hs), 1, fp5);
//			fread(time_mins, sizeof(time_mins), 1, fp5);
//			//setviewport(0, 0, 640, 480, 0);
//			setcolor(LIGHTMAGENTA);
//			settextstyle(0, 0, 2);
//			outtextxy(40, 169 + i * 70, user);
//			outtextxy(40, 209 + i * 70, time_hs);
//			outtextxy(90, 209 + i * 70, time_mins);
//			puthz(40, 180 + i * 70, pinglun, 16, 20, LIGHTMAGENTA);
//			puthz(72, 200 + i * 70, "时", 16, 16, LIGHTMAGENTA);
//			puthz(125, 200 + i * 70, "分", 16, 16, LIGHTMAGENTA);
//			strcpy(user, "\0");
//			strcpy(pinglun, "\0");
//			strcpy(time_hs, "\0");
//			strcpy(time_mins, "\0");
//			i++;
//		}
//	}
//	if (fclose(fp5) == -1)
//	{
//		closegraph();
//		printf("close file error in show\n");
//	}
//}
int getlen(char* vn)
{
	FILE* fp;
	char fname[25] = "\0";
	int len = 0;
	strcat(fname, "videos\\pinglun");
	strcat(fname, vn);
	strcat(fname, ".dat");
	fp = fopen(fname, "rb+");
	fseek(fp, 0L, SEEK_END);
	len = ftell(fp) / 140;
	fclose(fp);
	return len;
}