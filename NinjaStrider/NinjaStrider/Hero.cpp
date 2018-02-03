#include "Hero.h"



Hero::Hero(SDL_Window* window, SDL_Renderer* render, const std::string &file, int x, int y) : Sprite(window, render, file, x, y)
{
}

void Hero::cropSprite(int srcWidth, int srcHeight, int dstWidth, int dstHeight, int srcX, int srcY)
{
	rect.w = dstWidth;
	rect.h = dstHeight;

	srcRect.w = srcWidth;
	srcRect.h = srcHeight;
	srcRect.x = srcX;
	srcRect.y = srcY;

	//get the frame dimensions for changing the frame
	//in the changeFrame() function
	this->heroWidth = srcWidth;
	this->heroHeight = srcHeight;
}

void Hero::changeFrame(unsigned int interval)
{
	currentTime = SDL_GetTicks();
	if (currentTime > previousTime + interval)
	{
		//update hero sprite frame
		this->cropSprite(heroWidth, heroHeight, heroWidth, heroHeight,
			++frameSwitcher * heroWidth, 0);
		previousTime = currentTime;
		if (frameSwitcher >= 9)
		{
			frameSwitcher = 0;
		}
	}
}
Hero::~Hero()
{
}
