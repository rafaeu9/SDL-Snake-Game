#pragma once
#include "Game.h" 
#include "TextureManager.h"
#include <vector>



class Map
{
public:

	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();

	void update();

	std::vector<SDL_Rect> way;


private:

	SDL_Rect src, dest, MapLimits;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];

	enum Tile
	{
		waterT, grassT, dirtT
	};

};

