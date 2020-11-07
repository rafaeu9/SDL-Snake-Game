#pragma once

#include "Game.h"
#include <vector>

using namespace std;

class CollisionManager
{
private:



public:	

	//Entitys with colliders
	vector<unique_ptr<Entity>> Colliders;

	static bool Detect(const SDL_Rect& Rect_A, const SDL_Rect& Rect_B);

	static bool Detect_X(const SDL_Rect& Rect_A, const SDL_Rect& Rect_B);

	static bool Detect_Y(const SDL_Rect& Rect_A, const SDL_Rect& Rect_B);

	void update();
	
	void Add(Entity* ent);

	void WindowLimits(int w, int h);
};

