#pragma once
#include "Components.h"
#include "Game.h"


class RigidBody :	public Component
{
private:

	//Velocity of the character
	int Velocity;

	Coordinate Speed;

	//Last Position
	Coordinate Revert;



public:

	RigidBody();

	void SetVelocity(int Inp_Velocity) { Velocity = Inp_Velocity; };

	///Move
	void Up() { Speed.Set_Y(-1); };
	void Down() { Speed.Set_Y(1); };
	void Left() { Speed.Set_X(-1); };
	void Right() { Speed.Set_X(1); };
		
	///reset velocity
	void ResetXSpeed() { Speed.Set_X(0); };
	void ResetYSpeed() { Speed.Set_Y(0); };

	void update();

	///Revet Position
	void RevertPos();
	void RevertPos_X();
	void RevertPos_Y();

	void Rotate();
};

