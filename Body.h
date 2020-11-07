#pragma once
#include "Game.h"

class Body
{
private:

	//Max Distance Betwen the players
	int BodyLengh = 200;

	//Velocity of the Players
	int Velocity = 2;

	//Max space betwene body points
	int SpaceMidNodes = 25;

public:

	Body(Entity* Snake1, Entity* Snake2);

	//Points in the body
	array<Coordinate,5> Nodes;
	
	Entity* Player1;
	Entity* Player2;

	void Update();
	void draw();

	void follow();

	//Players health 
	int Health = 3;

	void Damage() { --Health; };

	bool Coin = false;

};

