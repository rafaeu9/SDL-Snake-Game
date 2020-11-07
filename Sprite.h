#pragma once
#include "TextureManager.h"
#include "Components.h"
#include "SDL.h"


class Sprite :	public Component
{
private:
	
	Coordinate* position;
	   
	SDL_Texture* Texture;	

public:

	SDL_Rect srcRect, destRect;
	

	Sprite();
	Sprite(const char* path, bool useTransparency = false);

	void setTex(const char* path, bool useTransparency = false);

	void init();

	void update();

	void draw();

	void rotation();

};
