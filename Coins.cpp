#include "Coins.h"

Coins::Coins(Body* inpSnake)
{
	Snake = inpSnake;
}

void Coins::update()
{
	///Detect if any players Colected the coin
	if (CollisionManager::Detect(entity->getComponent<Sprite>().destRect, Snake->Player1->getComponent<Collision>().Rect) ||
		CollisionManager::Detect(entity->getComponent<Sprite>().destRect, Snake->Player2->getComponent<Collision>().Rect))
	{		
		///Destroy de Coin whene colected 
		entity->destroy();
		Snake->Coin = true;

		///Sumon the Enemys
		Game::SumonEnemys(200, 200);
		Game::SumonEnemys(200, 300);
	}
}
