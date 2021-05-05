#ifndef _NTLOOK_H_
#define _NTLOOK_H_

void show_ntlook(int* page, USER* u,char*vn);
void base_draw_ntlook(FILE* fp1, int len);
void base_draw_my_ntlook(USER* u);
void base_ntlook_lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag,int k,FILE*fp1,int len);//∞¥≈•µ„¡¡
void base_ntlook_recoverbutton_login_information(int status, FILE* fp1,int i,int len);//ª÷∏¥

void input_nt(int *page,USER*u,char*vn);
void nt_del(char*STK_ADR6 ,USER*u,int len,int del_num);


#endif