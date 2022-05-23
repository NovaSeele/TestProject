#pragma once
#ifndef MENU__H
#define MENU__H

#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"


class Menu
{
public:
	Menu();
	~Menu();

	bool check(SDL_Rect mouseCheck);
	bool event();
	void draw();

private:
	Game* game;
	SDL_Rect startRect, escRect, settingRect, howtoplayRect;
	SDL_Texture* menu;
	SDL_Texture* setting;
	SDL_Texture* paused;
	SDL_Texture* howtoplay;
	SDL_Renderer* renderer;
	int menuContent;
	// menuContent = 1; go in the game
	// menuContent = 0; go in the menu
	// menuContent = 2; go in the setting
	// menuContent = 3; go in the how to play

	int cnt;
};

#endif