#include"public.h"
#include"ntlook.h"
void show_ntlook(int* page, USER* u,char*vn)
{
	int num = 0;
	char STK_ADR6[50] = { '\0' };
	FILE* fp1;
	int len;
	char abc[10];
	int k;
	int ab;
	
	
	char aaa[3]="\0";
	char mins[10] = "\0";
	char hs[10] = "\0";
	
	
	clrmous(MouseX, MouseY);
	delay(100);

	strcat(STK_ADR6, "Database\\USER\\");
	strcat(STK_ADR6, u->user);
	strcat(STK_ADR6, "\\NTLOOK.dat");
	if ((fp1 = fopen(STK_ADR6, "rb+")) == NULL)//建立数据库
	{
		printf("cannot open file");
		delay(3000);
		exit(1);
	}
	fseek(fp1, 0, SEEK_END);
	len = ftell(fp1) / (sizeof(aaa)+sizeof(mins)+sizeof(hs));
	cleardevice();//库函数

	/*itoa(len,abc,10);
	outtextxy(0,0,abc);*/

	base_draw_ntlook(fp1, len);
	base_draw_my_ntlook(u);



	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);

		for(k=0;k<len;k++)
		{
			if (MouseX > 24*3 && MouseX < 50 + 24 * 3 + 24*3+24 && MouseY>k*27 && MouseY <k*27+24)//
			{
				if (mouse_press(24*3,k*27,50 + 24 * 3 + 24*3+24,k*27+24) == 2)
				{
					if (num == 0)
					{
						MouseS = 1;
						fp1=fopen(STK_ADR6,"rb+");
						base_ntlook_lightbutton_login_information(24*3,k*27,50 + 24 * 3 + 24*3+24,k*27+24, WHITE, RED, 3,k,fp1,len);//color1为线颜色，color2为填充色
						num = 3;
						ab=k;
					}
					continue;
				}
				else if (mouse_press(24*3,k*27,50 + 24 * 3 + 24*3+24,k*27+24) == 1)
				{
					
					if ((fp1 = fopen(STK_ADR6, "rb+")) == NULL)//建立数据库
					{
						printf("cannot open file");
						delay(3000);
						exit(1);
					}
					fseek(fp1, k * (sizeof(aaa)+sizeof(mins)+sizeof(hs)), SEEK_SET);
					fread(aaa, sizeof(aaa), 1, fp1);//每次读一数据
					MouseS = 0;
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
					nt_del(STK_ADR6,u,len,k);
					if (fclose(fp1) != 0)
					{
						printf("\n cannot close Database.");
						delay(3000);
						exit(1);
					}
					
					return;
				}
			}
			
		}
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
		
		
		/*if (MouseX > 25 && MouseX < 110+25 && MouseY>300 && MouseY < 350)//编辑判定
		{
			if (mouse_press(25, 300, 110+25, 350) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					fp1=fopen(STK_ADR6,"rb+");
					base_collect_lightbutton_login_information(25, 300, 110+25, 350, WHITE, RED, 7,ab,fp1,len);//color1为线颜色，color2为填充色
					num = 7;
				}
				continue;
			}
			else if (mouse_press(25, 300, 110+25, 350) == 1)
			{
				MouseS = 0;
				*page = 22;//现在默认0首页
				return;
			}
		}*/
		
		if (MouseX > 24*3 && MouseX < 50 + 24 * 3 + 24*3+24 && MouseY>ab*27 && MouseY <ab*27+24)//收藏
		{
			if (mouse_press(24*3,ab*27,50 + 24 * 3 + 24*3+24,ab*27+24) == 2)
			{
				continue;
			}
		}

		if (num != 0)//点亮恢复
		{
			if (num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7)
			{
				fp1=fopen(STK_ADR6,"rb+");
				base_ntlook_recoverbutton_login_information(num,fp1,ab,len);
			}
			num = 0;
		}
		if (MouseS != 0)
			MouseS = 0;
	}
}
void base_draw_ntlook(FILE* fp1, int len)
{
	int i;
	char aaa[3]="\0";
	char mins[10] = "\0";
	char hs[10] = "\0";
	setbkcolor(WHITE);
	setcolor(WHITE);//blibli图案
	settextstyle(0, 0, 3);
	setfillstyle(1,LIGHTMAGENTA);

	for (i = 0; i < len; i++)
	{

		fseek(fp1, (len-i-1) * (sizeof(aaa)+sizeof(mins)+sizeof(hs)), SEEK_SET);
		fread(aaa, sizeof(aaa), 1, fp1);//每次读一数据
		bar(24*3,i*27,50 + 24 * 3 + 24*3+24,i*27+24);
		puthz(24 * 3, i * 27, "计划番剧", 24, 24 + 4, WHITE);
		outtextxy(50 + 24 * 3 + 24*3, i * 27, aaa);//
	}
	if (fclose(fp1) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
}
void base_draw_my_ntlook(USER* u)
{

	setbkcolor(WHITE);
	setcolor(LIGHTMAGENTA);

	setfillstyle(1, LIGHTMAGENTA);//稍后再看
	
	/*bar(25, 300, 25+110, 350);//返回
	puthz(25, 315, "编辑", 24, 4 + 24+10, WHITE);*/

	bar(420, 300, 530, 350);//返回
	puthz(425, 315, "返回", 24, 4 + 24, WHITE);

}
void base_ntlook_lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag,int k,FILE*fp1,int len)//按钮点亮
{

	char aaa[3]="\0";
	char mins[10] = "\0";
	char hs[10] = "\0";
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框
	
	switch (flag)
	{
		
		
		//rectangle(24*3,i*27,50 + 24 * 3 + 24*3+24,i*27+24)
	case 3:
	
		fseek(fp1,(len-k-1)*(sizeof(aaa)+sizeof(mins)+sizeof(hs)),SEEK_SET);
		fread(aaa,sizeof(aaa),1,fp1);

		puthz(24*3,k*27,"计划番剧", 24, 4 + 24, WHITE);
		outtextxy(50 + 24 * 3 + 24*3, k * 27, aaa);
		
		if (fclose(fp1) != 0)
		{
			printf("\n cannot close Database.");
			delay(3000);
			exit(1);
		}
		break;
	case 4:
		puthz(425, 315, "返回", 24, 4 + 24, WHITE);
		break;
		
	/*case 7:
		puthz(25, 315, "编辑", 24, 4 + 24+10, WHITE);
		break;*/
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}

}


