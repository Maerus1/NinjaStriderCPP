#include <iostream>
#include <SDL.h>
#include "Enemy.h"
#include "Hero.h"
#include "SDL_image.h"

//you need to add parameters to the main function here or else you'll get linker errors
int main(int argc, char* argv[]) {

	//create window pointer
	SDL_Window* window;

	//Screen and tile constants
	const int SCREEN_WIDTH = 980;
	const int SCREEN_HEIGHT = 720;
	const int TILE_SIZE = 40;

	//flag to keep the game loop going
	bool quit = false;
	//event listener for window events
	SDL_Event event; 

	//initialize SDL Video capabilities
	SDL_Init(SDL_INIT_VIDEO);

	//initialize PNG loader to speed up load time
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) 
	{
		SDL_LogError(SDL_LOG_CATEGORY_RENDER, "%s");
		std::cout << "PNG loading failed, Error: " << SDL_GetError();
		window = nullptr;
		IMG_Quit();
		SDL_Quit();
		return 1;
	}

	//create and point to the window object
	window = SDL_CreateWindow(
		"Ninja Strider",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		980,
		720,
		SDL_WINDOW_OPENGL
	);

	if (window == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "%s");
		std::cout << "Window creation failed, Error: " << SDL_GetError();
		SDL_DestroyWindow(window);
		window = nullptr;
		IMG_Quit();
		SDL_Quit();
		return 1;
	}

	//create the renderer
	SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	//if the render pointer is null, quit the program
	if (render == nullptr) {
		std::cout << "Could not create the renderer. Error: " << SDL_GetError();
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(render);
		render = nullptr;
		window = nullptr;
		IMG_Quit();
		SDL_Quit();
		return 1;
	}
	
	//create an Enemy object
	Enemy* enemy = new Enemy(window, render,"Assets/Images/enemy.png", 50, 50);
	Hero* hero = new Hero(window, render, "Assets/Images/hero.png", 72, 90);

	while (!quit) {
		//use the event variable and actively listen for window
		//and input events
		while (!quit && SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				//when the game is exited
				quit = true;
				break;
			case SDL_KEYDOWN:
				//if the user presses the escape key
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					quit = true;
				}
				break;
			}
		}
		//render the image
		//clear the renderer first
		SDL_RenderClear(render);
		//draw the texture
		SDL_RenderCopy(render, enemy->getTexture(), NULL, &enemy->getRect());
		SDL_RenderCopy(render, hero->getTexture(), NULL, &hero->getRect());
		//update screen
		SDL_RenderPresent(render);
		
	}
	
	//free all my memory
	delete enemy;
	delete hero;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(render);
	enemy = nullptr;
	hero = nullptr;
	window = nullptr;
	render = nullptr;
	//clean up and destroy the game instance
	IMG_Quit();
	SDL_Quit();
	return 0;
}