#pragma once
#include "Char_p2.h"
#include "Chars_menu.h"

class Gameplay
{
public:
	static void detect_colision(Char_p1 &p1, Char_p2 &p2, Screen &scr);
	static void get_damage(Char_p1 &p1, Char_p2 &p2, Chars_menu &ch_menu);
	static void hp_bar(Char_p1 &p1, Char_p2 &p2, Screen &scr);
	static void set_name(Char_p1 &p1, Char_p2 &p2, Screen &scr, Chars_menu &ch_menu);
	static void check_winner(Char_p1 & p1, Char_p2 &p2, Screen &scr);
};