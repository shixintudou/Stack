#ifndef _MAINPAGE_H_
#define _MAINPAGE_H_

#include"mouse.h"
#include"hz.h"
#include"plv.h"
void main_page(int* page, char* vn);
void drawpage();
void lightbutton_mainpage(int x, int y, int x1, int y1, int color1, int color2, int flag);
void recoverbutton_mainpage(int status);
#endif


