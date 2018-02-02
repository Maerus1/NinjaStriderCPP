#pragma once
#include "Sprite.h"
#include <string>
#include <SDL.h>
class Enemy :
	public Sprite
{
public:
	Enemy(SDL_Window* window, SDL_Renderer* render, const std::string &file, int x, int y);
	virtual SDL_Surface* getImage() const;
	~Enemy();
};

