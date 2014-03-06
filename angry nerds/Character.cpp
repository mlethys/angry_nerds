#include "Character.h"


bool Character::load_character(string filename)
{
	character = IMG_Load(filename.c_str());

	if (character == NULL)
	{
		return false;
	}
	return true;
}


void Character::set_clips_move()
{
	clips_move = new SDL_Rect[move_size];

	for (int i = 0; i < move_size; i++)
	{
		clips_move[i].x = char_w *i;
		clips_move[i].y = char_h *0;
		clips_move[i].w = char_w;
		clips_move[i].h = char_h;
	}
}

void Character::set_clips_jump()
{
	clips_jump = new SDL_Rect[jump_size];

	for (int i = 0; i < jump_size; i++)
	{
		clips_jump[i].x = char_w *i;
		clips_jump[i].y = char_h *1;
		clips_jump[i].w = char_w;
		clips_jump[i].h = char_h;
	}
}


void Character::set_clips_left_fist()
{
	clips_left_fist = new SDL_Rect[left_fist_size];

	for (int i = 0; i < left_fist_size; i++)
	{
		clips_left_fist[i].x = char_w *i;
		clips_left_fist[i].y = char_h *2;
		clips_left_fist[i].w = char_w;
		clips_left_fist[i].h = char_h;
	}
}

void Character::set_clips_block()
{
	clips_block = new SDL_Rect[block_size];

	for (int i = 0; i < block_size; i++)
	{
		clips_block[i].x = char_w *i;
		clips_block[i].y = char_h *3;
		clips_block[i].w = char_w;
		clips_block[i].h = char_h;
	}
}

void Character::set_clips_left_kick()
{
	clips_left_kick = new SDL_Rect[left_kick_size];

	for (int i = 0; i < left_kick_size; i++)
	{
		clips_left_kick[i].x = char_w *i;
		clips_left_kick[i].y = char_h *4;
		clips_left_kick[i].w = char_w;
		clips_left_kick[i].h = char_h;
	}
}

void Character::set_clips_right_fist()
{
	clips_right_fist = new SDL_Rect[right_fist_size];

	for (int i = 0; i < right_fist_size; i++)
	{
		clips_right_fist[i].x = char_w *i;
		clips_right_fist[i].y = char_h *5;
		clips_right_fist[i].w = char_w;
		clips_right_fist[i].h = char_h;
	}
}

void Character::set_clips_right_kick()
{
	
	clips_right_kick = new SDL_Rect[right_kick_size];

	for (int i = 0; i < right_kick_size; i++)
	{
		clips_right_kick[i].x = char_w *i;
		clips_right_kick[i].y = char_h *6;
		clips_right_kick[i].w = char_w;
		clips_right_kick[i].h = char_h;
	}
}

void Character::set_clips_squat()
{
	clips_squat = new SDL_Rect[squat_size];

	for( int i = 0; i < squat_size; i++)
	{
		clips_squat[i].x = char_w *i;
		clips_squat[i].y = char_h *7;
		clips_squat[i].w = char_w;
		clips_squat[i].h = char_h;
	}
}

void Character::set_clips_s_attack1()
{
	clips_s_attack1 = new SDL_Rect[s_attack1_size];

	for (int i = 0; i < s_attack1_size; i++)
	{
		clips_s_attack1[i].x = char_w *i;
		clips_s_attack1[i].y = char_h *8;
		clips_s_attack1[i].w = char_w;
		clips_s_attack1[i].h = char_h;
	}
}

void Character::set_clips_s_attack2()
{
	clips_s_attack2 = new SDL_Rect[s_attack2_size];

	for (int i = 0; i < s_attack2_size; i++)
	{
		clips_s_attack2[i].x = char_w *i;
		clips_s_attack2[i].y = char_h *9;
		clips_s_attack2[i].w = char_w;
		clips_s_attack2[i].h = char_h;
	}
}

void Character::set_clips_victory()
{
	clips_victory = new SDL_Rect[victory_size];

	for (int i = 0; i < victory_size; i++)
	{
		clips_victory[i].x = char_w *i;
		clips_victory[i].y = char_h *10;
		clips_victory[i].w = char_w;
		clips_victory[i].h = char_h;
	}
}

void Character::set_clips_fail()
{
	clips_fail = new SDL_Rect[fail_size];

	for (int i = 0; i < fail_size; i++)
	{
		clips_fail[i].x = char_w *i;
		clips_fail[i].y = char_h *11;
		clips_fail[i].w = char_w;
		clips_fail[i].h = char_h;
	}
}


