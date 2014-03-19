#include "SDL.h"
#include "SDL_image.h"
#include <string>

//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;


SDL_Surface *load_image(std::string filename)
{
	//The image that's loaded
	SDL_Surface* loadedImage = NULL;

	//The optimized image that will be used
	SDL_Surface* optimizedImage = NULL;

	//Load the image
	loadedImage = IMG_Load(filename.c_str());

	//If the image loaded
	if (loadedImage != NULL)
	{
		//Create an optimized image
		optimizedImage = SDL_DisplayFormat(loadedImage);

		//Free the old image
		SDL_FreeSurface(loadedImage);
	}

	//If the image was optimized just fine
	if (optimizedImage != NULL)
	{
		//Map the color key
		Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0xFF);
		
		//Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
		SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
	}

	//Return the optimized image
	return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
	//Temporary rectangle to hold the offsets
	SDL_Rect offset;

	//Get the offsets
	offset.x = x;
	offset.y = y;

	//Blit the surface
	SDL_BlitSurface(source, NULL, destination, &offset);
}

bool init(SDL_Surface * screen)
{
	//Initialize all SDL subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}

	//Set up the screen
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

	//If there was an error in setting up the screen
	if (screen == NULL)
	{
		return false;
	}

	//Set the window caption
	SDL_WM_SetCaption("Event test", NULL);

	//If everything initialized fine
	return true;
}


int main(int argc, char* args[])
{
	//The surfaces
	SDL_Surface *dots = NULL;
	SDL_Surface *screen = NULL;

	//The event structure that will be used
	SDL_Event event;

	//The portions of the sprite map to be blitted
	SDL_Rect clip[4];

	//Make sure the program waits for a quit
	bool quit = false;
	//Initialize
	if (init(screen) == false)
	{
		return 1;
	}



	//Update the screen
	if (SDL_Flip(screen) == -1)
	{
		return 1;
	}

	//While the user hasn't quit
	while (quit == false)
	{
		//While there's an event to handle
		while (SDL_PollEvent(&event))
		{
			//If the user has Xed out the window
			if (event.type == SDL_QUIT)
			{
				//Quit the program
				quit = true;
			}
		}
	}

	//Free the surface and quit SDL
	SDL_Quit();

	return 0;
}