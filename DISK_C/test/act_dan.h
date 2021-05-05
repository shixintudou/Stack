#ifndef _ACT_DAN_H_
#define _ACT_DAN_H_



void act_dan_base(int *page,USER* u,char *vn);
void draw_dan(FILE*fp1,int len);
void base_dan_draw_action(USER* u);
void base_dan_action_lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag,USER*u,FILE*fp1);//点亮
void base_dan_action_recoverbutton_login_information(int status,FILE*fp1,int ab);//恢复




#endif
