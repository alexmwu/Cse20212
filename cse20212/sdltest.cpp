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

		//If the image was optimized just fine
		if (optimizedImage != NULL)
		{
			//Map the color key
			Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0xFF);

			//Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
			SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
		}
	}
	//Return the optimized image
	return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL)
{
	//Temporary rectangle to hold the offsets
	SDL_Rect offset;

	//Get the offsets
	offset.x = x;
	offset.y = y;

	//Blit the surface
	SDL_BlitSurface(source, clip, destination, &offset);
}

SDL_Surface * init(SDL_Surface * screen)
{
	//Initialize all SDL subsystems
	SDL_Init(SDL_INIT_EVERYTHING);

	//Set up the screen
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);


	//Set the window caption
	SDL_WM_SetCaption("Moving Sprite", NULL);

	return screen;
}


int main(int argc, char* args[])
{
	//Screen attributes
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	const int SCREEN_BPP = 32;
	int moveSpeed = 10;
	//The surfaces
	SDL_Surface *pokemon = NULL;
	SDL_Surface *screen = NULL;

	//The event structure that will be used
	SDL_Event event;

	//The portions of the sprite map to be blitted
	SDL_Rect trainersquare;

	//trainer location on screen
	SDL_Rect trainerloc;

	//Initialize
	screen = init(screen);

	//enable key repeating
	if (SDL_EnableKeyRepeat(1, moveSpeed) == -1){
		return 1;
	}

	//Load dots
	pokemon = load_image("pokemon.png");

	//trainer image from sprite sheet
	trainersquare.x = 42;
	trainersquare.y = 37;
	trainersquare.w = 14;
	trainersquare.h = 18;

	//trainer location on screen
	trainerloc.x = 0;
	trainerloc.y = 0;

	//Make sure the program waits for a quit
	bool quit = false;


	//Fill the screen white
	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

	//Apply the images to the screen
	apply_surface(0, 0, pokemon, screen, &trainersquare);


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

			//If a key was pressed
			if (event.type == SDL_KEYDOWN)
			{
				//Set the proper message surface
				switch (event.key.keysym.sym)
				{
				case SDLK_UP: 
					if (trainerloc.y>0) trainerloc.y--;
					break;
				case SDLK_DOWN:
					if (trainerloc.y < SCREEN_HEIGHT-trainersquare.h) trainerloc.y++;
					break;
				case SDLK_LEFT:
					if (trainerloc.x>0) trainerloc.x--;
					break;
				case SDLK_RIGHT:
					if (trainerloc.x < SCREEN_WIDTH-trainersquare.w) trainerloc.x++;
					break;
				}

				//Fill the screen white
				SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

				//apply
				apply_surface(trainerloc.x, trainerloc.y, pokemon, screen, &trainersquare);

				//Update the screen
				if (SDL_Flip(screen) == -1)
				{
					return 1;
				}
			}

			//If the user has Xed out the window
			else if (event.type == SDL_QUIT)
			{
				//Quit the program
				quit = true;
			}
		}
	}

	SDL_FreeSurface(pokemon);

	//Free the surface and quit SDL
	SDL_Quit();

	return 0;
}