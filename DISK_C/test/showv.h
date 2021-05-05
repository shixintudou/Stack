#ifndef _SHOW_H_
#define _SHOW_H_

#include<stdio.h>
#include<graphics.h>
#include"mouse.h"
#include"plv.h"
#include"hz.h"
#include"database.h"

void show_main(int* page,char* vn,USER* u);
void drawshow();
void lightbutton_show( int color1, int color2, int flag);
void recoverbutton_show(int status);
void addzan(char* vn);
void showzan(char* vn);

#endif

