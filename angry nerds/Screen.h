#pragma once
#include <SDL.h>

class Screen
{
protected:
	bool quit;
	int screen_w;
	int screen_h;
	int screen_bbp;
	int fps;
public:
	SDL_Surface * screen;
	SDL_Surface * background;
	SDL_Event screen_event;
	Screen();
	Screen(int screen_w_, int screen_h_, int screen_bbp_, int fps_);
	//~Screen();
	bool init();
	bool qet_quit(){ return quit;};
	int get_screen_w(){ return screen_w;};
	int get_screen_h(){ return screen_h;};
	int get_Screen_bbp(){ return screen_bbp;};
	int get_screen_fps(){ return fps;};
	void set_quit();
	void reset_quit();
};