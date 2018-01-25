#include <iostream>
#include <SDL.h>

//you need to add parameters to the main function here or else you'll get linker errors
int main(int argc, char* argv[]) {

	//create window pointer
	SDL_Window* window;
	//flag to keep the game loop going
	bool quit = false;
	//event listener for window events
	SDL_Event event; 

	//initialize SDL Video capabilities
	SDL_Init(SDL_INIT_VIDEO);

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
		std::cout << "Window creation failed, Error: " << SDL_GetError();
		return 1;
	}

	//create the renderer
	SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	//if the render pointer is null, quit the program
	if (render == nullptr) {
		SDL_DestroyWindow(window);
		std::cout << "Could not create the renderer. Error: " << SDL_GetError();
		SDL_Quit();
		return 1;
	}
	
	//create the image
	SDL_Surface* image = SDL_LoadBMP("Assets/Images/enemy.bmp");
	if (image == nullptr) {
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(window);
		std::cout << "Could not load image. Error: " << SDL_GetError();
		SDL_Quit();
		//return 1;
	}

	//Create the texture
	SDL_Texture* tex = SDL_CreateTextureFromSurface(render, image);
	if (tex == nullptr) {
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(window);
		std::cout << "Could not create texture. Error: " << SDL_GetError();
		SDL_Quit();
		//return 1;
	}

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
		SDL_RenderCopy(render, tex, NULL, NULL);
		//update screen
		SDL_RenderPresent(render);
		
	}

	//delete the window instance
	SDL_DestroyWindow(window);

	//clean up and destroy the game instance
	SDL_Quit();
	return 0;
}