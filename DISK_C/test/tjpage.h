#ifndef _OTPAGE_H_
#define _OTPAGE_H_

#include"public.h"
#include"plv.h"

void tj_page(int* page, char* vn);
void drawtjpage();
void lightbutton_tjpage(int x, int y, int x1, int y1, int color1, int color2, int flag);
void recoverbutton_tjpage(int status);

#endif 

