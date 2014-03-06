#include "Options.h"

void Options::set_options(Screen &scr)
{
	Background::set_background(scr, "options_background.png");
	SDL_Flip(scr.screen);
}