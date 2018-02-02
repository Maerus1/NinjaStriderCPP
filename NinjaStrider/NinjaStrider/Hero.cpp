#include "Hero.h"



Hero::Hero(SDL_Window* window, SDL_Renderer* render, const std::string &file, int x, int y) : Sprite(window, render, file, x, y)
{
}

SDL_Surface* Hero::getImage() const 
{
	return image;
}
Hero::~Hero()
{
}
