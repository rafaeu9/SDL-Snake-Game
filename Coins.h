#pragma once
#include "Game.h"
class Coins :
	public Component
{
private:
	Body* Snake;

public:
	Coins(Body* inpSnake);

	void update();

};

