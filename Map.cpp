#include "Map.h"




// Map structure
int lvl1[20][25] = {

	{ 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 }

};



Map::Map()
{
	//Difrent tips of tiles
	dirt = TextureManager::LoadBMPTexture("assets/dirt.bmp");
	grass = TextureManager::LoadBMPTexture("assets/grass.bmp");
	water = TextureManager::LoadBMPTexture("assets/water.bmp");

	//Load map Structure
	LoadMap(lvl1);

	//Define size of the tile
	src.x = src.y = 0;
	dest.x = dest.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;

	//Define Map colision
	Tile type;
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			type = Tile(map[row][column]);

			dest.x = column * 32;
			dest.y = row * 32;

			switch (type)
			{
			case waterT:
				way.push_back(dest);
				break;
			case dirtT:
				way.push_back(dest);
				break;
			default:
				break;
			}
		}
	}

	//Define Map Borders
	MapLimits.x = 1 * 32;
	MapLimits.y = 1 * 32;
	MapLimits.w = 25 * 32 + 32;
	MapLimits.h = 17 * 32 + 32;
}

//Load Map
void Map::LoadMap(int arr[20][25])
{
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column ++)
		{
			map[row][column] = arr[row][column];
		}
	}


}

void Map::DrawMap()
{
	//Draw Map Tile By Tile
	Tile type;
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			type = Tile (map[row][column]);

			dest.x = column * 32;
			dest.y = row * 32;

			switch (type)
			{
			case waterT:
				TextureManager::Draw(water, dest);				
				break;				
			case grassT:
				TextureManager::Draw(grass, dest);				
				break;
			case dirtT:
				TextureManager::Draw(dirt, dest);				
				break;
			default:
				break;
			}
		}
	}
}

void Map::update()
{
	//Detect if ther is any Colision inside the map
	for (auto& i : way)	
		for (auto& e : Game::collisionManger->Colliders)
			if (e->hasComponent<RigidBody>())
			{
				if (CollisionManager::Detect(e->getComponent<Collision>().Rect, i))
				{
					e->getComponent<RigidBody>().RevertPos();
					break;
				}
			}		
	//Detect if ther is any Colision on the borders
	for (auto& i : Game::collisionManger->Colliders) if (i->hasComponent<RigidBody>())
	{
		if (!CollisionManager::Detect(i->getComponent<Collision>().Rect, MapLimits))
			i->getComponent<RigidBody>().RevertPos();
	}
}
