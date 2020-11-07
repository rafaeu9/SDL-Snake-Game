#include "CollisionManager.h"


bool CollisionManager::Detect(const SDL_Rect& Rect_A, const SDL_Rect& Rect_B)
{
	//Check Collision
	if (Rect_A.x + Rect_A.w >= Rect_B.x &&
		Rect_B.x + Rect_B.w >= Rect_A.x &&
		Rect_A.y + Rect_A.h >= Rect_B.y &&
		Rect_B.y + Rect_B.h >= Rect_A.y)
	{
		return true;
	}
	else
	return false;
}

//Check Collision X
bool CollisionManager::Detect_X(const SDL_Rect& Rect_A, const SDL_Rect& Rect_B)
{
	if (Rect_A.x + Rect_A.w >= Rect_B.x &&
		Rect_B.x + Rect_B.w >= Rect_A.x )
	{
		return true;
	}
	else
		return false;
}

//Check Collision Y
bool CollisionManager::Detect_Y(const SDL_Rect& Rect_A, const SDL_Rect& Rect_B)
{
	if (Rect_A.y + Rect_A.h >= Rect_B.y &&
		Rect_B.y + Rect_B.h >= Rect_A.y)
	{
		return true;
	}
	else
		return false;
}



void CollisionManager::update()
{

	//Go through all entitys with colliders and conpare with all entitys with colliders
	for (auto& e : Colliders) for (auto& i : Colliders)
		if (i != e && e->hasComponent<RigidBody>() && Detect(e->getComponent<Collision>().Rect, i->getComponent<Collision>().Rect))
		{			
			e->getComponent<RigidBody>().RevertPos();
		
		}
}

//Add an entity with colider to the list
void CollisionManager::Add(Entity* ent)
{
	Colliders.emplace_back(move(ent));
}




