#ifndef _VIFUNC_H_
#define _VIFUNC_H_

#include"public.h"
#include"showv.h"
#include"input.h"

void log_judge(USER* u,char* number,char* vn);
void pleaselog();
void drawinput();
void sort(char* danmu);
int showdanmu(int side, int y, int color, char* s,int* p);

#endif 

