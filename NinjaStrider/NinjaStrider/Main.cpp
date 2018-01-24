#include <iostream>
#include <SDL.h>

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "SDL integration failed. Error: " << SDL_GetError();
	}
	else {
		std::cout << "SDL Successfully integrated!";
	}
	std::cin.get();
	return 0;
}