void base_ntlook_recoverbutton_login_information(int status, FILE* fp1,int i,int len)//恢复
{
	char aaa[3]="\0";
	char mins[10] = "\0";
	char hs[10] = "\0";
	int k;
	k=i;
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
	case 3://
	
		setcolor(WHITE);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
	
	
		fseek(fp1,(len-k-1)*(sizeof(aaa)+sizeof(mins)+sizeof(hs)),SEEK_SET);
		fread(aaa,sizeof(aaa),1,fp1);
		fread(mins,sizeof(mins),1,fp1);
		fread(hs,sizeof(hs),1,fp1);

		bar(24*3,i*27,50 + 24 * 3 + 24*3+24,i*27+24);

		puthz(24*3,k*27,"计划番剧", 24, 4 + 24, WHITE);
		outtextxy(50 + 24 * 3 + 24*3, k * 27, aaa);
		if (fclose(fp1) != 0)
		{
			printf("\n cannot close Database.");
			delay(3000);
			exit(1);
		}
		break;
	case 4://登录
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(420, 300, 530, 350);
		puthz(425, 315, "返回", 24, 28, WHITE);
		
		if (fclose(fp1) != 0)
		{
			printf("\n cannot close Database.");
			delay(3000);
			exit(1);
		}
		break;
		
	/*case 7://编辑
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(25, 300, 25+110, 350);
		puthz(25, 315, "编辑", 24, 28+10, WHITE);
		if (fclose(fp1) != 0)
		{
			printf("\n cannot close Database.");
			delay(3000);
			exit(1);
		}
		break;*/
	
	}
}


