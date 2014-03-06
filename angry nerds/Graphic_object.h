#pragma once
#include <SDL_image.h>
#include <string>
#include "Screen.h"

using namespace std;

class Graphic_object: public Screen
{

public:
	static SDL_Surface * load_image(string filename);
	static void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);
};

