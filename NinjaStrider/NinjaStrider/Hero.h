#pragma once
#include "Sprite.h"
class Hero :
	public Sprite
{
public:
	Hero(SDL_Window* window, SDL_Renderer* render, const std::string &file, int x, int y);
	virtual void cropSprite(int srcWidth, int srcHeight, int dstWidth, int dstHeight, int dstX, int dstY, int srcX, int srcY);
	void changeFrame(unsigned int interval);
	~Hero();
private:
	//for animation
	int heroWidth;
	int heroHeight;
	int frameSwitcher = 0;
	unsigned int previousTime = 0;
	unsigned int currentTime = 0;
};

