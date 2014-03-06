#include "Arena.h"

void Arena::set_arena(Screen &screen)
{
	Background::set_background(screen, "arena.jpg");
	SDL_Flip(screen.screen);
}
