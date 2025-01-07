//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
//#include <SDL_image.h>


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Global variables

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if(SDL_Init( SDL_INIT_VIDEO ) < 0)
	//If SDL could not initialize
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		//Using global variable SDL_Window* gWindow
		//Create Window function creates a window with the title "SDL Tutorial"
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		//If the window was not created
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			//Call to SDL_GetWindowSurface with the window we created
			//We call SDL_GetWindowSurface to grab the surface contained by the window
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}

	return success;
}

bool LoadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	//Load BMP function loads an image from a file
	//The first argument is the path to the image
	//The second argument is the surface we want to load the image onto
	gHelloWorld = SDL_LoadBMP("hello_world.bmp");
	//If the image was not loaded
	if (gHelloWorld == NULL)
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError() );
		success = false;
	}

	return success;
}

void close()
{
	//Deallocate surface
	//Call to SDL_FreeSurface to deallocate the surface we loaded the image onto
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;
	//Destroy window
	//Call to SDL_DestroyWindow to destroy the window we created
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	//Quit SDL subsystems
	//Call to SDL_Quit to shut down SDL
	SDL_Quit();
}

//SDL requires this type of main so it is compatible with multiple platforms
//It is important that we have arguments of the main function be an int and a char* (array)
//and the return type be an int
int main(int argc, char* args[])
{
	//Start up SDL and create window
	if ( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if ( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			//Apply the image
			//Call to SDL_BlitSurface to apply the image to the window surface
			//The first argument is the source surface
			//The second argument is the rectangle we want to copy from the source surface
			//The third argument is the destination surface
			//The fourth argument is the rectangle we want to copy to on the destination surface
			SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
			//Update the surface
			//Call to SDL_UpdateWindowSurface to update the window with the surface we have been drawing to
			SDL_UpdateWindowSurface( gWindow );
			
			//Hack the window to stay up
			SDL_Event e; 
			bool quit = false; 
			while (quit == false)
			{
				while ( SDL_PollEvent( &e)  != 0 )
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
			}
		}
	}

	//Free resources and close SDL
	//Call to close to free resources and close SDL
	close();

	return 0;
}