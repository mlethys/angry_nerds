#pragma once
#include <SDL.h>

class Timer
{
private: 
	int start_ticks;
	int paused_ticks;
	bool paused;
	bool started;

public:
	Timer();
	Timer(int start_ticks_, int paused_ticks_);
	void start();
	void stop();
	void pause();
	void unpause();
	int get_ticks();
	bool is_started();
	bool is_paused();
};