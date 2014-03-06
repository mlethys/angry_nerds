#pragma once
#include "Graphic_object.h"
#include "Menu_interface.h"

class Chars_menu: public Graphic_object, public Menu_interface
{
private:
	SDL_Surface *avatar1;
	SDL_Surface *avatar2;
	SDL_Surface *avatar3;

	SDL_Rect char_av1_data;
	SDL_Rect char_av1_dest;

	SDL_Rect char_av2_data;
	SDL_Rect char_av2_dest;

	SDL_Rect char_av3_data;
	SDL_Rect char_av3_dest;

	SDL_Event evnt;
	int mouse_x;
	int mouse_y;

public:
	Chars_menu();
	Chars_menu(int data_x, int data_y, int dest_x, int dest_y);
	int choice;
	int choice2;
	void set(Screen &scr, string filename, string filename2, string filename3);
	void show_clicked_p1(Screen &scr, int choice);
	void show_clicked_p2(Screen &scr, int choice2);
	void reset_choice();
	int is_clicked()
	{
		while(SDL_PollEvent(&evnt))
		{
			if(evnt.type == SDL_MOUSEMOTION)
			{
				mouse_x = evnt.motion.x;
				mouse_y = evnt.motion.y;
			}
			if(evnt.type == SDL_MOUSEBUTTONDOWN)
			{
				if(evnt.button.button == SDL_BUTTON_LEFT && (mouse_x >=char_av1_dest.x && mouse_x <= char_av1_dest.x + char_av1_data.w)
					&& (mouse_y >= char_av1_dest.y && mouse_y <= char_av1_dest.y + char_av1_data.h))
				{
					return 1;
				}
				if(evnt.button.button == SDL_BUTTON_LEFT && (mouse_x >=char_av2_dest.x && mouse_x <= char_av2_dest.x + char_av2_data.w)
					&& (mouse_y >= char_av2_dest.y && mouse_y <= char_av2_dest.y + char_av2_data.h))
				{
					return 2;
				}
				if(evnt.button.button == SDL_BUTTON_LEFT && (mouse_x >=char_av3_dest.x && mouse_x <= char_av3_dest.x + char_av3_data.w)
					&& (mouse_y >= char_av3_dest.y && mouse_y <=char_av3_dest.y + char_av3_data.h))
				{
					return 3;
				}
			}
		}
		return 0;
	}
};