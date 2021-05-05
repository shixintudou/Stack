#ifndef _SHOWVIDEO_H_
#define _SHOWVIDEO_H_

#include<stdio.h>
#include<graphics.h>
#include"mouse.h"
#include"playvideo.h"
#include"hz.h"
#include"database.h"

void show(int* page, char* vn, USER* u, BH* h);
void drawshow();
void lightbutton_show( int color1, int color2, int flag);
void recoverbutton_show(int status);

#endif _SHOWVIDEO_H_

