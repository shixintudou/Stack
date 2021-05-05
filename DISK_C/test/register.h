#ifndef _REGISTER_H_
#define _REGISTER_H_

#include<stdio.h>
#include<graphics.h>
#include"mouse.h"
#include"hz.h"

void drawregister();
void register_main(int* page);
void lightbutton_signin(int x, int y, int x1, int y1, int color1, int color2, int flag);
void recoverbutton_signin(int status);
#endif