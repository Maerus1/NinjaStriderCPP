#include <iostream>
#include <SDL.h>

int main(int argc, char* argv[]) {
	SDL_Window* window;
	//flag to keep the game loop going
	bool quit = false;
	//event listener for window events
	SDL_Event event; 

	SDL_Init(SDL_INIT_VIDEO);

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

	while (!quit) {
		//use the event variable and actively listen for window
		//and input events
		while (!quit && SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					quit = true;
				}
				break;
			}
		}
		
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}