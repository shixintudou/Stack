#include"public.h"
#include"sub_show.h"
void input_his(USER* u, char* vn)
{
	HIS* bh;
	COLL* c;
	int judge;
	FILE* fp1;
	FILE* fp2;
	time_t timep;
	int h, min;
	char mins[10];
	char hs[10];
	char num_pa[10];

	char STK_ADR6[50] = { '\0' };
	struct tm* t;
	time(&timep);
	t = localtime(&timep);
	h = t->tm_hour;
	min = t->tm_min;
	itoa(h, hs, 10);
	itoa(min, mins, 10);
	if (strlen(u->user) != 0)
	{
		strcat(STK_ADR6, "Database\\USER\\");
		strcat(STK_ADR6, u->user);
		strcat(STK_ADR6, "\\history.dat");
		if ((fp1 = fopen(STK_ADR6, "rb+")) == NULL)//建立数据库
		{
			printf("cannot open file");
			delay(3000);
			exit(1);
		}
		if ((bh = (HIS*)malloc(sizeof(HIS))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		memset(bh, '\0', sizeof(HIS));
		strcpy(bh->name, vn);
		strcpy(bh->now_hour, hs);
		strcpy(bh->now_min, mins);
		fseek(fp1, 0, SEEK_END);//跳转至文件末尾
		fwrite(bh, sizeof(HIS), 1, fp1);//把用户信息写入文件 余额默认为0


		if (fclose(fp1) != 0)
		{
			printf("\n cannot close Database.");
			delay(3000);
			exit(1);
		}
	}
}
void input_coll(USER* u, char* vn,int*page)
{

	HIS* bh;
	COLL* c;
	int len;
	int judge;
	FILE* fp1;
	FILE* fp2;
	int i;
	int label;
	char num_pa[10];

	char STK_ADR7[50] = { '\0' };

	if (strlen(u->user) != 0)
	{
		strcat(STK_ADR7, "Database\\USER\\");
		strcat(STK_ADR7, u->user);
		strcat(STK_ADR7, "\\COLLECT.DAT");
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
	len=ftell(fp2)/sizeof(COLL);
	
	
	
	for (i=0;i<len;i++)
	{
		if ((c = (COLL*)malloc(sizeof(COLL))) == NULL)
		{
		printf("memoryallocation runs wrong in lgfunc.c");
		delay(3000);
		exit(1);
		}
		
		fseek(fp2,i*sizeof(COLL),SEEK_SET);
		fread(c,sizeof(COLL),1,fp2);
		if(strcmp(vn,c->name)==0)
		{
			if (c != NULL)
			{
				free(c);
				c = NULL;
			}

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
			puthz(0 + 200, 0 + 200, "之前已收藏", 16, 20+15, WHITE);
			delay(1500);
			*page = *page;
			return;
		}
		
		if (c != NULL)
		{
			free(c);
			c = NULL;
		}

	}
	
	
	
	if ((c = (COLL*)malloc(sizeof(COLL))) == NULL)
	{
	printf("memoryallocation runs wrong in lgfunc.c");
	delay(3000);
	exit(1);
	}

	memset(c, '\0', sizeof(COLL));
	itoa(*page, num_pa, 10);
	strcpy(c->name, vn);
	strcpy(c->num_page, num_pa);





	fseek(fp2, 0, SEEK_END);//跳转至文件末尾
	fwrite(c, sizeof(COLL), 1, fp2);//把用户信息写入文件 余额默认为0



	if (c != NULL)
	{
		free(c);
		c = NULL;
	}
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
	puthz(0 + 200, 0 + 200, "收藏成功", 16, 20+20, WHITE);
	delay(1500);
	//*page = *page;

}