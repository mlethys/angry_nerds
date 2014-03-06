#include "Credits.h"
#include "Arena.h"
#include "Back.h"
#include "Timer.h"
#include "Char_p2.h"
#include "Chars_menu.h"
#include "Options.h"
#include "Gameplay.h"




int main(int argc, char * args[])
{
	Screen screen(1024, 768, 32, 60);
	if (screen.init() == false)
	{
		return 1;
	}
	Menu menu(350, 80, 337, 200);
	Chars_menu ch_menu(193, 219, 200, 300);	
	Background::set_background(screen, "background.png");
	menu.set_menu(screen, "start_button.png", "options_button.png", "credits_button.png", "close_button.png");
	Char_p1 ch3_p1(100, 50, 290, 300, 3, 4, 4, 4, 4, 4, 5, 8, 11, 2, 4, 4);
	Char_p1 ch2_p1(100, 50, 150, 300, 4, 4, 4, 4, 4, 4, 5, 6, 5, 2, 3, 4);
	Char_p1 ch1_p1(100, 50, 160, 300, 4, 4, 4, 2, 4, 4, 5, 8, 6, 2, 3, 4);
	Char_p2 ch1_p2(ch1_p1, 600);
	Char_p2 ch2_p2(ch2_p1, 600);
	Char_p2 ch3_p2(ch3_p1, 600);
	Timer fps(0, 0);
	while(true)
	{

		ch3_p1.reset_hp();
		ch2_p1.reset_hp();
		ch1_p1.reset_hp();

		ch3_p2.reset_hp();
		ch2_p2.reset_hp();
		ch1_p2.reset_hp();

		ch3_p1.reset_win_fail();
		ch2_p1.reset_win_fail();
		ch1_p1.reset_win_fail();

		ch3_p2.reset_win_fail();
		ch2_p2.reset_win_fail();
		ch1_p2.reset_win_fail();

		menu.choice = menu.is_clicked();
		if(menu.choice == 1)
		{
			Background::set_background(screen, "background_chars_options.png");
			ch_menu.set(screen, "char1_av.png", "char2_av.png", "char3_av.png");
			SDL_Flip(screen.screen);
			screen.reset_quit();
			ch_menu.reset_choice();
			
			while(!screen.qet_quit())
			{
				if (ch_menu.choice == 0)
				{
					ch_menu.choice = ch_menu.is_clicked();
					ch_menu.show_clicked_p1(screen, ch_menu.choice);
				}
				if (ch_menu.choice == 1)
				{
					ch_menu.show_clicked_p1(screen, ch_menu.choice);
					while (ch_menu.choice2 == 0)
					{
						ch_menu.choice2 = ch_menu.is_clicked();
						ch_menu.show_clicked_p2(screen, ch_menu.choice2);
					}
					switch(ch_menu.choice2)
					{
					case 2:
						if (!ch2_p2.load_character("char2_p2.png"))
						{
							return 1;
						}
						break;
					case 3:
						if (!ch3_p2.load_character("char3_p2.png"))
						{
							return 1;
						}
						break; 
					}
					if (!ch1_p1.load_character("char_1.png"))
					{
						return 1;
					}
					Arena::set_arena(screen);
					ch1_p1.set_clips_move();
					ch1_p1.set_clips_jump();
					ch1_p1.set_clips_left_fist();
					ch1_p1.set_clips_block();
					ch1_p1.set_clips_left_kick();
					ch1_p1.set_clips_right_fist();
					ch1_p1.set_clips_right_kick();
					ch1_p1.set_clips_squat();
					ch1_p1.set_clips_s_attack1();
					ch1_p1.set_clips_s_attack2();
					ch1_p1.set_clips_fail();
					ch1_p1.set_clips_victory();
					switch(ch_menu.choice2)
					{
					case 2:
						ch2_p2.set_clips_move();
						ch2_p2.set_clips_jump();
						ch2_p2.set_clips_left_fist();
						ch2_p2.set_clips_block();
						ch2_p2.set_clips_left_kick();
						ch2_p2.set_clips_right_fist();
						ch2_p2.set_clips_right_kick();
						ch2_p2.set_clips_squat();
						ch2_p2.set_clips_s_attack1();
						ch2_p2.set_clips_s_attack2();
						ch2_p2.set_clips_fail();
						ch2_p2.set_clips_victory();
						break;
					case 3:
						ch3_p2.set_clips_move();
						ch3_p2.set_clips_jump();
						ch3_p2.set_clips_left_fist();
						ch3_p2.set_clips_block();
						ch3_p2.set_clips_left_kick();
						ch3_p2.set_clips_right_fist();
						ch3_p2.set_clips_right_kick();
						ch3_p2.set_clips_squat();
						ch3_p2.set_clips_s_attack1();
						ch3_p2.set_clips_s_attack2();
						ch3_p2.set_clips_fail();
						ch3_p2.set_clips_victory();
						break;
					}
					while(!screen.qet_quit())
					{
						fps.start();
						while(SDL_PollEvent(&screen.screen_event))
						{
							ch1_p1.handle_events(screen);
							switch(ch_menu.choice2)
							{
							case 2:
								ch2_p2.handle_events(screen);
								break;
							case 3:
								ch3_p2.handle_events(screen);
								break;
							}
							if (screen.screen_event.type == SDL_KEYDOWN)
							{
								switch(screen.screen_event.key.keysym.sym)
								{
								case SDLK_ESCAPE:
									screen.set_quit();
									break;
								}
							}
						}
						ch1_p1.move(screen);
						switch(ch_menu.choice2)
						{
						case 2:
							ch2_p2.move(screen);
							break;
						case 3:
							ch3_p2.move(screen);
							break;
						}
						SDL_BlitSurface(screen.background, NULL, screen.screen, NULL);
						ch1_p1.show(screen);
						ch1_p1.set_player(screen);
						switch(ch_menu.choice2)
						{
						case 2:
							ch2_p2.show(screen);
							ch2_p2.set_player(screen);
							Gameplay::hp_bar(ch1_p1, ch2_p2, screen);
							Gameplay::get_damage(ch1_p1, ch2_p2, ch_menu);
							Gameplay::detect_colision(ch1_p1, ch2_p2, screen);
							Gameplay::check_winner(ch1_p1, ch2_p2, screen);
							Gameplay::set_name(ch1_p1, ch2_p2, screen, ch_menu);
							break;
						case 3:
							ch3_p2.show(screen);
							ch3_p2.set_player(screen);
							Gameplay::hp_bar(ch1_p1, ch3_p2, screen);
							Gameplay::get_damage(ch1_p1, ch3_p2, ch_menu);
							Gameplay::detect_colision(ch1_p1, ch3_p2, screen);
							Gameplay::check_winner(ch1_p1, ch3_p2, screen);
							Gameplay::set_name(ch1_p1, ch3_p2, screen, ch_menu);
							break;
						}
						SDL_Flip(screen.screen);
						if ( fps.get_ticks() < 1000 / screen.get_screen_fps() )
						{
							SDL_Delay( ( 1000 / screen.get_screen_fps() ) - fps.get_ticks() );
						}
					}
				}
				else if (ch_menu.choice == 2)
				{
					while (ch_menu.choice2 == 0)
					{
						ch_menu.choice2 = ch_menu.is_clicked();
						ch_menu.show_clicked_p2(screen, ch_menu.choice2);
					}
					if (!ch2_p1.load_character("char_2.png"))
					{
						return 1;
					}
					switch(ch_menu.choice2)
					{
					case 1:
						if (!ch1_p2.load_character("char1_p2.png"))
						{
							return 1;
						}
						break;
					case 3:
						if (!ch3_p2.load_character("char3_p2.png"))
						{
							return 1;
						}
						break;
					}
					Arena::set_arena(screen);
					ch2_p1.set_clips_move();
					ch2_p1.set_clips_jump();
					ch2_p1.set_clips_left_fist();
					ch2_p1.set_clips_block();
					ch2_p1.set_clips_left_kick();
					ch2_p1.set_clips_right_fist();
					ch2_p1.set_clips_right_kick();
					ch2_p1.set_clips_squat();
					ch2_p1.set_clips_s_attack1();
					ch2_p1.set_clips_s_attack2();
					ch2_p1.set_clips_fail();
					ch2_p1.set_clips_victory();
					switch(ch_menu.choice2)
					{
					case 1:
						ch1_p2.set_clips_move();
						ch1_p2.set_clips_jump();
						ch1_p2.set_clips_left_fist();
						ch1_p2.set_clips_block();
						ch1_p2.set_clips_left_kick();
						ch1_p2.set_clips_right_fist();
						ch1_p2.set_clips_right_kick();
						ch1_p2.set_clips_squat();
						ch1_p2.set_clips_s_attack1();
						ch1_p2.set_clips_s_attack2();
						ch1_p2.set_clips_fail();
						ch1_p2.set_clips_victory();
						break;
					case 3:
						ch3_p2.set_clips_move();
						ch3_p2.set_clips_jump();
						ch3_p2.set_clips_left_fist();
						ch3_p2.set_clips_block();
						ch3_p2.set_clips_left_kick();
						ch3_p2.set_clips_right_fist();
						ch3_p2.set_clips_right_kick();
						ch3_p2.set_clips_squat();
						ch3_p2.set_clips_s_attack1();
						ch3_p2.set_clips_s_attack2();
						ch3_p2.set_clips_fail();
						ch3_p2.set_clips_victory();
						break;
					}
					while(!screen.qet_quit())
					{
						fps.start();
						while(SDL_PollEvent(&screen.screen_event))
						{
							ch2_p1.handle_events(screen);
							switch(ch_menu.choice2)
							{
							case 1:
								ch1_p2.handle_events(screen);
								break;
							case 3:
								ch3_p2.handle_events(screen);
								break;
							}
							if (screen.screen_event.type == SDL_KEYDOWN)
							{
								switch(screen.screen_event.key.keysym.sym)
								{
								case SDLK_ESCAPE:
									screen.set_quit();
									break;
								}
							}
						}
						ch2_p1.move(screen);
						switch(ch_menu.choice2)
						{
						case 1:
							ch1_p2.move(screen);
							break;
						case 3:
							ch3_p2.move(screen);
							break;
						}
						SDL_BlitSurface(screen.background, NULL, screen.screen, NULL);
						ch2_p1.show(screen);
						ch2_p1.set_player(screen);
						switch(ch_menu.choice2)
						{
						case 1:
							ch1_p2.show(screen);
							ch1_p2.set_player(screen);
							Gameplay::hp_bar(ch2_p1, ch1_p2, screen);
							Gameplay::get_damage(ch2_p1, ch1_p2, ch_menu);
							Gameplay::detect_colision(ch2_p1, ch1_p2, screen);
							Gameplay::check_winner(ch2_p1, ch1_p2, screen);
							Gameplay::set_name(ch2_p1, ch1_p2, screen, ch_menu);
							break;
						case 3:
							ch3_p2.show(screen);
							ch3_p2.set_player(screen);
							Gameplay::hp_bar(ch2_p1, ch3_p2, screen);
							Gameplay::get_damage(ch2_p1, ch3_p2, ch_menu);
							Gameplay::detect_colision(ch2_p1, ch3_p2, screen);
							Gameplay::check_winner(ch2_p1, ch3_p2, screen);
							Gameplay::set_name(ch2_p1, ch3_p2, screen, ch_menu);
							break;
						}
						SDL_Flip(screen.screen);
						if ( fps.get_ticks() < 1000 / screen.get_screen_fps() )
						{
							SDL_Delay( ( 1000 / screen.get_screen_fps() ) - fps.get_ticks() );
						}
					}
				}
				else if (ch_menu.choice == 3)
				{
					
					while (ch_menu.choice2 == 0)
					{
						ch_menu.choice2 = ch_menu.is_clicked();
						ch_menu.show_clicked_p2(screen, ch_menu.choice2);
					}
					if (!ch3_p1.load_character("char_3.png"))
					{
						return 1;
					}
					switch(ch_menu.choice2)
					{
					case 1:
						if(!ch1_p2.load_character("char1_p2.png"))
						{
							return 1;
						}
						break;
					case 2:
						if(!ch2_p2.load_character("char2_p2.png"))
						{
							return 1;
						}
						break;
					}
					Arena::set_arena(screen);
					ch3_p1.set_clips_move();
					ch3_p1.set_clips_jump();
					ch3_p1.set_clips_left_fist();
					ch3_p1.set_clips_block();
					ch3_p1.set_clips_left_kick();
					ch3_p1.set_clips_right_fist();
					ch3_p1.set_clips_right_kick();
					ch3_p1.set_clips_squat();
					ch3_p1.set_clips_s_attack1();
					ch3_p1.set_clips_s_attack2();
					ch3_p1.set_clips_fail();
					ch3_p1.set_clips_victory();
					switch(ch_menu.choice2)
					{
					case 1:
						ch1_p2.set_clips_move();
						ch1_p2.set_clips_jump();
						ch1_p2.set_clips_left_fist();
						ch1_p2.set_clips_block();
						ch1_p2.set_clips_left_kick();
						ch1_p2.set_clips_right_fist();
						ch1_p2.set_clips_right_kick();
						ch1_p2.set_clips_squat();
						ch1_p2.set_clips_s_attack1();
						ch1_p2.set_clips_s_attack2();
						ch1_p2.set_clips_fail();
						ch1_p2.set_clips_victory();
						break;
					case 2:
						ch2_p2.set_clips_move();
						ch2_p2.set_clips_jump();
						ch2_p2.set_clips_left_fist();
						ch2_p2.set_clips_block();
						ch2_p2.set_clips_left_kick();
						ch2_p2.set_clips_right_fist();
						ch2_p2.set_clips_right_kick();
						ch2_p2.set_clips_squat();
						ch2_p2.set_clips_s_attack1();
						ch2_p2.set_clips_s_attack2();
						ch2_p2.set_clips_fail();
						ch2_p2.set_clips_victory();
						break;
					}
					while(!screen.qet_quit())
					{
						fps.start();
						while(SDL_PollEvent(&screen.screen_event))
						{
							ch3_p1.handle_events(screen);
							switch(ch_menu.choice2)
							{
							case 1:
								ch1_p2.handle_events(screen);
								break;
							case 2:
								ch2_p2.handle_events(screen);
								break;
							}
							if (screen.screen_event.type == SDL_KEYDOWN)
							{
								switch(screen.screen_event.key.keysym.sym)
								{
								case SDLK_ESCAPE:
									screen.set_quit();
									break;
								}
							}
						}
						ch3_p1.move(screen);
						switch(ch_menu.choice2)
						{
						case 1:
							ch1_p2.move(screen);
							break;
						case 2:
							ch2_p2.move(screen);
							break;
						}
						SDL_BlitSurface(screen.background, NULL, screen.screen, NULL);
						ch3_p1.show(screen);
						ch3_p1.set_player(screen);
						switch(ch_menu.choice2)
						{
						case 1:
							ch1_p2.show(screen);
							ch1_p2.set_player(screen);
							Gameplay::hp_bar(ch3_p1, ch1_p2, screen);
							Gameplay::get_damage(ch3_p1, ch1_p2, ch_menu);
							Gameplay::detect_colision(ch3_p1, ch1_p2, screen);
							Gameplay::check_winner(ch3_p1, ch1_p2, screen);
							Gameplay::set_name(ch3_p1, ch1_p2, screen, ch_menu);
							break;
						case 2:
							ch2_p2.show(screen);
							ch2_p2.set_player(screen);
							Gameplay::hp_bar(ch3_p1, ch2_p2, screen);
							Gameplay::get_damage(ch3_p1, ch2_p2, ch_menu);
							Gameplay::detect_colision(ch3_p1, ch2_p2, screen);
							Gameplay::check_winner(ch3_p1, ch2_p2, screen);
							Gameplay::set_name(ch3_p1, ch2_p2, screen, ch_menu);
							break;
						}
						SDL_Flip(screen.screen);
						if ( fps.get_ticks() < 1000 / screen.get_screen_fps() )
						{
							SDL_Delay( ( 1000 / screen.get_screen_fps() ) - fps.get_ticks() );
						}
					}
				}
			}
			if(Back::back())
			{
				Background::set_background(screen, "background.png");
				menu.set_menu(screen, "start_button.png", "options_button.png", "credits_button.png", "close_button.png");
			}
		}
		if(menu.choice == 2)
		{
			Options::set_options(screen);
			if(Back::back())
			{
				Background::set_background(screen, "background.png");
				menu.set_menu(screen, "start_button.png", "options_button.png", "credits_button.png", "close_button.png");
			}
		}
		if(menu.choice == 3)
		{
			Credits::set_credits(screen);
			if(Back::back())
			{
				Background::set_background(screen, "background.png");
				menu.set_menu(screen, "start_button.png", "options_button.png", "credits_button.png", "close_button.png");
			}
		}
		if(menu.choice == 4)
		{	
			break;
		}
		SDL_Flip(screen.screen);
		
	}
	SDL_Quit();
	return 0;
}