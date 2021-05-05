#ifndef _COLLECT_H_
#define _COLLECT_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<math.h>
#include<bios.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include"HZ.H"
#include"MOUSE.H"
#include"DATABASE.H"

void show_collect(int* page, USER* u,char*vn);
void base_draw_collect(FILE* fp1, int len);
void base_draw_my_collect(USER* u);
void base_collect_lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag,int k,FILE*fp1,int len);//∞¥≈•µ„¡¡
void base_collect_recoverbutton_login_information(int status, FILE* fp1,int i,int len);
#endif
