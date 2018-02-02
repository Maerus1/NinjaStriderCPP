#include "Enemy.h"



Enemy::Enemy(SDL_Window* window, SDL_Renderer* render, const std::string &file, int x, int y) : Sprite( window, render, file, x, y)
{
	
}

SDL_Surface* Enemy::getImage() const {
	return image;
}
Enemy::~Enemy()
{
}
