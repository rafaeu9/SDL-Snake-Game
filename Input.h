#pragma once
#include "Components.h"

class Input :
	public Component
{
public:
	Input(SDL_Keycode Up, SDL_Keycode Down, SDL_Keycode Left, SDL_Keycode Right, SDL_Keycode Action);
		

	void update();

private:		

	SDL_Keycode KEY_Up;
	SDL_Keycode KEY_Down;
	SDL_Keycode KEY_Left;
	SDL_Keycode KEY_Right;
	SDL_Keycode KEY_Action;

};

