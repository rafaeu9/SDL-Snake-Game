#pragma once
#include "Game.h"

class Collision :
	public Component
{
private:
	Coordinate* pos;

public:

	SDL_Rect Rect;

	Collision(int Inp_h, int Inp_w);

	Collision(const char* path);

	void init();
	void update();
	void draw();

	void Square();
};

