#ifndef _SUB_COLL_H_
#define _SUB_COLL_H_


void show_sub_collect(int* page, USER* u,char*vn);
void base_sub_draw_collect(FILE* fp1, int len);
void base_sub_draw_my_collect(USER* u);
void base_sub_collect_lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag,int k,FILE*fp1,int len);//∞¥≈•µ„¡¡
void base_sub_collect_recoverbutton_login_information(int status, FILE* fp1,int i,int len);//ª÷∏¥
void sub_del(char*STK_ADR6,int len,USER*u,int del_num);


#endif