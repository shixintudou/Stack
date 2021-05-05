#ifndef _INFORMATION_H_
#define _INFORMATION_H_

#include"public.h"
void draw_my_information(USER* u);//绘制我的信息界面
void my_information(int* page,USER* u);
void lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag);//登录界面按钮点亮
void recoverbutton_login_information(int status);//恢复
int control_judge(USER* u);
void cpop(int i);
#endif
