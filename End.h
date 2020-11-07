#pragma once
#include "Game.h"

class End :
	public Component
{
private:
	SDL_Rect FinalArea;
	Body* Snake;
public:

	End(Body* InpSnake) { Snake = InpSnake; };

	bool EndGame = false;

	void init();
	void update();
};

