#ifndef _RMPAGE_H_
#define _RMPAGE_H_

#include"public.h"
#include"plv.h"

void rm_page(int* page, char* vn);
void drawrmpage();
void lightbutton_rmpage(int x, int y, int x1, int y1, int color1, int color2, int flag);
void recoverbutton_rmpage(int status);


#endif