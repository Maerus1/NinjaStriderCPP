#pragma once
#include <string>
#include <iostream>
#include <SDL.h>
class Sprite
{
public:
	Sprite();
	Sprite(SDL_Window* window, SDL_Renderer* render, const std::string &file, int x, int y);
	virtual SDL_Surface* getImage() const = 0;
	SDL_Texture* getTexture() const;
	void loadTexture(const std::string &file, SDL_Renderer *render);
	void resizeTexture(SDL_Renderer* render, int x, int y, int w, int h);
	SDL_Rect getRect();
	virtual ~Sprite();
private:
	SDL_Texture* tex;
	SDL_Rect rect;
protected:
	SDL_Surface* image;
};