void Character::show(Screen &scr)
{
	if (!fail)
	{
		if (velocity < 0)
		{
			status = LEFT;
			move_frame++;
		}
		else if (velocity > 0)
		{
			status = RIGHT;
			move_frame++;
		}
		else
		{
			move_frame = 0;
		}
		if (move_frame >= move_size)
		{
			move_frame = 0;
		}

		if(jump)
		{
			status = JUMP;
			jump_frame++;
		}
		else
		{
			jump_frame = 0;
		}
		if (jump_frame >= jump_size)
		{
			jump = false;
			jump_frame = 0;
		}
		if(left_fist && !right_fist)
		{
			status = LEFT_FIST;
			left_fist_frame++;
		}
		else
		{
			left_fist_frame = 0;
		}
		if (left_fist_frame >= left_fist_size)
		{
			left_fist = false;
			left_fist_frame = 0;
		}
		if(block)
		{
			status = BLOCK;
			block_frame = 1;
		}
		else
		{
			block_frame = 0;
		}
		if(left_kick && !right_kick)
		{
			status = LEFT_KICK;
			left_kick_frame++;
		}
		else
		{
			left_kick_frame = 0;
		}
		if (left_kick_frame >= left_kick_size)
		{
			left_kick = false;
			left_kick_frame = 0;
		}
		if(right_fist && !left_fist)
		{
			status = RIGHT_FIST;
			right_fist_frame++;
		}
		else
		{
			right_fist_frame = 0;
		}
		if (right_fist_frame >= right_fist_size)
		{
			right_fist = false;
			right_fist_frame = 0;
		}
		if(right_kick && !left_kick)
		{
			status = RIGHT_KICK;
			right_kick_frame++;
		}
		else
		{
			right_kick_frame = 0;
		}
		if (right_kick_frame >= right_kick_size)
		{
			right_kick = false;
			right_kick_frame = 0;
		}
		if(squat)
		{
			status = SQUAT;
			squat_frame++;
		}
		else
		{
			squat_frame = 0; 
		}
		if (squat_frame >= squat_size)
		{
			squat = false;
			squat_frame = 0;
		}
		if(left_fist && right_fist)
		{
			status = S_ATTACK1;
			s_attack1_frame++;
		}
		else
		{
			s_attack1_frame = 0;
		}
		if (s_attack1_frame >= s_attack1_size)
		{
			left_fist = false;
			right_fist = false;
			s_attack1_frame = 0;
		}
		if(left_kick && right_kick)
		{
			status = S_ATTACK2;
			s_attack2_frame++;
		}
		else
		{
			s_attack2_frame = 0;
		}
		if (s_attack2_frame >= s_attack2_size)
		{
			left_kick = false;
			right_kick = false;
			s_attack2_frame = 0;
		}
		if(victory)
		{
			status = VICTORY;
			victory_frame++;
		}
		else
		{
			victory_frame = 0;
		}
		if (victory_frame >= victory_size)
		{
			victory_frame = victory_size;
		}
	}
	if(fail)
	{
		status = FAIL;
		fail_frame++;
	}
	else
	{
		fail_frame = 0;
	}
	if (fail_frame >= fail_size)
	{
		fail_frame = fail_size;
	}
	
	//--
	if (status == RIGHT || status == LEFT)
	{
		Graphic_object::apply_surface(offset, scr.get_screen_h() - char_h - 50, character, scr.screen, &clips_move[move_frame]);
		SDL_Delay(20);
	}
	if (status == JUMP)
	{
		Graphic_object::apply_surface(offset, scr.get_screen_h() - char_h - 50, character, scr.screen, &clips_jump[jump_frame]);
		SDL_Delay(20);
		if (jump_frame == 3)
		{
			SDL_Delay(100);
		}
	}
	if (status == LEFT_FIST)
	{
		Graphic_object::apply_surface(offset, scr.get_screen_h() - char_h - 50, character, scr.screen, &clips_left_fist[left_fist_frame]);
		SDL_Delay(60);
	}
	if (status == BLOCK)
	{
		Graphic_object::apply_surface(offset, scr.get_screen_h() - char_h - 50, character, scr.screen, &clips_block[block_frame]);
	}
	if (status == LEFT_KICK)
	{
		Graphic_object::apply_surface(offset, scr.get_screen_h() - char_h - 50, character, scr.screen, &clips_left_kick[left_kick_frame]);
		SDL_Delay(60);
		if (left_kick_frame == 3)
		{
			SDL_Delay(70);
		}
	}
	if (status == RIGHT_FIST)
	{
		Graphic_object::apply_surface(offset, scr.get_screen_h() - char_h - 50, character, scr.screen, &clips_right_fist[right_fist_frame]);
		SDL_Delay(30);
		if (right_fist_frame == 3)
		{
			SDL_Delay(65);
		}
	}
	if (status == RIGHT_KICK)
	{
		Graphic_object::apply_surface(offset, scr.get_screen_h() - char_h - 50, character, scr.screen, &clips_right_kick[right_kick_frame]);
		SDL_Delay(40);
		if (left_kick_frame == 4)
		{
			SDL_Delay(80);
		}	
	}
	if (status == SQUAT)
	{
		Graphic_object::apply_surface(offset, scr.get_screen_h() - char_h - 50, character, scr.screen, &clips_squat[squat_frame]);
		SDL_Delay(30);
		if (squat_frame == 3)
		{
			SDL_Delay(80);
		}
	}
	if (status == S_ATTACK1)
	{
		Graphic_object::apply_surface(offset, scr.get_screen_h() - char_h - 50, character, scr.screen, &clips_s_attack1[s_attack1_frame]);
		SDL_Delay(40);
	}
	if (status == S_ATTACK2)
	{
		Graphic_object::apply_surface(offset, scr.get_screen_h() - char_h - 50, character, scr.screen, &clips_s_attack2[s_attack2_frame]);
		SDL_Delay(40);
	}
	if (status == VICTORY)
	{
		Graphic_object::apply_surface(offset, scr.get_screen_h() - char_h - 50, character, scr.screen, &clips_victory[victory_frame -1]);
		SDL_Delay(40);
	}
	if (status == FAIL)
	{
		Graphic_object::apply_surface(offset, scr.get_screen_h() - char_h - 50, character, scr.screen, &clips_fail[fail_frame -1]);
		SDL_Delay(40);
	}
}


void Character::reset_hp()
{
	hp = 100;
}

void Character::reset_win_fail()
{
	victory = false;
	fail = false;
}