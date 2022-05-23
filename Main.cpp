#include<SDL.h>
#undef main
#include"Menu.h"

int main(int argc, char* argv[])
{
	//Open Game, Open Menu
	Menu menu;

	int running = true; //check whenever run or not
	while (running)
	{
		menu.draw(); //draw menu
		if (menu.event()) running = false; //quit menu when acting, load to game or another
	}
	return 0;
}