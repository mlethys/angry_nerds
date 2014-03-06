#include "Back.h"


bool Back::back()
{
	SDL_Event evnt;
	bool quit = false;
	while(!quit)
	{
		while(SDL_PollEvent(&evnt))
		{
			if (evnt.type == SDL_KEYDOWN)
			{
				switch(evnt.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					return true;
					break;
				}
			}
			break;
		}
	}
	return false;
}