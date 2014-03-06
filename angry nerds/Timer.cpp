#include "Timer.h"



Timer::Timer(int start_ticks_, int paused_ticks_)
{
	start_ticks = start_ticks_;
	paused_ticks = paused_ticks_;
	paused = false;
	started = false;
}

void Timer::start()
{
	started = true;
	paused = false;
	start_ticks = SDL_GetTicks();
}

void Timer::stop()
{
	started = false;
	paused = false;
}

void Timer::pause()
{
	if ((started == true) && (paused == false))
	{
		paused = true;
		paused_ticks = SDL_GetTicks() - start_ticks;
	}
}

void Timer::unpause()
{
	if (paused == true)
	{
		paused = false;
		start_ticks = SDL_GetTicks() - paused_ticks;
		paused_ticks = 0;
	}
}

int Timer::get_ticks()
{
	if (started == true)
	{
		if (paused == true)
		{
			return paused_ticks;
		}
		else
		{
			return SDL_GetTicks() - start_ticks;
		}
	}
	return 0;
}

bool Timer::is_paused()
{
	return paused;
}

bool Timer::is_started()
{
	return started;
}
