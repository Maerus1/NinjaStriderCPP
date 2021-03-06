#include "Sprite.h"
#include "SDL_image.h"


Sprite::Sprite() 
{
}
Sprite::Sprite(SDL_Window* window, SDL_Renderer* render, const std::string &file, int x, int y)
{
	//create the image
	
	tex = IMG_LoadTexture(render, file.c_str());

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
SDL_Surface* Sprite::getImage() const
{
	return image;
}

void Sprite::loadTexture(const std::string &file, SDL_Renderer *render) 
{
	tex = IMG_LoadTexture(render, file.c_str());
	if (tex == nullptr) {
		SDL_LogError(SDL_LOG_CATEGORY_RENDER, "%s");
	}
}


void Sprite::resizeTexture(int x, int y, int w, int h) 
{
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
}

void Sprite::translateSprite(int x, int y) 
{
	rect.x += x;
	rect.y += y;
}

SDL_Rect Sprite::getDstRect() 
{
	return rect;
}

SDL_Rect Sprite::getSrcRect()
{
	return srcRect;
}
SDL_Texture* Sprite::getTexture() const
{
	return tex;
}

Sprite::~Sprite()
{
}
