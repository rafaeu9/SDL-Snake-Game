#pragma once
#include "Game.h"

//#include "Body.h"

class Body;

class EnemyAI :
	public Component
{	
	
	//velocity of enemy
	int Velocity = 5;

	//Time Betwene attacks
	int CooldownDelay = 3;

	//Can attack or not
	bool Cooldown = true;

	//hold time
	Uint32 frameStart;

public:

	EnemyAI(Body* InSnake);

	void init();
	
	void update();

	void Attack();

	void Damage();

};

