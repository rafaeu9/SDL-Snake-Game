#include "CharAction.h"

void CharAction::update()
{
	///Update Range Area
	AttackRange.x = entity->getComponent<Collision>().Rect.x - range;
	AttackRange.y = entity->getComponent<Collision>().Rect.y - range;
	AttackRange.w = entity->getComponent<Collision>().Rect.w + range * 2;
	AttackRange.h = entity->getComponent<Collision>().Rect.h + range * 2;
}


void CharAction::draw()
{
	///Draw Range
	/*SDL_RenderDrawRect(Game::renderer, &AttackRange);*/
}


void CharAction::Action()
{
	///Detect if thers enemy close
	cout << "Action" << endl;
	for (auto& e : Game::enemys)
		if (e->hasComponent<EnemyAI>() && CollisionManager::Detect(AttackRange, e->getComponent<Sprite>().destRect))
		{
			///Kill the Enemy
			cout << "attack" << endl;
			e->getComponent<EnemyAI>().Damage();
		}
		
}
