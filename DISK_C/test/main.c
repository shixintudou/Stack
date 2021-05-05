#include"main.h"
#include"public.h"
#include"plv.h"
#include<string.h>
int main()
{
	int page = 0;
	int i = 0;
	int gd = VGA, gm = VGAHI;
	/*char number[3] = "\0";
	char name[18] = "\0";
	char dbm[18] = "\0";
	int t = 1;*/
	USER u;
	VIDEO v;
	char vn[3] = "\0";
	memset(&u, '\0', sizeof(USER));
	memset(&v, '\0', sizeof(VIDEO));
	initgraph(&gd, &gm, "C:\\BORLANDC\\BGI");
	/*for (i = 0; i < 686; i++)
	{
		itoa(t, number, 10);
		strcat(name, "d160\\");
		strcat(name, number);
		strcpy(dbm, name);
		strcat(dbm, ".dat");
		strcat(name, ".bmp");
		bmp_convert(name, dbm);
		t++;
		strcpy(number, "\0");
		strcpy(name, "\0");
		strcpy(dbm, "\0");
	}*/
	//welcome_page();	//»¶Ó­½çÃæ
	mouseinit();
	while (1)
	{
		switch (page)
		{
		case 0:
			main_page(&page,vn);//Ö÷Ò³
			break;
		case 1:
			login_main(&page, &u);//µÇÂ¼
			break;
		case 2:
			register_main(&page);//×¢²á
			break;
		case 3:
			my_information(&page, &u);
			break;
		case 4:
			show_main(&page,vn, &u);//ÊÓÆµ²¥·Å
			break;
		case 5:
			main_base(&page, &u);
			break;
		case 6:
			show_history(&page, &u,vn);
			break;
		case 7:
			show_collect(&page, &u);
			break;
		case 8:
			show_ntlook(&page,&u,vn);
			break;
		case 9:
			action_base(&page,&u);
			break;
		case 11:
			tj_page(&page, vn);
			break;
		case 12:
			fg_page(&page, vn);
			break;
		case 13:
			rm_page(&page, vn);
			break;
		case 21:
			show_sub_history(&page, &u,vn);
			break;
		case 22:
			show_sub_collect(&page, &u,vn);
			break;
		case 23:
			act_ping_base(&page,&u);
			break;
		case 24:
			act_dan_base(&page,&u,vn);
			break;
		
		}
		
	}
	closegraph();
	return 0;
}