#ifndef _ACT_PING_H_
#define _ACT_PING_H_

void act_ping_base(int *page,USER* u);
void draw_ping(FILE*fp1,int len);
void base_ping_draw_action(USER* u);
void base_ping_action_lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag);//µ„¡¡
void base_ping_action_recoverbutton_login_information(int status);//ª÷∏¥

#endif