void input_nt(int *page,USER*u,char*vn)
{
	
	
	int len;
	int judge;
	FILE* fp1;
	FILE* fp2;
	int i;
	int label;
	char num_pa[10];
	char c[3]="\0";

	char STK_ADR7[50] = { '\0' };
	
	
	time_t timep;
	int h, min;
	char aaa[3]="\0";
	char mins[10] = "\0";
	char hs[10] = "\0";
	struct tm* t;
	time(&timep);
	t = localtime(&timep);
	h = t->tm_hour;
	min = t->tm_min;
	itoa(h, hs, 10);
	itoa(min, mins, 10);//获取时间
	
	

	if (strlen(u->user) != 0)
	{
		strcat(STK_ADR7, "Database\\USER\\");
		strcat(STK_ADR7, u->user);
		strcat(STK_ADR7, "\\NTLOOK.DAT");
	}


	judge = control_judge(u);
	if (judge == 0)
	{
		cpop(judge);
		*page = 1;
		return;
	}

	if ((fp2 = fopen(STK_ADR7, "rb+")) == NULL)//建立数据库
	{
		printf("cannot open file");
		delay(3000);
		exit(1);
	}

	
	fseek(fp2,0,SEEK_END);
	len=ftell(fp2)/(sizeof(aaa)+sizeof(hs)+sizeof(mins));
	
	
	
	for (i=0;i<len;i++)
	{
		
		
		fseek(fp2,i*(sizeof(aaa)+sizeof(hs)+sizeof(mins)),SEEK_SET);
		fread(c,sizeof(aaa),1,fp2);
		if(strcmp(vn,c)==0)
		{

			if (fclose(fp2) != 0)
			{
				printf("\n cannot close Database.");
				delay(3000);
				exit(1);
			}
			
			clrmous(MouseX, MouseY);
			setfillstyle(SOLID_FILL, LIGHTMAGENTA);
			bar(190, 180, 410, 260);
			setfillstyle(SOLID_FILL, LIGHTMAGENTA);
			bar(190, 180, 410, 260);
			puthz(0 + 200, 0 + 200, "之前已添加", 16, 20+15, WHITE);
			delay(1500);
			*page = *page;
			return;
		}
		

	}
	fseek(fp2,0,SEEK_END);
	fwrite(vn,sizeof(aaa),1,fp2);
	fwrite(hs,sizeof(hs),1,fp2);
	fwrite(mins,sizeof(mins),1,fp2);
	if (fclose(fp2) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}

	clrmous(MouseX, MouseY);

	setfillstyle(SOLID_FILL, LIGHTMAGENTA);
	bar(190, 180, 410, 260);
	setfillstyle(SOLID_FILL, LIGHTMAGENTA);
	bar(190, 180, 410, 260);
	puthz(0 + 200, 0 + 200, "添加成功", 16, 20+20, WHITE);
	delay(1500);
	*page = *page;
	
}

void nt_del(char*STK_ADR6 ,USER*u,int len,int del_num)
{
	FILE*fp1;
	FILE*fp2;
	int i;
	char aaa[3]="\0";
	char mins[10] = "\0";
	char hs[10] = "\0";
	char STK_ADR7[50]="\0";

	strcat(STK_ADR7, "Database\\USER\\");
	strcat(STK_ADR7, u->user);
	strcat(STK_ADR7, "\\sub.dat");
	fp2=fopen(STK_ADR7,"wb+");
	fp1=fopen(STK_ADR6,"rb+");
	for (i=0;i<len;i++)
	{
		if(i==len-del_num-1)
		{
			continue;
		}
		fseek(fp1,i*(sizeof(aaa)+sizeof(mins)+sizeof(hs)),SEEK_SET);
		fseek(fp2,0,SEEK_END);
		fread(aaa,sizeof(aaa),1,fp1);
		fread(hs,sizeof(hs),1,fp1);
		fread(mins,sizeof(mins),1,fp1);
		
		
		fwrite(aaa,sizeof(aaa),1,fp2);
		fwrite(hs,sizeof(hs),1,fp2);
		fwrite(mins,sizeof(mins),1,fp2);
	
	
	}
	if (fclose(fp1) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
		
	if (fclose(fp2) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
	fp1=fopen(STK_ADR6,"wb+");
	fp2=fopen(STK_ADR7,"rb+");
	for (i=0;i<len-1;i++)
	{

		fseek(fp2,i*(sizeof(aaa)+sizeof(mins)+sizeof(hs)),SEEK_SET);
		fseek(fp1,0,SEEK_END);
		
		fread(aaa,sizeof(aaa),1,fp2);
		fread(hs,sizeof(hs),1,fp2);
		fread(mins,sizeof(mins),1,fp2);

		fwrite(aaa,sizeof(aaa),1,fp1);
		fwrite(hs,sizeof(hs),1,fp1);
		fwrite(mins,sizeof(mins),1,fp1);
	
	}
	if (fclose(fp1) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
		
	if (fclose(fp2) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
	
	
}
