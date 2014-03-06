#include "Screen.h"

Screen::Screen()
{
	screen_w = 0;
	screen_h = 0;
	fps = 0;
	screen_bbp = 0;
}

Screen::Screen(int screen_w_, int screen_h_, int screen_bbp_, int fps_)
{
	screen = NULL;
	background = NULL;
	screen_w = screen_w_;
	screen_h = screen_h_;
	screen_bbp = screen_bbp_;
	fps = fps_;
	quit = false;
}


void Screen::reset_quit()
{
	quit = false;
}
void Screen::set_quit()
{
	quit = true;
}

bool Screen::init()
{
	if ((SDL_Init(SDL_INIT_EVERYTHING) == -1) || (SDL_Init(SDL_INIT_EVENTTHREAD) == -1))
	{
		return false;
	}

	screen = SDL_SetVideoMode(screen_w, screen_h, screen_bbp, SDL_FULLSCREEN);
	SDL_WM_SetCaption( "Angry Nerds", NULL );

	if (screen == NULL)
	{
		return false;
	}

	return true;
}