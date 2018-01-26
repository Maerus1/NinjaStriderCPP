#include "Enemy.h"



Enemy::Enemy(const char* url, SDL_Window* window, SDL_Renderer* render, int x, int y) : Sprite(url, window, render, x, y)
{
	
}

SDL_Surface* Enemy::getImage() const {
	return image;
}
Enemy::~Enemy()
{
}
