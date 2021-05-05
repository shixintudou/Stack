#include"public.h"
#include"welcome.h"


/*****************************************
welcome.c
COPYRIGHT: 	dengshumin
FUNCTION:   draw welcome interface
DATE:       2019/8/31
******************************************/

void welcome_page(void)	//欢迎界面
{
	char bacground[48][55] = {
	"                                                     ",
	"                                                     ",
	"              你 感 兴 趣 的 视 频                   ",
	"                                                     ",
	"                    都 在 B 站                       ",
	"                  r.                                 ",
	"                 vPvi                                ",
	"                   Qq                                ",
	"               .iirj77JYLr:                          ",
	"             iY1Lvrirrr77Ls1i        ::::.           ",
	"            5J7r7rrirrri7iir1v    ..iui.     7M:     ",
	"           Z7rrrrir7i:rivZuiiJv.....   ..::  BBBB:   ",
	"          2PrirrrrLb7iri:vMb7i1:    .   . .:v7 vu.   ",
	"          QjisrrrduidS72uvririrv  ..   . ...2r  . :  ",
	"          QUrLri7Br  :vEi:BBbisDL ..  :    ...U:  .: ",
	"          sQu7irr2 .v.    BZrr1..   .L2.:    rB    : ",
	"          .MP:irriuQi.      :bPu::::i  :v     i   .: ",
	"           BY7v:i25:   :r:  21.B5   UBBUr .. :v  .:  ",
	"          vQEMQPjKD5i  :r.iBPr      iBR7  .  :u. .:  ",
	"         :EBBgbMZ. :vJrMB7  rj:       ...  ri.7rrr.  ",
	"       is i.    jr  . ..i   r:7Xv..  .r:..sJ5Ksv17:  ",
	"     vSu.    ir1Bb77v::ru. .    :iUBBB  UZi..: i..   ",
	".     Yv:. 7BQBBBXq2IUqSKdi:ir   :7PB7  qE.   :. ::  ",
	":gBBBBQgE22QQQBBii. .Rir: :s.   Prsd.. r.     .:::.  ",
	"  uBBBBQQgQQBDP:     i.r.:  ....i  :   i.       .    ",
	"    .r7YKQBRs:i.    :  BBBB2. .... u   i.            ",
	"       sBBd:ii .ii:rL. 2uUui      .r.  :S.           ",
	"       :..  .  .i:r7:r:           :v7i :ZS.          ",
	"             r... .:ii:           r:.:..  :          ",
	"           .BBB.   :. .          .        ..         ",
	"           dBjBB5bBBgKq           Ji .r   .          ",
	"               qQBBBQBB          .BB:RIidB:          ",
	"                :BBBBQB          :BQBBBBBB           ",
	"                   rBBB           1bJ BBBi           ",
	"                    BBB               BBB            ",
	"                   :BMQ               QBQ            ",
	"                    BRB7             jBBJ            ",
	"                     QMB.            BBB             ",
	"                      QRBQg2      qQBBBr             ",
	"                      .s7:.        .:7i              ",
	"                ____  _ _ _ _     _ _ _ 	   	      ",
	"               |  _ \\(_) (_) |   (_) (_)		       ",
	"               | |_) |_| |_| |__  _| |_ 		      ",
	"               |  _ <| | | | '_ \\| | | |		       ",
	"               | |_) | | | | |_) | | | |		      ",
	"               |____/|_|_|_|_.__/|_|_|_|		      ",
	"                                                     ",
	};
	int i;
	setcolor(LIGHTMAGENTA);//blibli图案
	settextstyle(0, 0, 1);
	for (i = 0; i < 48; i++)
	{
		outtextxy(95, i * 10, bacground[i]);
	}
	delay(2500);
}