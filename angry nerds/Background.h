#pragma once
#include "Graphic_object.h"

class Background: public Graphic_object
{
public:
	static void set_background(Screen &scr, string filename);
};

