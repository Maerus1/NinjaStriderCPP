#pragma once
#include "Sprite.h"
#include <string>
#include <SDL.h>
class Enemy :
	public Sprite
{
public:
	Enemy(SDL_Window* window, SDL_Renderer* render, const std::string &file, int x, int y);
	virtual void cropSprite(int srcWidth, int srcHeight, int dstWidth, int dstHeight, int dstX, int dstY, int srcX, int srcY);
	~Enemy();
};

