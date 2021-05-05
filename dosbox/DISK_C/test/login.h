#ifndef _LOGIN_H_
#define _LOGIN_H_

#include<stdio.h>
#include<graphics.h>
#include"mouse.h"
#include"hz.h"
#include"lgfunc.h"

void drawlog();
void lightbutton_login(int x, int y, int x1, int y1, int color1, int color2, int flag);
void login_main(int *page, USER *u);
void recoverbutton_login(int status);

#endif