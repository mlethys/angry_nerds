#pragma once
#include "Graphic_object.h"
#include <vector>

class Character
{
	friend class Gameplay;
protected:
	SDL_Rect * clips_move;
	SDL_Rect * clips_jump;
	SDL_Rect * clips_left_fist;
	SDL_Rect * clips_block;
	SDL_Rect * clips_left_kick;
	SDL_Rect * clips_right_fist;
	SDL_Rect * clips_right_kick;
	SDL_Rect * clips_squat;
	SDL_Rect * clips_s_attack1;
	SDL_Rect * clips_s_attack2;
	SDL_Rect * clips_victory;
	SDL_Rect * clips_fail;

	SDL_Rect hp_bar_data;
	SDL_Rect hp_bar_dest;

	SDL_Rect player_dest;
	SDL_Rect name_dest;
	SDL_Rect win_dest;

	SDL_Surface * character;
	SDL_Surface * hp_bar;
	SDL_Surface * player;
	SDL_Surface * name;
	SDL_Surface * win;
	int char_w;
	int char_h;
	int hp;
	int offset;
	int velocity;
	int move_frame;
	int jump_frame;
	int left_fist_frame;
	int block_frame;
	int left_kick_frame;
	int right_fist_frame;
	int right_kick_frame;
	int squat_frame;
	int s_attack1_frame;
	int s_attack2_frame;
	int victory_frame;
	int fail_frame;
	//--
	int status;
	int move_size;
	int jump_size;
	int left_fist_size;
	int right_fist_size;
	int left_kick_size;
	int right_kick_size;
	int block_size;
	int squat_size;
	int s_attack1_size;
	int s_attack2_size;
	int victory_size;
	int fail_size;
	//--
	bool jump;
	bool left_fist;
	bool right_fist;
	bool block;
	bool left_kick;
	bool right_kick;
	bool squat;
	bool s_attack1;
	bool s_attack2;
	bool victory;
	bool fail;
	//--
	static const int RIGHT = 0;
	static const int LEFT = 1;
	static const int BLOCK = 2;
	static const int JUMP = 3;
	static const int SQUAT = 4;
	static const int LEFT_FIST = 5;
	static const int RIGHT_FIST = 6;
	static const int LEFT_KICK = 7;
	static const int RIGHT_KICK = 8;
	static const int S_ATTACK1 = 9;
	static const int S_ATTACK2 = 10;
	static const int VICTORY = 11;
	static const int FAIL = 12;

public:
	virtual void move(Screen &scr) = 0;
	void show(Screen &scr);
    bool load_character(string filename);
	virtual void handle_events(Screen &scr) = 0;
	virtual void set_player(Screen &scr) = 0;
	void set_clips_move();
	void set_clips_jump();
	void set_clips_left_fist();
	void set_clips_block();
	void set_clips_left_kick();
	void set_clips_right_fist();
	void set_clips_right_kick();
	void set_clips_squat();
	void set_clips_s_attack1();
	void set_clips_s_attack2();
	void set_clips_victory();
	void set_clips_fail();
	void reset_hp();
	void reset_win_fail();
};