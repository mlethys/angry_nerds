#pragma once
#include "Character.h"


class Char_p1: public Character
{
public:
	Char_p1();
	Char_p1(int hp_, int offset_, int char_w_, int char_h_, int move_size_, int jump_size_, int squat_size_, int left_fist_size_, int right_fist_size_, int left_kick_size_, int right_kick_size_, int s_attack1_size_, int s_attack2_size_, int block_size_, int victory_size_, int fail_size_);
	void handle_events(Screen &scr); 
	void move(Screen &scr)
	{
		if(!victory && !fail)
		{
			offset += velocity;
			if (offset < 0 || offset + 180 > scr.get_screen_w())
			{
				offset -= velocity;
			}
		}
	}
	void set_player(Screen &scr)
	{
		player_dest.x = 50;
		player_dest.y = 50;

		if(player == NULL)
		{
			player = IMG_Load("player1.png");
		}
		SDL_BlitSurface(player, NULL, scr.screen, &player_dest);
	}

	int get_char_w() {return char_w;};
	int get_char_h() {return char_h;};
	int get_hp() {return hp;};
	int get_move_size() {return move_size;};
	int get_jump_size() {return jump_size;};
	int get_left_fist_size() {return left_fist_size;};
	int get_right_fist_size() {return right_fist_size;};
	int get_left_kick_size() {return left_kick_size;};
	int get_right_kick_size() {return right_kick_size;};
	int get_block_size() {return block_size;};
	int get_squat_size( ){return squat_size;};
	int get_s_attack1_size() {return s_attack1_size;};
	int get_s_attack2_size() {return s_attack2_size;};
	int get_victory_size() {return victory_size;};
	int get_fail_size() {return fail_size;};

};