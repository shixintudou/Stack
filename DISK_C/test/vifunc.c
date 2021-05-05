#include"vifunc.h"
#include<string.h>
void log_judge(USER* u,char* number,char* vn)
{
	FILE* fp,*fp6;
	
	char SKT[50]="\0";

	char s[100] = "\0";
	int LEN = 0;
	char name[18] = "\0";
	
	
	char aaa[3]="\0";
	
	
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
	strcat(SKT, "\\DMU.dat");
	
	
	strcat(name, "videos\\danmu");
	strcat(name, vn);
	strcat(name, ".dat");
	setfillstyle(1, LIGHTGRAY);
	bar(590, 0, 640, 50);          //遮盖
	if (strlen(u->user) == 0)
	{
		pleaselog();
	}
	else
	{
		drawinput();
		LEN=hz_input(240, 390, 400, 420, s, LEN, WHITE);
		settextjustify(0,2);
		if (LEN != 0)
		{
			
			
			
			if ((fp6 = fopen(SKT, "rb+")) == NULL)//打开评论文件
			{
				printf("can't open pinglun file");
				exit(1);
			}
		
			fseek(fp6, 0L, SEEK_END);
			fwrite(vn, sizeof(aaa), 1, fp6);
			fwrite(hs, sizeof(hs), 1, fp6);
			fwrite(mins, sizeof(mins), 1, fp6);
			fwrite(s, sizeof(s), 1, fp6);
		
			if (fclose(fp6) != 0)
			{
				printf("\n cannot close Database.");
				delay(3000);
				exit(1);
			}
			
			
			
			if ((fp = fopen(name, "rb+")) == NULL)
			{
				printf("can't open file");
				closegraph();
				exit(1);
			}
			fseek(fp, 0L, SEEK_END);
			fwrite(number, sizeof(number), 1, fp);
			fwrite(s, sizeof(s), 1, fp);
			fclose(fp);
			sort(name);
		}
		cleardevice();
		drawshow();
	}
}
void pleaselog()
{
	clrmous(MouseX, MouseY);
		setfillstyle(1, LIGHTMAGENTA);
		bar(180, 150, 460, 330);
		setfillstyle(1, LIGHTMAGENTA);
		bar(200, 170, 440, 310);
		puthz(250, 200, "请先登录", 16, 20, WHITE);
		delay(1000);
		cleardevice();
		drawshow();
}
void drawinput()
{
	setcolor(WHITE);
	bar(0, 350, 640, 480);
	setcolor(LIGHTGRAY);
	bar(240, 390, 400, 420);
	setcolor(DARKGRAY);
	rectangle(240, 390, 400, 420);
}
void sort(char* danmu)//弹幕排序
{
	char danmus[15][104];
	char index[15][4];
	char temp[104] = "\0";
	int len = 0;
	int i = 0, j = 0;
	FILE* fp;
	fp = fopen(danmu, "rb+");
	fseek(fp, 0L, SEEK_END);
	len = ftell(fp) / 104;
	fseek(fp, 0L, SEEK_SET);
	if (len <= 1)
	{
		fclose(fp);
		return;
	}		
	for (i = 0; i < 15; i++)
	{
		strcpy(danmus[i], "\0");
		strcpy(index[i], "\0");
	}
	for (i = 0; i < len; i++)
	{
		fread(danmus[i], sizeof(danmus[i]), 1, fp);
	}
	fseek(fp, 0L, SEEK_SET);
	for (i = 0; i < len; i++)
	{
		fread(index[i], sizeof(index[i]), 1, fp);
		fseek(fp, 100L, SEEK_CUR);
	}
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (atoi(index[j])>atoi(index[j+1]))
			{
				strcpy(temp, danmus[j]);
				strcpy(danmus[j], danmus[j + 1]);
				strcpy(danmus[j + 1], temp);
			}
		}
	}
	fclose(fp);
	fp = fopen(danmu, "wb+");
	for (i = 0; i < len; i++)
	{
		fwrite(danmus[i], sizeof(danmus[i]), 1, fp);
	}
	fclose(fp);
}
int showdanmu(int side, int y, int color, char* s,int* p)
{
	setfillstyle(1, WHITE);
	switch (side)
	{
	case 0://从左开始
		*p += 16;
		puthz(*p, y, s, 16, 20, color);
		delay(100);
		bar(*p - 5, y + 15, 640, y - 15);
		if (*p > 600)
			return 1;
		else
			return 0;
		break;
	case 1://从右开始
		*p -= 16;
		puthz(*p, y, s, 16, 20, color);
		delay(100);
		bar(*p-5 , y + 15, 640, y - 15);
		if (*p < 40)
			return 1;
		else
			return 0;
		break;
	default:
		closegraph();
		printf("side error!\n");
		break;
	}
}