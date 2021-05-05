#include"main.h"
#include"public.h"
int main()
{
	int page = 1;
	int gd = DETECT, gm;
	USER u;
	memset(&u, '\0', sizeof(USER));
	initgraph(&gd, &gm, "C:\\BORLANDC\\BGI");
	welcome_page();	//ª∂”≠ΩÁ√Ê
	mouseinit();
	while (1)
	{
		switch (page)
		{
		case 0:
			main_page(&page);
			break;
		case 1:
			login_main(&page, &u);
			break;
		case 2:
			register_main(&page);
			break;
		}
	}
	closegraph();
	return 0;
}