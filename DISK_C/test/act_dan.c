#include"public.h"
#include"act_dan.h"
void act_dan_base(int *page,USER* u,char *vn)
{
	int num = 0;
	FILE*fp1;
	int len;
	int ab;
	char STK[50]="\0";
	int i;
	char aaa[3]="\0";
	char danmu[100] = "\0";
	char mins[10] = "\0";
	char hs[10] = "\0";
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();//
	strcpy(STK, "Database\\USER\\");     
	strcat(STK, u->user);
	strcat(STK, "\\DMU.dat");

	if ((fp1 = fopen(STK, "rb+")) == NULL)//建立数据库
	{
		printf("cannot open file");
		delay(3000);
		exit(1);
	}
	fseek(fp1,0,SEEK_END);
	len=ftell(fp1)/(sizeof(aaa)+sizeof(danmu)+sizeof(mins)+sizeof(hs));
	fseek(fp1,0,SEEK_SET);
	draw_dan(fp1,len);
	base_dan_draw_action(u);
	
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);

			//bar(16 * 3, i * 17, 16 * 4 * 4 + 25+24+100+100, i * 17+16);

		/*for (i=0;i<len;i++)
		{
			if (MouseX > 16 * 3 && MouseX < 16 * 4 * 4 + 25+24+100+100 && MouseY>i * 17&& MouseY < i * 17+16)//返回
			{
				if (mouse_press(16 * 3, i * 17, 16 * 4 * 4 + 25+24+100+100, i * 17+16) == 2)
				{
					if (num == 0)
					{
						MouseS = 1;
						base_dan_action_lightbutton_login_information(16 * 3, i * 17, 16 * 4 * 4 + 25+24+100+100, i * 17+16, WHITE, RED, 3,u,fp1);//边框，填充
						num = 3;
						ab=i;
					}
					continue;
				}
				else if (mouse_press(16 * 3, i * 17, 16 * 4 * 4 + 25+24+100+100, i * 17+16) == 1)
				{
					MouseS = 0;
					fseek(fp1,i*(sizeof(aaa)+sizeof(danmu)+sizeof(mins)+sizeof(hs)),SEEK_SET);
					fread(aaa, sizeof(aaa), 1, fp1);
					fread(hs, sizeof(hs), 1, fp1);
					fread(mins, sizeof(mins), 1, fp1);
					fread(danmu, sizeof(danmu), 1, fp1);
					strcpy(vn, aaa);
					strcpy(vn, aaa);
					strcpy(vn, aaa);
					strcpy(vn, aaa);
					strcpy(vn, aaa);
					strcpy(vn, aaa);
					*page = 4;
					*page = 4;
					*page = 4;
					*page = 4;
					*page = 4;
					*page = 4;
					*page = 4;
					*page = 4;
					
					if (fclose(fp1) != 0)
					{
						printf("\n cannot close Database.");
						delay(3000);
						exit(1);
					}
					
					return;
				}
			}
			
			
		}*/
		
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
				if (fclose(fp1) != 0)
				{
					printf("\n cannot close Database.");
					delay(3000);
					exit(1);
				}
				return;
			}
		}
		
		if (MouseX > 16 * 3 && MouseX < 16 * 4 * 4 + 25+24+100+100 && MouseY>ab * 17&& MouseY < ab * 17+16)//返回
		{
			if (mouse_press(16 * 3, ab * 17, 16 * 4 * 4 + 25+24+100+100, ab * 17+16) == 2)
			{
				
				continue;
			}
		}
		if (num != 0)//
		{
			if (num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7)
			{
				base_dan_action_recoverbutton_login_information(num,fp1,ab);
			}
			num = 0;
		}
		if (MouseS != 0)
			MouseS = 0;
	}
}




void draw_dan(FILE*fp1,int len)
{
	int i;
	char STK[50]="\0";

	
	char aaa[3]="\0";
	char danmu[100] = "\0";
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
		fread(danmu, sizeof(danmu), 1, fp1);
		
		
		bar(16 * 3, i * 17, 16 * 4 * 4 + 25+24+100+100, i * 17+16);
		//bar(24 * 3, i * 27, 24 * 4 * 4 + 25+24, i * 27+24);//返回
		puthz(16 * 3, i*17, "在番剧", 16, 18, WHITE);//84
		puthz(115+20, i*17, "发弹幕于", 16, 18, WHITE);
		puthz(170+20+10+40, i*17, "时", 16, 18, WHITE);
		puthz(190+20+20+10+40, i*17, "分", 16, 18, WHITE);//230
		puthz(230+20+10+40, i*17, "内容为：", 16, 18, WHITE);//284

		outtextxy(85+20, i*17, aaa);//110
		outtextxy(170+40, i*17, hs);//
		outtextxy(190+15+10+40, i*17, mins);//
		puthz(290+20+10+20+40,i*17,danmu,16, 18, WHITE);
		
	}
	

	
}

