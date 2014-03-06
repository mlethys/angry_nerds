#include "Menu.h"


Menu::Menu()
{
	start_button = NULL;
	options_button = NULL;
	credits_button = NULL;
	close_button = NULL;
}



Menu::Menu(int button_data_w, int button_data_h, int button_dest_x, int button_dest_y)
{

	button_start_data.w = button_data_w;
	button_start_data.h = button_data_h;
	button_start_data.x = 0;
	button_start_data.y = 0;

	
	button_options_data.w = button_data_w;
	button_options_data.h = button_data_h;
	button_options_data.x = 0;
	button_options_data.y = 0;

	button_credits_data.w = button_data_w;
	button_credits_data.h = button_data_h;
	button_credits_data.x = 0;
	button_credits_data.y = 0;

	button_close_data.w = button_data_w;
	button_close_data.h = button_data_h;
	button_close_data.x = 0;
	button_close_data.y = 0;


	//---

	button_start_dest.x = button_dest_x;
	button_start_dest.y = button_dest_y;

	button_options_dest.x = button_dest_x;
	button_options_dest.y = button_dest_y + 120;

	button_credits_dest.x = button_dest_x;
	button_credits_dest.y = button_dest_y + 120 *2;

	button_close_dest.x = button_dest_x;
	button_close_dest.y = button_dest_y + 120 *3;

}

Menu::~Menu()
{
	SDL_FreeSurface(start_button);
	SDL_FreeSurface(options_button);
	SDL_FreeSurface(credits_button);
	SDL_FreeSurface(close_button);
}

void Menu::set_menu(Screen &scr, string start_filename, string options_filename, string credits_filename, string close_filename)
{
	start_button = IMG_Load(start_filename.c_str());
	SDL_BlitSurface(start_button, &button_start_data, scr.screen, &button_start_dest);

	options_button = IMG_Load(options_filename.c_str());
	SDL_BlitSurface(options_button, &button_options_data, scr.screen, &button_options_dest);

	credits_button = IMG_Load(credits_filename.c_str());
	SDL_BlitSurface(credits_button, &button_credits_data, scr.screen, &button_credits_dest);
		
	close_button = IMG_Load(close_filename.c_str());
	SDL_BlitSurface(close_button, &button_close_data, scr.screen, &button_close_dest);
}


