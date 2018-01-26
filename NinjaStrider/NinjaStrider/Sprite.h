#pragma once
#include <string>
#include <iostream>
#include <SDL.h>
class Sprite
{
public:
	Sprite();
	Sprite(const char* url, SDL_Window* window, SDL_Renderer* render,int x, int y);
	virtual SDL_Surface* getImage() const = 0;
	SDL_Texture* getTexture() const;
	SDL_Rect getRect();
	virtual ~Sprite();
private:
	SDL_Texture* tex;
	SDL_Rect rect;
protected:
	SDL_Surface* image;
};

