#ifndef _HIS_SUB_H_
#define _HIS_SUB_H_



void show_sub_history(int* page, USER* u,char*vn);
void base_sub_draw_history(FILE* fp1, int len,int label,int label2);
void base_sub_draw_my_history(USER* u);
void base_sub_history_lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag, FILE* fp1,int len,int label,int label2,int q);
void base_sub_history_recoverbutton_login_information(int status, FILE* fp1,int i,int len,int label,int label2,int q);
void del(char*STK_ADR6,int len,USER*u,int del_num,int label2);

#endif