#pragma once
#include "Sprite.h"
class Hero :
	public Sprite
{
public:
	Hero(SDL_Window* window, SDL_Renderer* render, const std::string &file, int x, int y);
	virtual SDL_Surface* getImage() const;
	~Hero();
};

