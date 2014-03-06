#include "Char_p2.h"


Char_p2::Char_p2(Char_p1 &ch_p1, int offset_)
{
	character = NULL;
	hp_bar = NULL;
	name = NULL;
	player = NULL;
	win = NULL;
	char_w = ch_p1.get_char_w();
	char_h = ch_p1.get_char_h();
	hp = ch_p1.get_hp();
	offset = offset_;
	velocity = 0;
	move_frame = 0;
	jump_frame = 0;
	left_fist_frame = 0;
	block_frame = 0;
	left_kick_frame = 0;
	right_fist_frame = 0;
	right_kick_frame = 0;
	squat_frame = 0;
	s_attack1_frame = 0;
	s_attack2_frame = 0;
	victory_frame = 0;
	fail_frame = 0;
	status = RIGHT;
	jump = false;
	left_fist = false;
	right_fist = false;
	block = false;
	left_kick = false;
	right_fist = false;
	right_kick = false;
	squat = false;
	s_attack1 = false;
	s_attack2 = false;
	victory = false;
	fail = false;

	move_size = ch_p1.get_move_size();
	jump_size = ch_p1.get_jump_size();
	left_fist_size = ch_p1.get_left_fist_size();
	right_fist_size = ch_p1.get_right_fist_size();
	left_kick_size = ch_p1.get_left_kick_size();
	right_kick_size = ch_p1.get_right_kick_size();
	block_size = ch_p1.get_block_size();
	squat_size = ch_p1.get_squat_size();
	s_attack1_size = ch_p1.get_s_attack1_size();
	s_attack2_size = ch_p1.get_s_attack2_size();
	victory_size = ch_p1.get_victory_size();
	fail_size = ch_p1.get_fail_size();
}



void Char_p2::handle_events(Screen &scr)
{
		if( scr.screen_event.type == SDL_KEYDOWN )
		{

			switch( scr.screen_event.key.keysym.sym )
			{
				case SDLK_RIGHT: 
					velocity += char_w / 4; 
					break;
				case SDLK_LEFT: 
					velocity -= char_w / 4; 
					break;
				case SDLK_UP:
					jump = true;
					break;
				case SDLK_o:
					left_fist = true;
					break;
				case SDLK_LEFTBRACKET:
					block = true;
					break;
				case SDLK_l:
					left_kick = true;
					break;
				case SDLK_p:
					right_fist = true;
					break;
				case SDLK_SEMICOLON:
					right_kick = true;
					break;
				case SDLK_DOWN:
					squat = true;

			}
		}

		else if( scr.screen_event.type == SDL_KEYUP )
		{
		switch( scr.screen_event.key.keysym.sym )
			{
				case SDLK_RIGHT: 
					velocity -= char_w / 4; 
					break;
				case SDLK_LEFT: 
					velocity += char_w / 4; 
					break;
				case SDLK_LEFTBRACKET:
					block = false;
					break;
			}
		}
}