
#include"lgfunc.h"
#include"mouse.h"
#include"hz.h"
#include"public.h"
#include"database.h"
#include<string.h>
/*********************************************
FUNCTION:inputadmin
***********************************************/
void inputadmin(char* id, int x1, int y1, int charnum, int color)//输入的字符串，输入的xy，输入的字符限制，输入框的颜色
{
	int k = 0;
	int i = 0;
	char t;
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
	while (bioskey(1))
	{
		k = bioskey(0);//吃
	}
	while (1)
	{

		t = bioskey(0);
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //遮盖光标
					outtextxy(x1 + 8 + i * 18, y1 - 1, id + i);//输出t字符(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标  
				break;
			}
		}
	}
}
/*********************************************
FUNCTION:inputpassword
DESCRIPTION：函数功能：输入密码等需要隐藏的信息
INPUT:id,x1,y1,charnum,color
RETURN:无
***********************************************/
void inputpassword(char* id, int x1, int y1, int charnum, int color)
{
	int k = 0;
	int i = 0;
	char t;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
	while (bioskey(1))
	{
		k = bioskey(0);//吃
	}
	while (1)
	{
		t = bioskey(0);//读取键值
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//033表示Esc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
					outtextxy(x1 + 8 + i * 18, y1 + 4, "*");//输出*字符
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 22);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 22);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
				break;
			}
		}
	}
}

