//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//SDL requires this type of main so it is compatible with multiple platforms
//It is important that we have arguments of the main function be an int and a char* (array)
//and the return type be an int
int main(int argc, char* args[])
{
	//Declaration of SDL_Window pointer named window
	//A window is a container for a 2D image
	SDL_Window* window = NULL;
	
	//Declaration of SDL_Surface pointer named screenSurface
	//A surface is a 2D image that is drawn on the window
	SDL_Surface* screenSurface = NULL;


	//Initialize SDL (Cant call any SDL functions without this)
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		//If the value returned is less than 0, then SDL failed to initialize
		//printf is print format to the console, it prints the string in the first argument
		//string returned by SDL_GetError() is the error message
		//%s is a format specifier that is replaced by the string in the second argument
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	//If SDL initialized successfully
	else
	{
		//Create window function creates a window with the title "SDL Tutorial"
		//SDL_WINDOWPOS_UNDEFINED and SDL_WINDOWPOS_UNDEFINED are the x and y positions of the window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);
			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			//Update the surface
			SDL_UpdateWindowSurface(window);
			//Hack to get window to stay up
			SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
		}
	}
	//Destroy window
	SDL_DestroyWindow(window);
	//Quit SDL subsystems
	SDL_Quit();
	return 0;
}