#include "Char_p1.h"


Char_p1::Char_p1(int hp_, int offset_, int char_w_, int char_h_, int move_size_, int jump_size_, int squat_size_, int left_fist_size_, int right_fist_size_, int left_kick_size_, int right_kick_size_, int s_attack1_size_, int s_attack2_size_, int block_size_, int victory_size_, int fail_size_)
{
	character = NULL;
	hp_bar = NULL;
	name = NULL;
	player = NULL;
	win = NULL;
	char_w = char_w_;
	char_h = char_h_;
	hp = hp_;
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
	//--
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

	move_size = move_size_;
	jump_size = jump_size_;
	left_fist_size = left_fist_size_;
	right_fist_size = right_fist_size_;
	left_kick_size = left_kick_size_;
	right_kick_size = right_kick_size_;
	block_size = block_size_;
	squat_size = squat_size_;
	s_attack1_size = s_attack1_size_;
	s_attack2_size = s_attack2_size_;
	victory_size = victory_size_;
	fail_size = fail_size_;
}




void Char_p1::handle_events(Screen &scr)
{
		if( scr.screen_event.type == SDL_KEYDOWN )
		{

			switch( scr.screen_event.key.keysym.sym )
			{
				case SDLK_h: 
					velocity += char_w / 4; 
					break;
				case SDLK_f: 
					velocity -= char_w / 4; 
					break;
				case SDLK_t:
					jump = true;
					break;
				case SDLK_q:
					left_fist = true;
					break;
				case SDLK_e:
					block = true;
					break;
				case SDLK_a:
					left_kick = true;
					break;
				case SDLK_w:
					right_fist = true;
					break;
				case SDLK_s:
					right_kick = true;
					break;
				case SDLK_g:
					squat = true;
					break;
			}
		}

		else if( scr.screen_event.type == SDL_KEYUP )
		{
		switch( scr.screen_event.key.keysym.sym )
			{
				case SDLK_h: 
					velocity -= char_w / 4; 
					break;
				case SDLK_f: 
					velocity += char_w / 4; 
					break;
				case SDLK_e:
					block = false;
					break;
			}
		}
}