///*********************************************
//FUNCTION:login_complete
//DESCRIPTION：用来判断登录信息是否输入完全和正确
//INPUT:u,p
//RETURN:1/0
//***********************************************/
int login_complete(char* u, char* p)
{
	int state1 = 1;//是否输入的变量
	int state2 = 1;
	while (1)
	{
		recoverhz(557, 150, BLACK);
		recoverhz(557, 190, BLACK);
		judge(u, &state1, 557, 150);
		judge(p, &state2, 557, 190);
		if (state1 == 1 || state2 == 1)
		{
			break;
		}
		else if (state1 == 0 && state2 == 0)
		{
			if (judge_rightpassword(u, p))
			{
				return 1;
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}
/*********************************************
//FUNCTION:register_complete
//DESCRIPTION：用来判断注册信息是否输入完全和正确
//INPUT : u, p, cp, id, vc, rdvc, b, bp
//RETURN : 1 / 0
//* **********************************************/
int register_complete(char* u, char* p, char* cp, char* id,char* b)//rdvc为randomvc
{
	int i;
	int state = 0;
	int state1 = 1;
	int state2 = 1;
	int state3 = 1;
	int state4 = 1;
	while (1)
	{
		recoverhz(557, 105, BLACK);
		recoverhz(557, 145, BLACK);
		recoverhz(557, 185, BLACK);
		recoverhz(557, 225, BLACK);
		recoverhz(557, 265, BLACK);
		recoverhz(19, 190, BLACK);
		recoverhz(280, 440, BLACK);
		judge(id, &state, 557, 115);          //judge:未输入就state=1
		judge(b, &state, 557, 155);
		judge(u, &state, 557, 195);
		judge(p, &state, 557, 235);
		judge(cp, &state, 557, 275);
		if (state == 1)
		{
			break;
		}
		else if (state == 0)
		{
			if (!judge_sameuser(u, 1))          //  重名则返回0，未重名返回1
			{
				state1 = checkright_user(u, 557, 185);
				state2 = checkright_password(p, 557, 225);
				state3 = checkright_confirmedpassword(p, cp, 557, 265);
				state4 = checkright_ID(id, 557, 105, 1);
				break;
			}
			else if (judge_sameuser(u, 2))//账号没有重名
			{
				puthz(20, 190, "可用的账号", 16, 17, RED);
				state1 = checkright_user(u, 557, 185);
				state2 = checkright_password(p, 557, 225);
				state3 = checkright_confirmedpassword(p, cp, 557, 265);
				state4 = checkright_ID(id, 557, 105, 1);
				if (state1 != 0 || state2 != 0 || state3 != 0 || state4 != 0 )
				{
					break;
				}
				else if (state1 == 0 && state2 == 0 && state3 == 0 && state4 == 0 )
				{
					input_database(u, id, p, b);
					//写入数据库
					puthz(280, 440, "注册成功", 16, 17, RED);
					delay(2000);
 				return 1;//返回
				}
			}
		}
	}
	return 0;
}

///*********************************************
//FUNCTION:judge_rightpassword
//DESCRIPTION：判断账号和密码是否匹配
//	匹配则登录
//INPUT:name,id,pass,againpass
//RETURN:1/0
//***********************************************/
int judge_rightpassword(char* name, char* pass)
{
	int len;
	int i;
	FILE* fp;
	USER* u;
	if ((fp = fopen("database\\UserData.dat", "rb+")) == NULL)
	{
		printf("cannot open file UserData.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(name, u->ID)-strcmp(name,u->password)== 0)//账号匹配
		{
			if (strcmp(pass, u->password)-strcmp(pass,u->phone)!= 0)//密码不配
			{
				puthz(560, 190, "密码错误", 16, 17, RED);
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				break;
			}
			else if (strcmp(pass, u->password) - strcmp(pass, u->phone) == 0)//密码匹配
			{
				puthz(290, 355, "登录成功", 16, 17, RED);
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				delay(1000);
				if (fclose(fp) != 0)
				{
					printf("\n cannot close Database");
					delay(3000);
					exit(1);
				}
				return 1;
				//切换界面
			}
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
	if (i == len)
	{
		puthz(560, 150, "账户未注册", 16, 17, RED);//走到最后一位
	}

	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database");
		delay(3000);
		exit(1);
	}
	return 0;
}

///*********************************************
//FUNCTION:input_database
//DESCRIPTION：把用户注册或者开户信息写入文件
//INPUT:name,id,code,bank,bankcode
//RETURN:1/0
//***********************************************/
void input_database(char* name, char* id, char* code, char* bank)
{
	FILE* fp;
	USER* u;
	char n;
	if ((fp = fopen("database\\UserData.dat", "rb+")) == NULL)//建立数据库
	{
		printf("cannot open file UserData.dat");
		delay(3000);
		exit(1);
	}
	if ((u = (USER*)malloc(sizeof(USER))) == NULL)
	{
		printf("memoryallocation runs wrong in lgfunc.c");
		delay(3000);
		exit(1);
	}
	memset(u, '\0', sizeof(USER));
	strcpy(u->ID, name);
	strcpy(u->phone, id);
	strcpy(u->password, code);
	strcpy(u->user, bank);
	fseek(fp, 0, SEEK_END);//跳转至文件末尾
	fwrite(u, sizeof(USER), 1, fp);//把用户信息写入文件 余额默认为0
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
}

///*********************************************
//FUNCTION:judge_sameuser
//DESCRIPTION：判断账户是否出现重名,
//	flag为1判断是否注册，
//	flag为2判断找回密码中是否存在
//INPUT:new_user,flag
//RETURN:1/0
//***********************************************/
int judge_sameuser(char* new_user, int flag)
{
	int len;
	int i;
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen("database\\UserData.dat", "rb+")) == NULL)//建立数据库
	{
		printf("cannot open file UserData.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(u->user, new_user) == 0)
		{
			switch (flag)
			{
			case 1:
				puthz(45, 190, "用户已被注册", 16, 17, RED);
				break;
			case 2:
				puthz(450, 110, "账号存在", 16, 17, RED);
				break;
			default:
				printf("something wrong");
				delay(3000);
				exit(1);
			}
			if (u != NULL)
			{
				free(u);
				u = NULL;
			}
			if (fclose(fp) != 0)
			{
				printf("\n cannot close Database.");
				delay(3000);
				exit(1);
			}
			return 0;
		}
		free(u);
		u = NULL;
	}
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
	return 1;
}

///*********************************************
//FUNCTION:checkright_user
//DESCRIPTION：检查用户名是否大于6位
//INPUT:str,x,y
//RETURN:1/0
//***********************************************/
int checkright_user(char* str, int x, int y)
{
	if (strlen(str) <6  )
	{
		puthz(x, y, "名称应", 16, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x + 53, y - 5, ">6");
		return 1;
	}
	else if (strlen(str) >= 6 && strlen(str) <= 12)
	{
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3);
		//line(550, 98, 560, 108); 
		//line(560, 108, 570, 88); 
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}

///*********************************************
//FUNCTION:checkright_password
//DESCRIPTION：检查密码是否大于8位
//INPUT:str,x,y
//RETURN:1/0
//***********************************************/
int checkright_password(char* str, int x, int y)
{
	if (strlen(str) < 8)//小于8位
	{
		puthz(x, y, "密码应", 16, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x + 53, y - 5, ">8");
		return 1;
	}
	else if (strlen(str) >= 8 && strlen(str) <= 16)
	{
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3);
		//line(550, 158, 560, 168);
		//line(560, 168, 570, 148);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}

///*********************************************
//FUNCTION:checkright_password
//DESCRIPTION：检查确认密码是否一致
//INPUT:str1,str2,x,y
//RETURN:1/0
//***********************************************/
int checkright_confirmedpassword(char* str1, char* str2, int x, int y)
{
	if (strcmp(str1, str2) != 0)
	{
		puthz(x, y, "两次不一致", 16, 17, RED);
		return 1;
	}
	else if (strcmp(str1, str2) == 0)
	{
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}

///*********************************************
//FUNCTION:checkright_ID
//DESCRIPTION：检查身份证位数与格式
//INPUT:str,x,y,flag
//RETURN:1/0
//***********************************************/
int checkright_ID(char* str, int x, int y, int flag)
{
	int i;
	int state = 1;
	if (strlen(str) != 11)
	{
		puthz(x, y, "应为", 16, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x + 35, y - 5, "11");
		puthz(x + 65, y, "位", 16, 17, RED);//长度不符合
		return 1;
	}
	else if (strlen(str) == 11)
	{
		for (i = 0; i < 9; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				continue;
			}
			else
			{
				puthz(x, y, "格式不正确", 16, 17, RED);
				return 0;
			}

		}
		state = 0;
		/*if (str[17] == 'X' || (str[17] >= '0' && str[17] <= '9'))
		{
			state = 0;//判断最后一位是否为数字和X
		}
		else
		{
			puthz(x, y, "格式不正确", 16, 17, RED);
			return 1;
		}*/
	}
	if (state == 0)
	{
		switch (flag)
		{
		case 1:
			setcolor(BLUE);
			setlinestyle(SOLID_LINE, 0, 3);
			line(x + 3, y + 8, x + 13, y + 18);
			line(x + 13, y + 18, x + 23, y - 2);
			break;
		case 2:
			break;
		}
		return 0;
	}
	return 1;
}
///*********************************************
//FUNCTION:judge
//DESCRIPTION：判断注册的状态
//INPUT : str, p, x, y
//RETURN : 无
//* **********************************************/
void judge(char* str, int* p, int x, int y)
{
	if (strlen(str) == 0)
	{
		*p = 1;
		puthz(x, y, "未输入", 16, 17, RED);
	}
	else
	{
		*p = 0;
	}
}

///************************************
//* 覆盖之前汉字
//*************************************/
void recoverhz(int x, int y, int color)
{
	setfillstyle(SOLID_FILL, color);
	bar(x, y, x + 95, y + 35);
}
	
