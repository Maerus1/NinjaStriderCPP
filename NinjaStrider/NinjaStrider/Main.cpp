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

	//some constants for the hero
	//sprite and animating it
	const int HERO_WIDTH = 64;
	const int HERO_HEIGHT = 79;
	const unsigned int FRAME_INTERVAL = 60;
	int heroSpeed = 5;

	//this prevents a delay in movement after the key is first pressed and held
	bool moveLeft = false;
	bool moveRight = false;

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

	//set initial hero sprite frame
	hero->cropSprite(HERO_WIDTH, HERO_HEIGHT, HERO_WIDTH, HERO_HEIGHT, 0, 0);
	while (!quit) {
		//use the event variable and actively listen for window
		//and input events
		while (!quit && SDL_PollEvent(&event)) 
		{
			switch (event.type) 
			{
			case SDL_QUIT:
				//when the game is exited
				quit = true;
				break;
			case SDL_KEYDOWN:
				//if the user presses the escape key
				if (event.key.keysym.sym == SDLK_ESCAPE) 
				{
					quit = true;
				}
				if (event.key.keysym.sym == SDLK_a &&
					event.key.keysym.sym != SDLK_d)
				{
					//if I put the translation of the sprite
					//directly in here, there would be a little
					//delay after the first keypress and hold
					moveLeft = true;
					moveRight = false;
				}
				else if (event.key.keysym.sym == SDLK_d &&
						 event.key.keysym.sym != SDLK_a)
				{
					moveRight = true;
					moveLeft = false;
				}
				break;
			case SDL_KEYUP:
				if (event.key.keysym.sym == SDLK_a || 
					event.key.keysym.sym == SDLK_d)
				{
					//in order to stop movement
					moveLeft = false;
					moveRight = false;
				}
				break;
			}
		}
		if (moveLeft) 
		{
			hero->translateSprite(-heroSpeed, 0);
		}
		else if (moveRight) 
		{
			hero->translateSprite(heroSpeed, 0);
		}

		

		//render the image
		//clear the renderer first
		SDL_RenderClear(render);
		
		//draw the texture
		SDL_RenderCopy(render, hero->getTexture(), &hero->getSrcRect(), &hero->getDstRect());
		//update screen
		SDL_RenderPresent(render);
		
		//updates the frame of the sprite at a regular interval
		hero->changeFrame(FRAME_INTERVAL);
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