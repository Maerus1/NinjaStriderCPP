#pragma once
#include <string>
#include <iostream>
#include <SDL.h>
class Sprite
{
public:
	Sprite();
	Sprite(SDL_Window* window, SDL_Renderer* render, const std::string &file, int x, int y);
	SDL_Surface* getImage() const;
	virtual void cropSprite(int srcWidth, int srcHeight, int dstWidth, int dstHeight, int dstX, int dstY, int srcX, int srcY) = 0;
	SDL_Texture* getTexture() const;
	void loadTexture(const std::string &file, SDL_Renderer *render);
	void resizeTexture(int x, int y, int w, int h);

	//gets the destination rectangle
	SDL_Rect getDstRect();

	//gets the source rectangle
	SDL_Rect getSrcRect();
	virtual ~Sprite();
private:
	SDL_Texture* tex;
protected:
	SDL_Surface* image;
	SDL_Rect rect;
	SDL_Rect srcRect;
};

