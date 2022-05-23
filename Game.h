#pragma once
#ifndef GAME__H
#define GAME__H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Key.h"
#include "Key_SV.h"
#include "Stat.h"
#include <string>


using namespace std;

class Game
{
public:
	Game();
	~Game();

	void gameUpdate();
	void gameRender();
	void gameClean();
	//game function

	void keyPressed(); //handle Menu option

	SDL_Renderer* gRenderer();
	bool isPause();
	bool youLose();

	void drawScore();
	void drawCombo();
	void drawAccuracy();
	//display function


private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* background;

	bool failed, paused;
	Key* key1;
	Key* key2;
	Key* key3;
	Key* key4;

	Key_SV* key1_sv;
	Key_SV* key2_sv;
	Key_SV* key3_sv;
	Key_SV* key4_sv;


	TTF_Font* font;
	SDL_Texture* content[10];
};

#endif