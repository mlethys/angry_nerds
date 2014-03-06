#pragma once
#include "Char_p1.h"


class Char_p2: public Character
{
public:
	Char_p2();
	Char_p2(Char_p1 &ch_p1, int offset_);
	void move(Screen &scr)
	{
		if(!victory && !fail)
		{
			offset += velocity;
			if (offset < 0 || offset + char_w > scr.get_screen_w())
			{
				offset -= velocity;
			}
		}
	}
	void set_player(Screen &scr)
	{
		player_dest.x = 575;
		player_dest.y = 50;

		if(player == NULL)
		{
			player = IMG_Load("player2.png");
		}
		SDL_BlitSurface(player, NULL, scr.screen, &player_dest);
	}
	void handle_events(Screen &scr); 
};