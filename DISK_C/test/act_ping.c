#include"public.h"
#include"act_ping.h"
void act_ping_base(int *page,USER* u)
{
	int num = 0;
	FILE*fp1;
	int len;
	char STK[50]="\0";
	
	char aaa[3]="\0";
	char pinglun[100] = "\0";
	char mins[10] = "\0";
	char hs[10] = "\0";
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();//
	strcpy(STK, "Database\\USER\\");     
	strcat(STK, u->user);
	strcat(STK, "\\PLUN.dat");

	if ((fp1 = fopen(STK, "rb+")) == NULL)//建立数据库
	{
		printf("cannot open file");
		delay(3000);
		exit(1);
	}
	fseek(fp1,0,SEEK_END);
	len=ftell(fp1)/(sizeof(aaa)+sizeof(pinglun)+sizeof(mins)+sizeof(hs));
	fseek(fp1,0,SEEK_SET);
	draw_ping(fp1,len);
	base_ping_draw_action(u);
	if (fclose(fp1) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
	
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		
		if (MouseX > 420 && MouseX < 530 && MouseY>300 && MouseY < 350)//返回
		{
			if (mouse_press(420, 300, 530, 350) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					base_ping_action_lightbutton_login_information(420, 300, 530, 350, RED, RED, 5);//边框，填充
					num = 5;
				}
				continue;
			}
			else if (mouse_press(420, 300, 530, 350) == 1)
			{
				MouseS = 0;
				*page = 9;//
				return;
			}
		}
		if (num != 0)//
		{
			if (num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7)
			{
				base_ping_action_recoverbutton_login_information(num);
			}
			num = 0;
		}
		if (MouseS != 0)
			MouseS = 0;
	}
}




void draw_ping(FILE*fp1,int len)
{
	int i;
	
	
	char aaa[3]="\0";
	char pinglun[100] = "\0";
	char mins[10] = "\0";
	char hs[10] = "\0";
	
	
	
	setbkcolor(WHITE);
	setcolor(WHITE);
	setfillstyle(1, LIGHTMAGENTA);//
	settextstyle(0, 0, 2);

	
	
	for (i=0;i<len;i++)
	{
		fread(aaa, sizeof(aaa), 1, fp1);
		fread(hs, sizeof(hs), 1, fp1);
		fread(mins, sizeof(mins), 1, fp1);
		fread(pinglun, sizeof(pinglun), 1, fp1);
		
		
		bar(16 * 3, i * 17, 16 * 4 * 4 + 25+24+100+100, i * 16+16);
		//bar(24 * 3, i * 27, 24 * 4 * 4 + 25+24, i * 27+24);//返回
		puthz(16 * 3, i*17, "番剧", 16, 18, WHITE);//84
		puthz(115, i*17, "评论于", 16, 18, WHITE);
		puthz(170+20+10, i*17, "时", 16, 18, WHITE);
		puthz(190+20+20+10, i*17, "分", 16, 18, WHITE);//230
		puthz(230+20+10, i*17, "内容为：", 16, 18, WHITE);//284

		outtextxy(85, i*17, aaa);//110
		outtextxy(170, i*17, hs);//
		outtextxy(190+15+10, i*17, mins);//
		puthz(290+20+10+20,i*17,pinglun,16, 18, WHITE);
		
	}
	

	
}

void base_ping_draw_action(USER* u)
{

	setbkcolor(WHITE);
	setcolor(LIGHTMAGENTA);
	setfillstyle(1, LIGHTMAGENTA);//

	bar(420, 300, 530, 350);//
	puthz(425, 315, "返回", 24, 4 + 24, WHITE);

}
void base_ping_action_lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag)//点亮
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
	case 5:
		puthz(425, 315, "返回", 24, 4 + 24, WHITE);
		break;
	
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}

}


void base_ping_action_recoverbutton_login_information(int status)//恢复
{
	clrmous(MouseX, MouseY);
	switch (status)
	{
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