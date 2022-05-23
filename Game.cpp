#include "Game.h"



Game::Game() //create window
{
	window = SDL_CreateWindow("Mania", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(renderer, screen_width, screen_height);

	font = TTF_OpenFont("fonts/RobotoCondensed-Bold.ttf", 28);

	SDL_Surface* icon = IMG_Load("res/img/icon.png"); //window icon
	SDL_SetWindowIcon(window, icon);

	SDL_Texture* Background = nullptr;
	SDL_Surface* surface = IMG_Load("res/img/bg.png"); //load background
	Background = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	this->background = Background;

	failed = false;
	paused = false;

	//khai bao key o day

}

bool Game::youLose() //check whenever y lose
{
	return failed;
}

Game::~Game() //decontruct window
{

}

void Game::keyPressed()
{
	SDL_Event e;
	if (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			failed = true;
			break;
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym)
			{
				case SDLK_a:
					//key 1 here
					break;
				case SDLK_s:
					//key 2 here
					break;
				case SDLK_j:
					//key 3 here
					break;
				case SDLK_k:
					//key 4 here
					break;
				default:
					break;
			}
		default:
			break;
		}
	}
}

void Game::gameUpdate() //handle game logic here
{

}

void Game::gameRender() //display game here
{
	SDL_RenderCopy(renderer, background, NULL, NULL);
}

void Game::gameClean() //for no memory leaking
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

SDL_Renderer* Game::gRenderer()
{
	return renderer;
}

bool Game::isPause()
{
	return paused;
}

void Game::drawScore()
{

}

void Game::drawCombo()
{

}

void Game::drawAccuracy()
{

}