void base_dan_draw_action(USER* u)
{

	setbkcolor(WHITE);
	setcolor(LIGHTMAGENTA);
	setfillstyle(1, LIGHTMAGENTA);//

	bar(420, 300, 530, 350);//
	puthz(425, 315, "返回", 24, 4 + 24, WHITE);

}
void base_dan_action_lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag,USER*u,FILE*fp1)//点亮
{

    int i;
	char aaa[3]="\0";
	char danmu[100] = "\0";
	char mins[10] = "\0";
	char hs[10] = "\0";
	i=y/17;
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
	/*case 3:
	
	fseek(fp1,i*(sizeof(aaa)+sizeof(danmu)+sizeof(mins)+sizeof(hs)),SEEK_SET);
	settextstyle(0, 0, 2);

	fread(aaa, sizeof(aaa), 1, fp1);
	fread(hs, sizeof(hs), 1, fp1);
	fread(mins, sizeof(mins), 1, fp1);
	fread(danmu, sizeof(danmu), 1, fp1);
	
	
	bar(16 * 3, i * 17, 16 * 4 * 4 + 25+24+100+100, i * 17+16);
	//bar(24 * 3, i * 27, 24 * 4 * 4 + 25+24, i * 27+24);//返回
	puthz(16 * 3, i*17, "在番剧", 16, 18, WHITE);//84
	puthz(115+20, i*17, "发弹幕于", 16, 18, WHITE);
	puthz(170+20+10+40, i*17, "时", 16, 18, WHITE);
	puthz(190+20+20+10+40, i*17, "分", 16, 18, WHITE);//230
	puthz(230+20+10+40, i*17, "内容为：", 16, 18, WHITE);//284

	outtextxy(85+20, i*17, aaa);//110
	outtextxy(170+40, i*17, hs);//
	outtextxy(190+15+10+40, i*17, mins);//
	puthz(290+20+10+20+40,i*17,danmu,16, 18, WHITE);*/
	
		
	
	

	
	case 5:
		puthz(425, 315, "返回", 24, 4 + 24, WHITE);
		break;
	
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}

}


void base_dan_action_recoverbutton_login_information(int status,FILE*fp1,int ab)//恢复
{
	int i;
	char aaa[3]="\0";
	char danmu[100] = "\0";
	char mins[10] = "\0";
	char hs[10] = "\0";
	i=ab;
	clrmous(MouseX, MouseY);
	switch (status)
	{
		
	/*case 3:
		setcolor(WHITE);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		fseek(fp1,i*(sizeof(aaa)+sizeof(danmu)+sizeof(mins)+sizeof(hs)),SEEK_SET);
		settextstyle(0, 0, 2);

		fread(aaa, sizeof(aaa), 1, fp1);
		fread(hs, sizeof(hs), 1, fp1);
		fread(mins, sizeof(mins), 1, fp1);
		fread(danmu, sizeof(danmu), 1, fp1);
		
		
		bar(16 * 3, i * 17, 16 * 4 * 4 + 25+24+100+100, i * 17+16);
		//bar(24 * 3, i * 27, 24 * 4 * 4 + 25+24, i * 27+24);//返回
		puthz(16 * 3, i*17, "在番剧", 16, 18, WHITE);//84
		puthz(115+20, i*17, "发弹幕于", 16, 18, WHITE);
		puthz(170+20+10+40, i*17, "时", 16, 18, WHITE);
		puthz(190+20+20+10+40, i*17, "分", 16, 18, WHITE);//230
		puthz(230+20+10+40, i*17, "内容为：", 16, 18, WHITE);//284

		outtextxy(85+20, i*17, aaa);//110
		outtextxy(170+40, i*17, hs);//
		outtextxy(190+15+10+40, i*17, mins);//
		puthz(290+20+10+20+40,i*17,danmu,16, 18, WHITE);*/
		
		
	
	
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