#include "Chars_menu.h"



Chars_menu::Chars_menu()
{
	avatar1 = NULL;
	avatar2 = NULL;
	avatar3 = NULL;
}

Chars_menu::Chars_menu(int data_x, int data_y, int dest_x, int dest_y)
{
	char_av1_data.w = data_x;
	char_av1_data.h = data_y;
	char_av1_data.x = 0;
	char_av1_data.y = 0;

	char_av1_dest.x = dest_x;
	char_av1_dest.y = dest_y;

	char_av2_data.w = data_x;
	char_av2_data.h = data_y;
	char_av2_data.x = 0;
	char_av2_data.y = 0;

	char_av2_dest.x = dest_x + 215;
	char_av2_dest.y = dest_y;

	char_av3_data.w = data_x;
	char_av3_data.h = data_y;
	char_av3_data.x = 0;
	char_av3_data.y = 0;

	char_av3_dest.x = dest_x + 215 *2;
	char_av3_dest.y = dest_y;

	choice = 0;
	choice2 = 0;
}



void Chars_menu::set(Screen &scr, string filename1, string filename2, string filename3)
{
	avatar1 = IMG_Load(filename1.c_str());
	SDL_BlitSurface(avatar1, &char_av1_data, scr.screen, &char_av1_dest);
	
	avatar2 = IMG_Load(filename2.c_str());
	SDL_BlitSurface(avatar2, &char_av2_data, scr.screen, &char_av2_dest);
	
	avatar3 = IMG_Load(filename3.c_str());
	SDL_BlitSurface(avatar3, &char_av3_data, scr.screen, &char_av3_dest);
}

void Chars_menu::show_clicked_p1(Screen &scr, int choice)
{
	if (choice == 1)
	{
		avatar1 = IMG_Load("char1_av_p1.png");
		SDL_BlitSurface(avatar1, &char_av1_data, scr.screen, &char_av1_dest);
		SDL_Flip(scr.screen);

	}
	else if (choice == 2)
	{
		avatar2 = IMG_Load("char2_av_p1.png");
		SDL_BlitSurface(avatar2, &char_av2_data, scr.screen, &char_av2_dest);
		SDL_Flip(scr.screen);

	}
	else if (choice == 3)
	{
		avatar3 = IMG_Load("char3_av_p1.png");
		SDL_BlitSurface(avatar3, &char_av3_data, scr.screen, &char_av3_dest);
		SDL_Flip(scr.screen);

	}

}


void Chars_menu::show_clicked_p2(Screen &scr, int choice2)
{
	if (choice2 == 1)
	{
		avatar1 = IMG_Load("char1_av_p2.png");
		SDL_BlitSurface(avatar1, &char_av1_data, scr.screen, &char_av1_dest);
		SDL_Flip(scr.screen);
	}
	else if (choice2 == 2)
	{
		avatar2 = IMG_Load("char2_av_p2.png");
		SDL_BlitSurface(avatar2, &char_av2_data, scr.screen, &char_av2_dest);
		SDL_Flip(scr.screen);
	}
	else if (choice2 == 3)
	{
		avatar3 = IMG_Load("char3_av_p2.png");
		SDL_BlitSurface(avatar3, &char_av3_data, scr.screen, &char_av3_dest);
		SDL_Flip(scr.screen);
	}	
}

void Chars_menu::reset_choice()
{
	choice = 0;
	choice2 = 0;
}