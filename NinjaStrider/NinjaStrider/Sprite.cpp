#include "Sprite.h"



Sprite::Sprite() 
{
}
Sprite::Sprite(const char* url, SDL_Window* window, SDL_Renderer* render, int x, int y)
{
	//create the image
	//GET ADDITIONAL LIBRARIES SO I CAN USE DIFFERENT IMAGE TYPES
	image = SDL_LoadBMP(url);
	if (image == nullptr) {
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(window);
		std::cout << "Could not load image. Error: " << SDL_GetError();
		SDL_Quit();
		//return 1;
	}

	//Create the texture
	tex = SDL_CreateTextureFromSurface(render, image);
	if (tex == nullptr) {
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(window);
		std::cout << "Could not create texture. Error: " << SDL_GetError();
		SDL_Quit();
		//return 1;
	}
	rect.x = x;
	rect.y = y;
	//get the width and height of the texture
	SDL_QueryTexture(tex, NULL, NULL, &rect.w, &rect.h);

}

SDL_Rect Sprite::getRect() 
{
	return rect;
}

SDL_Texture* Sprite::getTexture() const
{
	return tex;
}

Sprite::~Sprite()
{
}
