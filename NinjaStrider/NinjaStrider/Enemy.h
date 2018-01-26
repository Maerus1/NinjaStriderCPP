#pragma once
#include "Sprite.h"
#include <string>
#include <SDL.h>
class Enemy :
	public Sprite
{
public:
	Enemy(const char* url, SDL_Window* window, SDL_Renderer* render, int x, int y);
	virtual SDL_Surface* getImage() const;
	~Enemy();
};

