#ifndef _PLAYVIDEO_H_
#define _PLAYVIDEO_H_

#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>


int putbmp(int x, int y, char* s);
void load_pic( char* name);
int bmp_convert(char* bmp, char* dbm);
int show_dbm(int x, int y, char* dbm);
#endif
