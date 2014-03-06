#pragma once
#include "Graphic_object.h"
#include "Menu_interface.h"


class Menu: public Graphic_object, public Menu_interface
{
protected:
	SDL_Event evnt;
	int mouse_x;
	int mouse_y;
	

public:
	SDL_Surface * start_button;
	SDL_Surface * options_button;
	SDL_Surface * credits_button;
	SDL_Surface * close_button;
	
	SDL_Rect button_start_data;
	SDL_Rect button_start_dest;

	SDL_Rect button_options_data;
	SDL_Rect button_options_dest;

	SDL_Rect button_credits_data;
	SDL_Rect button_credits_dest;

	SDL_Rect button_close_data;
	SDL_Rect button_close_dest;

public:
	Menu();
	Menu(int button_data_w, int button_data_h, int button_dest_x, int button_dest_y);
	~Menu();
	void set_menu(Screen &scr, string start_filename, string options_filename, string credits_filename, string close_filename);
	int choice;
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
				if(evnt.button.button == SDL_BUTTON_LEFT && (mouse_x >=button_start_dest.x && mouse_x <= button_start_dest.x + button_start_data.w)
					&& (mouse_y >= button_start_dest.y && mouse_y <= button_start_dest.y + button_start_data.h))
				{
					return 1;
				}
				if(evnt.button.button == SDL_BUTTON_LEFT && (mouse_x >=button_options_dest.x && mouse_x <= button_options_dest.x + button_options_data.w)
					&& (mouse_y >= button_options_dest.y && mouse_y <= button_options_dest.y + button_options_data.h))
				{
					return 2;
				}
				if(evnt.button.button == SDL_BUTTON_LEFT && (mouse_x >=button_credits_dest.x && mouse_x <= button_credits_dest.x + button_credits_data.w)
					&& (mouse_y >= button_credits_dest.y && mouse_y <= button_credits_dest.y + button_credits_data.h))
				{
					return 3;
				}
				if(evnt.button.button == SDL_BUTTON_LEFT && (mouse_x >=button_close_dest.x && mouse_x <= button_close_dest.x + button_close_data.w)
					&& (mouse_y >= button_close_dest.y && mouse_y <= button_close_dest.y + button_close_data.h))
				{
					return 4;
				}
			}
		}
		return 0;
	}
};