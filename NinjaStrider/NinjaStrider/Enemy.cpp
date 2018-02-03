#include "Enemy.h"



Enemy::Enemy(SDL_Window* window, SDL_Renderer* render, const std::string &file, int x, int y) : Sprite( window, render, file, x, y)
{
}

void Enemy::cropSprite(int srcWidth, int srcHeight, int dstWidth, int dstHeight, int srcX, int srcY)
{
	rect.w = dstWidth;
	rect.h = dstHeight;

	srcRect.w = srcWidth;
	srcRect.h = srcHeight;
	srcRect.x = srcX;
	srcRect.y = srcY;
}

Enemy::~Enemy()
{
}
