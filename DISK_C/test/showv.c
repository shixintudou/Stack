#include"showv.h"
#include<string.h>
#include"vifunc.h"
#include"public.h"
#include"sub_show.h"
#include"pinglun.h"
#include"ntlook.h"
void show_main(int* page,char* vn,USER* u)
{
	//int isinput = 0;//0为未输入过,1为输入过
	

	int i = 1;//视频播放数字,表示播放进程
	int num = 0;
	int state = 0;//0为播放中，1为暂停中
	char danmu[18] = "\0";//弹幕文件名
	char dbm[18] = "\0";//视频名
	char number[4] = "\0";//视频编号字符
	char index[15][4];//弹幕索引，存储弹幕放送时间,已经过排序
	char danmus[15][100];//弹幕内容
	int p[15] = { 0 };//弹幕横向位置
	int len;
	int ind = 0;//待播放的弹幕
	int temp[15] = { 0 };//弹幕状态
	int state1[15] = { 0 };//弹幕位置是否生成
	int dxy[15][3] = { 0,0,0 };//弹幕位置及颜色
	int j[15];
	FILE* fp;
	input_his(u, vn);
	strcat(danmu, "videos\\danmu");
	strcat(danmu, vn);
	strcat(danmu, ".dat");
	fp = fopen(danmu, "rb+");//打开弹幕文件
	fseek(fp, 0L, SEEK_END);
	len = ftell(fp) / 104;
	fseek(fp, 0L, SEEK_SET);
	if (len > 0)//如果文件不为空
	{
		srand((unsigned)time(NULL));
		for (i = 0; i < len; i++)
		{
			strcpy(danmus[i], "\0");//初始化弹幕数组
			strcpy(index[i], "\0");
		}
		for (i = 0; i < len; i++)
		{
			fread(index[i], sizeof(index[i]), 1, fp);//读取弹幕内容
			fread(danmus[i], sizeof(danmus[i]), 1, fp);
		}
		i = 1;
	}
	fclose(fp);
	setcolor(GREEN);
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	setfillstyle(1, GREEN);
	bar(0, 351, 1, 353);
	drawshow();
	showzan(vn);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		/*puthz(j, 240, "哈哈哈", 16, 20, BLUE);
		delay(50);
		setfillstyle(1, WHITE);
		bar(j, 220, 640, 260);
		j += 16;*/
		if (state == 0)//播放视频
		{
			strcpy(dbm, "\0");
			strcpy(number, "\0");
			strcat(dbm, vn);
			strcat(dbm, "\\");
			itoa(i, number, 10);
			strcat(dbm, number);
			strcat(dbm, ".dat");
			i++;
			show_dbm(80, 80, dbm);
			delay(30);
			setfillstyle(1, GREEN);
			bar(0, 351, (int)(i * (640.0 / 686)), 353);
			if (i > 686)
			{
				i = 1;
				state = 1;
				recoverbutton_show(2);
				setfillstyle(1, WHITE);
				bar(0, 351, 640, 353);
			}
			if (len > 0)
			{
				for (ind = 0; ind < len; ind++)
				{
					if (atoi(index[ind]) == i)//播放弹幕
					{
						if (state1[ind] == 0)
						{
							dxy[ind][0] = rand() % 2;//边
							dxy[ind][1] = rand() % 60 + 10;//纵坐标
							dxy[ind][2] = rand() % 14 + 1;//颜色
							if (dxy[ind][0] == 0)
								p[ind] = 0;
							if (dxy[ind][0] == 1)
								p[ind] = 600 - strlen(danmus[ind]);
							state1[ind] = 1;
						}
					}
					if (state1[ind] == 1)
					{
						j[ind] = showdanmu(dxy[ind][0], dxy[ind][1], dxy[ind][2], danmus[ind], &p[ind]);
						if (j[ind] == 1)
						{
							setfillstyle(1, WHITE);
							bar(0, dxy[ind][1] - 150, 640, dxy[ind][1] + 180);
							state1[ind] = 0;
							drawshow();
						}
						delay(50);
					}
				}
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
				delay(100);
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
			else if (mouse_press(450, 390, 540, 430) == 1)
			{
				MouseS = 0;
				input_coll(u, vn, page);
				

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
				state = 1;
				delay(50);
				log_judge(u,number,vn);
				state = 0;
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
				pinglun_main(u, &i, vn, &state);
				showzan(vn);
			}
		}
		if (MouseX > 450 && MouseX < 540 && MouseY>440 && MouseY < 470)//点赞按钮
		{
			if (mouse_press(450, 440, 540, 470) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_show(RED, RED, 7);
					num = 7;
				}
				continue;
			}
			else if (mouse_press(450, 440, 540, 470) == 1)
			{
				if (strlen(u->user) == 0)
				{
					pleaselog();
					showzan(vn);
					
					
					
				}
				else
				{
					MouseS = 0;
					addzan(vn);
					showzan(vn);
					delay(30);
				}				
			}
		}
		if (MouseX > 360 && MouseX < 430 && MouseY>390 && MouseY < 450)//稍后再看按钮
		{
			if (mouse_press(360, 390, 430, 450) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_show(RED, RED, 8);
					num = 8;
				}
				continue;
			}
			else if (mouse_press(360, 390, 430, 450) == 1)
			{
				MouseS = 0;
				input_nt(page,u,vn);
				
			}
		}
		if (num != 0)
		{
			if (state == 0)
				recoverbutton_show(1);
			if (state == 1)
				recoverbutton_show(2);
			if (num == 3 || num == 4 || num == 5 || num == 6||num== 7||num== 8)
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

	bar(450, 440, 540, 470);
	puthz(468, 445, "点赞", 24, 30, WHITE);
	settextstyle(0, 0, 2);
	outtextxy(550, 450, "x");

	bar(360, 390, 430, 450);
	puthz(370, 394, "稍后", 24, 30, WHITE);
	puthz(370, 423, "再看", 24, 30, WHITE);
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
	case 7:
		bar(450, 440, 540, 470);
		puthz(468, 445, "点赞", 24, 30, WHITE);
		break;
	case 8:
		bar(360, 390, 430, 450);
		puthz(370, 394, "稍后", 24, 30, WHITE);
		puthz(370, 423, "再看", 24, 30, WHITE);
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
	case 7:
		setfillstyle(1, LIGHTMAGENTA);
		bar(450, 440, 540, 470);
		puthz(468, 445, "点赞", 24, 30, WHITE);
		break;
	case 8:
		setfillstyle(1, LIGHTMAGENTA);
		bar(360, 390, 430, 450);
		puthz(370, 394, "稍后", 24, 30, WHITE);
		puthz(370, 423, "再看", 24, 30, WHITE);
		break;
	}
}
void addzan(char* vn)
{
	FILE* fp;
	int zan = 0;
	char fname[25] = "\0";
	strcat(fname, "videos\\dianzan");
	strcat(fname, vn);
	strcat(fname, ".dat");
	fp = fopen(fname, "rb+");
	if (fp == NULL)
	{
		closegraph();
		printf("open dianzan file error");
		exit(1);
	}
	fread(&zan, sizeof(int), 1, fp);
	zan++;
	fclose(fp);
	fopen(fname, "wb+");
	fwrite(&zan, sizeof(int), 1, fp);
	fclose(fp);
}
void showzan(char* vn)
{
	FILE* fp;
	int zan = 0;
	char zans[4] = "\0";
	char fname[25] = "\0";
	strcat(fname, "videos\\dianzan");
	strcat(fname, vn);
	strcat(fname, ".dat");
	fp = fopen(fname, "rb+");
	if (fp == NULL)
	{
		closegraph();
		printf("open dianzan file error");
		exit(1);
	}
	fread(&zan, sizeof(int), 1, fp);
	fclose(fp);
	if (zan == NULL)
		zan = 0;
	itoa(zan,zans, 10);
	setcolor(LIGHTRED);
	setfillstyle(1, WHITE);
	bar(569, 440, 600, 470);
	outtextxy(570, 450, zans);
}