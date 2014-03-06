#include "Gameplay.h"



void Gameplay::detect_colision(Char_p1 &p1, Char_p2 &p2, Screen &scr)
{
	if((p1.offset + p1.char_w - 185) >= (p2.offset) && (p1.char_w <= 170 && p2.char_w <= 170 ))
	{
		p1.offset -= p1.velocity;
		p2.offset -= p2.velocity;
	}
	if ((p1.offset + p1.char_w - 320) >= (p2.offset) && (p1.char_w > 170 || p2.char_w > 170 ))
	{
		p1.offset -= p1.velocity;
		p2.offset -= p2.velocity;
	}
}

void Gameplay::get_damage(Char_p1 &p1, Char_p2 &p2, Chars_menu &ch_menu)
{

	if(((p1.offset + p1.char_w - 150) >= (p2.offset) && (p1.char_w <= 170 && p2.char_w <= 170 )) || 
		((p1.offset + p1.char_w - 200) >= (p2.offset) && (p1.char_w > 170 || p2.char_w > 170 )))
	{
		if(!p2.block)
		{
			switch(ch_menu.choice)
			{
			case 1:
				if(p1.left_fist_frame == 1 || p1.right_fist_frame == 2)
				{
					p2.hp -= 10;
				}
				if(p1.left_kick_frame == 2 || p1.right_kick_frame == 3)
				{
					p2.hp -= 20;
				}
				if(p1.s_attack1_frame == 7)
				{
					p2.hp -= 40;
				}
				if(p1.s_attack2_frame == 2)
				{
					p2.hp -= 20;
					if(p1.s_attack2_frame == 4)
					{
						p2.hp -=20;
					}
				}
				break;
			case 2:
				if(p1.left_fist_frame == 2 || p1.right_fist_frame == 2)
				{
					p2.hp -= 10;
				}
				if(p1.left_kick_frame == 2 || p1.right_kick_frame == 3)
				{
					p2.hp -= 20;
				}
				if(p1.s_attack1_frame == 2)
				{
					p2.hp -= 20;
					if(p1.s_attack1_frame == 4)
					{
						p2.hp -= 20;
					}
				}
				if(p1.s_attack2_frame == 3)
				{
					p2.hp -= 30;
				}
				break;
			case 3:
				if(p1.left_fist_frame == 2 || p1.right_fist_frame == 2)
				{
					p2.hp -= 10;
				}
				if(p1.left_kick_frame == 2 || p1.right_kick_frame == 3)
				{
					p2.hp -= 20;
				}
				if(p1.s_attack1_frame == 2)
				{
					p2.hp -= 20;
					if(p1.s_attack1_frame == 6)
					{
						p2.hp -= 20;
					}
				}
			}
		}
		//--
		if(!p1.block)
		{
			switch(ch_menu.choice2)
			{
			case 1:
				if(p2.left_fist_frame == 1 || p2.right_fist_frame == 2)
				{
					p1.hp -= 10;
				}
				if(p2.left_kick_frame == 2 || p2.right_kick_frame == 3)
				{
					p1.hp -= 20;
				}
				if(p2.s_attack1_frame == 7)
				{
					p1.hp -= 40;
				}
				if(p2.s_attack2_frame == 2)
				{
					p1.hp -= 20;
					if(p2.s_attack2_frame == 4)
					{
						p1.hp -=20;
					}
				}
				break;
			case 2:
				if(p2.left_fist_frame == 2 || p2.right_fist_frame == 2)
				{
					p1.hp -= 10;
				}
				if(p2.left_kick_frame == 2 || p2.right_kick_frame == 3)
				{
					p1.hp -= 20;
				}
				if(p2.s_attack1_frame == 2)
				{
					p1.hp -= 20;
					if(p2.s_attack1_frame == 4)
					{
						p1.hp -= 20;
					}
				}
				if(p2.s_attack2_frame == 3)
				{
					p1.hp -= 30;
				}
				break;
			case 3:
				if(p2.left_fist_frame == 2 || p2.right_fist_frame == 2)
				{
					p1.hp -= 10;
				}
				if(p2.left_kick_frame == 2 || p2.right_kick_frame == 3)
				{
					p1.hp -= 20;
				}
				if(p2.s_attack1_frame == 2)
				{
					p1.hp -= 20;
					if(p2.s_attack1_frame == 6)
					{
						p1.hp -= 20;
					}
				}
			}
		}
	}
	if(ch_menu.choice == 3 || ch_menu.choice2 == 3)
	{
		if(ch_menu.choice == 3)
		{
			if((p1.offset + p1.char_w - 100) >= (p2.offset))
			{
				if(p1.s_attack2_frame == 7)
				{
					p2.hp -= 20;
				}
			}
		}
		if(ch_menu.choice2 == 3)
		{
			if((p1.offset + p1.char_w - 200) >= (p2.offset - p2.char_w))
			{
				if(p2.s_attack2_frame == 7)
				{
					p1.hp -= 20;
				}
			}
		}
	}
}

