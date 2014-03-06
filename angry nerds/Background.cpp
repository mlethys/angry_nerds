#include "Background.h"


void Background::set_background(Screen &scr, string filename)
{
	scr.background = Graphic_object::load_image(filename);
	SDL_FillRect(scr.screen, NULL, 0);
	SDL_BlitSurface(scr.background, NULL, scr.screen, NULL);
}


