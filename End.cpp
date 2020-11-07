#include "End.h"

void End::init()
{
	FinalArea.x = entity->getComponent<Coordinate>().Get_X();
	FinalArea.y = entity->getComponent<Coordinate>().Get_Y();
	FinalArea.h = 32;
	FinalArea.w = 64;
}

void End::update()
{
	//Detect if can end
	for (auto& i : Game::collisionManger->Colliders)
		if (i->hasComponent<RigidBody>() && CollisionManager::Detect(i->getComponent<Collision>().Rect, FinalArea) && Snake->Coin)
			EndGame = true;
}
