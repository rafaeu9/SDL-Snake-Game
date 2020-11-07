#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include "SDL.h"
#include "TextureManager.h"
#include "Map.h"
#include "Components.h"
#include "Equations.h"
#include "CollisionManager.h"





struct SDL_Surface;
struct SDL_Texture;
struct SDL_Renderer;
class CollisionManager;

using namespace std;

class Game
{
public:

	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();	
	void render();
	void clean();

	static void SumonEnemys(int X, int Y);

	bool running() { return isRunning; };

	

	static SDL_Renderer* renderer;
	static SDL_Event* event;	
	static CollisionManager* collisionManger;

	static vector<Entity*> enemys;



private:

	bool isRunning;
	SDL_Window* window;

};









