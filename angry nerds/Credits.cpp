#include "Credits.h"




void Credits::set_credits(Screen &screen)
{
	Background::set_background(screen, "authors_background.jpg");
	SDL_Flip(screen.screen);
}