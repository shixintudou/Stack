#ifndef _DATA_H_
#define _DATA_H_
typedef struct userinfo
{
	char user[15];           //6-12位，用户名
	char ID[20];             //18位，账号
	char password[20];       //8-16位，密码
	char phone[21];       //19位，手机号
}USER;	//封装用户信息
typedef struct videoinfo
{
	char vn[2];//视频名称
	char comment[200];//评论
	int bingo;//点赞数
	char dan[15][30];//弹幕,分别记录时间及内容 
}VIDEO;

typedef struct history
{
	char name[10];  //番剧名称
	char now_hour[10];
	char now_min[10];
}HIS;

typedef struct collect
{
	char name[10];
	char num_page[10];
}COLL;

typedef struct pinglun
{
	char name[20];
	char plun[100];	
	char now_hour[10];
	char now_min[10];
}PING;



#endif