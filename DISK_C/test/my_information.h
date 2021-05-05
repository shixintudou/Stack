#ifndef _MY_INFORMATION_
#define _MY_INFORMATION_
#include<stdio.h>
#include<graphics.h>
#include"mouse.h"
#include"hz.h"
#include"database.h"
 

void draw_my_information(USER*u,char *ID);//绘制我的信息界面
void my_information(int* page, char* ID);
void lightbutton_login(int x, int y, int x1, int y1, int color1, int color2, int flag);//登录界面按钮点亮
void recoverbutton_login(int status);//恢复

#endif