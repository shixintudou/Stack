#ifndef _PINGLUN_H_
#define _PINGLUN_H_

#include"public.h"
#include"plv.h"
#include"input.h"
#include"vifunc.h"


void pinglun_main(USER* u, int* number, char* vn,int* state);
void draw_pinglun();
void lightbutton_pinglun(int x, int y, int x1, int y1, int color1, int color2, int flag);
void recoverbutton_pinglun(int status);
void getpinglun(USER* u,char* vn);
void showpinglun_start(char* vn, int head, int tail);
void input_data(char* fname, char* user, char* pinglun, char* hs, char* mins);
void drawinput_pinglun();
//void showpinglun_afterinput(char* vn, int head, int tail);
int getlen(char* vn);

#endif
