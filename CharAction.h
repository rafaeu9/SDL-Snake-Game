#pragma once
#include "Game.h"
 


class CharAction :
	public Component
{
private:

	//Max range
	int range = 10;

	//Range Area
	SDL_Rect AttackRange;

public:

	void update();
	
	void draw();
	
	void Action();
};

