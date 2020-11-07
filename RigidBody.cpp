#include "RigidBody.h"

RigidBody::RigidBody()
{
	Velocity = 1;
}

void RigidBody::update()
{	
	//Save Last Position
	Revert.Set(entity->getComponent<Coordinate>().Get_X(), entity->getComponent<Coordinate>().Get_Y());

	//Apply Movement
	entity->getComponent<Coordinate>().Add_X(Speed.Get_X() * Velocity);
	entity->getComponent<Coordinate>().Add_Y(Speed.Get_Y() * Velocity);

}

//Reset X and Y
void RigidBody::RevertPos()
{	
	entity->getComponent<Coordinate>().Set(Revert.Get_X(), Revert.Get_Y());
}

//Reset X
void RigidBody::RevertPos_X()
{

	entity->getComponent<Coordinate>().Set_X(Revert.Get_X());
}

//Reset Y
void RigidBody::RevertPos_Y()
{
	entity->getComponent<Coordinate>().Set_Y(Revert.Get_Y());
}

void RigidBody::Rotate()
{
	
}