void Gameplay::set_name(Char_p1 &p1, Char_p2 &p2, Screen &scr, Chars_menu &ch_menu)
{
	p1.name_dest.x = 50;
	p1.name_dest.y = 200;

	p2.name_dest.x = 575;
	p2.name_dest.y = 200;

	switch(ch_menu.choice)
	{
	case 1:
		if(p1.name == NULL)
		{
			p1.name = IMG_Load("char1_name.png");
		}
		SDL_BlitSurface(p1.name, NULL, scr.screen, &p1.name_dest);
		break;
	case 2:
		if(p1.name == NULL)
		{
			p1.name = IMG_Load("char2_name.png");
		}
		SDL_BlitSurface(p1.name, NULL, scr.screen, &p1.name_dest);
		break;
	case 3:
		if(p1.name == NULL)
		{
			p1.name = IMG_Load("char3_name.png");
		}
		SDL_BlitSurface(p1.name, NULL, scr.screen, &p1.name_dest);
		break;
	}
	switch(ch_menu.choice2)
	{
		case 1:
		if(p2.name == NULL)
		{
			p2.name = IMG_Load("char1_name.png");
		}
		SDL_BlitSurface(p2.name, NULL, scr.screen, &p2.name_dest);
		break;
	case 2:
		if(p2.name == NULL)
		{
			p2.name = IMG_Load("char2_name.png");
		}
		SDL_BlitSurface(p2.name, NULL, scr.screen, &p2.name_dest);
		break;
	case 3:
		if(p2.name == NULL)
		{
			p2.name = IMG_Load("char3_name.png");
		}
		SDL_BlitSurface(p2.name, NULL, scr.screen, &p2.name_dest);
		break;
	}
}

void Gameplay::hp_bar(Char_p1 &p1, Char_p2 &p2, Screen &scr)
{
	if(p1.hp_bar == NULL)
	{
		p1.hp_bar = IMG_Load("hp_bar.png");
	}
	if (p2.hp_bar == NULL)
	{
		p2.hp_bar = IMG_Load("hp_bar.png");
	}

	p1.hp_bar_data.w = 400;
	p1.hp_bar_data.h = 20;
	p1.hp_bar_data.x = 0;
	p1.hp_bar_data.y = 0;

	p2.hp_bar_data.w = 400;
	p2.hp_bar_data.h = 20;
	p2.hp_bar_data.x = 0;
	p2.hp_bar_data.y = 0;

	p1.hp_bar_dest.x = 50;
	p1.hp_bar_dest.y = 150;

	p2.hp_bar_dest.x = 575;
	p2.hp_bar_dest.y = 150;

	if (p1.hp > 80)
	{
		SDL_BlitSurface(p1.hp_bar, &p1.hp_bar_data, scr.screen, &p1.hp_bar_dest);
	}
	else if ((p1.hp > 60) && (p1.hp <= 80))
	{
		p1.hp_bar_data.y = 20;
		SDL_BlitSurface(p1.hp_bar, &p1.hp_bar_data, scr.screen, &p1.hp_bar_dest);
	}
	else if ((p1.hp > 40) && (p1.hp <=60))
	{
		p1.hp_bar_data.y = 40;
		SDL_BlitSurface(p1.hp_bar, &p1.hp_bar_data, scr.screen, &p1.hp_bar_dest);
	}
	else if ((p1.hp > 20) && (p1.hp <= 40))
	{
		p1.hp_bar_data.y = 60;
		SDL_BlitSurface(p1.hp_bar, &p1.hp_bar_data, scr.screen, &p1.hp_bar_dest);
	}
	else if ((p1.hp > 0) && (p1.hp <= 20 ))
	{
		p1.hp_bar_data.y = 80;
		SDL_BlitSurface(p1.hp_bar, &p1.hp_bar_data, scr.screen, &p1.hp_bar_dest);
	}
	else if (p1.hp <= 0)
	{
		p1.hp_bar_data.y = 100;
		SDL_BlitSurface(p1.hp_bar, &p1.hp_bar_data, scr.screen, &p1.hp_bar_dest);
	}
	//--
	if (p2.hp > 80)
	{
		SDL_BlitSurface(p2.hp_bar, &p2.hp_bar_data, scr.screen, &p2.hp_bar_dest);
	}
	else if ((p2.hp > 60) && (p2.hp <= 80))
	{
		p2.hp_bar_data.y = 20;
		SDL_BlitSurface(p2.hp_bar, &p2.hp_bar_data, scr.screen, &p2.hp_bar_dest);
	}
	else if ((p2.hp > 40) && (p2.hp <=60))
	{
		p2.hp_bar_data.y = 40;
		SDL_BlitSurface(p2.hp_bar, &p2.hp_bar_data, scr.screen, &p2.hp_bar_dest);
	}
	else if ((p2.hp > 20) && (p2.hp <= 40))
	{
		p2.hp_bar_data.y = 60;
		SDL_BlitSurface(p2.hp_bar, &p2.hp_bar_data, scr.screen, &p2.hp_bar_dest);
	}
	else if ((p2.hp > 0) && (p2.hp <= 20 ))
	{
		p2.hp_bar_data.y = 80;
		SDL_BlitSurface(p2.hp_bar, &p2.hp_bar_data, scr.screen, &p2.hp_bar_dest);
	}
	else if (p2.hp <= 0)
	{
		p2.hp_bar_data.y = 100;
		SDL_BlitSurface(p2.hp_bar, &p2.hp_bar_data, scr.screen, &p2.hp_bar_dest);
	}

}



void Gameplay::check_winner(Char_p1 & p1, Char_p2 &p2, Screen &scr)
{
	p1.win_dest.x = 352;
	p1.win_dest.y = 300;

	p2.win_dest.x = p1.win_dest.x;
	p2.win_dest.y = p2.win_dest.y;
	if(p1.hp <= 0)
	{
		p1.fail = true;
		if(p1.fail)
		{
			p2.victory = true;
			p2.win = IMG_Load("char2_win.png");
			SDL_BlitSurface(p2.win, NULL, scr.screen, &p2.win_dest);
		}
	}
	if (p2.hp <= 0)
	{
		p2.fail = true;
		if(p2.fail)
		{
			p1.victory = true;
			p1.win = IMG_Load("char1_win.png");
			SDL_BlitSurface(p1.win, NULL, scr.screen, &p2.win_dest);
		}
	}
}
