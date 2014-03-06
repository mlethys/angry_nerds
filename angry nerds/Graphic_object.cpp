#include "Graphic_object.h"



SDL_Surface * Graphic_object::load_image(string filename)
{
	SDL_Surface * loaded_img = NULL;
	SDL_Surface * optimized_img = NULL;

	loaded_img = IMG_Load(filename.c_str());

	if (loaded_img != NULL)
	{
		optimized_img = SDL_DisplayFormat(loaded_img);
		SDL_FreeSurface(loaded_img);
	
		if (optimized_img != NULL)
		{
			SDL_SetColorKey(optimized_img, SDL_SRCCOLORKEY, SDL_MapRGB(optimized_img->format, 0, 0xFF, 0xFF));
		}
	}
	
	return optimized_img;
}


void Graphic_object::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
	SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( source, clip, destination, &offset );
}
