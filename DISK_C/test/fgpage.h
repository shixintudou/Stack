#ifndef _FGPAGE_H_
#define _FGPAGE_H_

#include"public.h"
#include"plv.h"

void fg_page(int* page, char* vn);
void drawfgpage();
void lightbutton_fgpage(int x, int y, int x1, int y1, int color1, int color2, int flag);
void recoverbutton_fgpage(int status);

#endif 

