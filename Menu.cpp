#include "Menu.h"


Menu::Menu() //create menu here
{
	game = new Game(); //call out a new game
	renderer = game->gRenderer(); //display game on the screen, first menu
	cnt = 0; //counter variable
	menuContent = 0;

	//the velocity of the start button
	startRect.x = 470;
	startRect.y = 252;
	startRect.w = 318;
	startRect.h = 82;

	//the velocity of the esc button
	escRect.x = 9;
	escRect.y = 9;
	escRect.w = 76;
	escRect.h = 48;

	//the velocity of the setting button
	settingRect.x = 471;
	settingRect.y = 386;
	settingRect.w = 322;
	settingRect.h = 75;

	//the velocity of the howtoplay button
	howtoplayRect.x = 100;
	howtoplayRect.y = 100;
	howtoplayRect.w = 100;
	howtoplayRect.h = 100;

	
	SDL_Surface* surface;

	//load menu image
	surface = IMG_Load("res/img/menu.png");
	menu = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	//load menu setting
	surface = IMG_Load("res/img/howtoplay.png");
	setting = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	//load how to play button
	surface = IMG_Load("res/img/paused.png");
	howtoplay = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	//load paused button
	surface = IMG_Load("");
	paused = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

Menu::~Menu() //decontruct menu here
{
	
}

bool Menu::check(SDL_Rect mouseCheck) // menu mouseCheck 
{
	//do the mouse event here
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (mouseCheck.x <= x and x <= mouseCheck.x + mouseCheck.w and mouseCheck.y <= y and y <= mouseCheck.y + mouseCheck.h)
		return true;
	return false;
}

bool Menu::event() //handle menu event here
{
	bool running = true;
	SDL_Event event;
	switch (menuContent)
	{
	case 0: //menu
	{
		if (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_MOUSEBUTTONUP:
				if (check(startRect))
				{
					menuContent = 1; //going to game if press to the start button
				}
				if (check(howtoplayRect))
				{
					menuContent = 3; //going to the how to play
				}
				if (check(settingRect))
				{
					menuContent = 2; //going to the setting
				}
				break;
			default:
				break;
			}
		}
		break;
	}
	case 1: //in game
		//write the game logic here later
		break;
	case 2: //setting
		//write the game setting here later
		break;
	case 3: //how to play 
		if (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym = SDLK_ESCAPE)
				{
					menuContent = 0; // back to the game menu
				}
				break;
			case SDL_MOUSEBUTTONUP:
				if (check(escRect))
				{
					menuContent = 0; //back to the menu
				}
				break;
			default:
				break;
			}
		}
		break;
	default:
		running = false;
		break;
	}
	return running;
}

void Menu::draw() //draw menu here
{
	switch (menuContent)
	{
	case 0: //back to menu
		SDL_RenderCopy(renderer, menu, NULL, NULL);
		break;
	case 1: //go in the game
		game->gameRender();
		if (game->isPause())
		{
			SDL_RenderCopy(renderer, paused, NULL, NULL);
		}
		break;
	case 2: //setting menu
		SDL_RenderCopy(renderer, setting, NULL, NULL);
		break;
	case 3:
		SDL_RenderCopy(renderer, howtoplay, NULL, NULL);
		break;
	default:
		break;
	}
	SDL_RenderPresent(renderer);
}

