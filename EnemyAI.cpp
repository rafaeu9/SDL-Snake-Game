#include "EnemyAI.h"

Body* Snake;


EnemyAI::EnemyAI(Body* InSnake)
{
	Snake = InSnake;
}

void EnemyAI::init()
{
}

void EnemyAI::update()
{
	//Detect the closest player
	if (Equations::Sqrt(&Snake->Player1->getComponent<Coordinate>(), &entity->getComponent<Coordinate>())		
		<
		Equations::Sqrt(&Snake->Player2->getComponent<Coordinate>(), &entity->getComponent<Coordinate>()))
	{
		//Go to the Player1
		if (Snake->Player1->getComponent<Coordinate>().Get_X() > entity->getComponent<Coordinate>().Get_X())
			entity->getComponent<RigidBody>().Right();
		else if (Snake->Player1->getComponent<Coordinate>().Get_X() < entity->getComponent<Coordinate>().Get_X())
			entity->getComponent<RigidBody>().Left();
		else
			entity->getComponent<RigidBody>().RevertPos_X();

		if (Snake->Player1->getComponent<Coordinate>().Get_Y() > entity->getComponent<Coordinate>().Get_Y())
			entity->getComponent<RigidBody>().Down();
		else if (Snake->Player1->getComponent<Coordinate>().Get_Y() < entity->getComponent<Coordinate>().Get_Y())
			entity->getComponent<RigidBody>().Up();
		else
			entity->getComponent<RigidBody>().RevertPos_Y();

		//Attack him
		if (CollisionManager::Detect(entity->getComponent<Sprite>().destRect, Snake->Player1->getComponent<Collision>().Rect))
		{
			Attack();
		}
	}
	else
	{
		//Go to the Player2
		if (Snake->Player2->getComponent<Coordinate>().Get_X() > entity->getComponent<Coordinate>().Get_X())
			entity->getComponent<RigidBody>().Right();
		else if (Snake->Player2->getComponent<Coordinate>().Get_X() < entity->getComponent<Coordinate>().Get_X())
			entity->getComponent<RigidBody>().Left();
		else
			entity->getComponent<RigidBody>().RevertPos_X();

		if (Snake->Player2->getComponent<Coordinate>().Get_Y() > entity->getComponent<Coordinate>().Get_Y())
			entity->getComponent<RigidBody>().Down();
		else if (Snake->Player2->getComponent<Coordinate>().Get_Y() < entity->getComponent<Coordinate>().Get_Y())
			entity->getComponent<RigidBody>().Up();
		else
			entity->getComponent<RigidBody>().RevertPos_Y();

		//Attack him
		if (CollisionManager::Detect(entity->getComponent<Sprite>().destRect, Snake->Player2->getComponent<Collision>().Rect))
		{
			Attack();
		}
	}		
		
	///Detect if can attack again
	if (!Cooldown)
	{
		if ((SDL_GetTicks() - frameStart) >= (CooldownDelay * 1000))
			Cooldown = true;		
	}
}

void EnemyAI::Attack()
{
	///Start Cooldown timer after enemy attack
	if (Cooldown)
	{
		Cooldown = false;		

		Snake->Damage();

		frameStart = SDL_GetTicks();
	}
}

///Take Damage
void EnemyAI::Damage()
{
	entity->destroy();
}



