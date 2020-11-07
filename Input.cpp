#include "Input.h"

//Define inputs
Input::Input(SDL_Keycode Up, SDL_Keycode Down, SDL_Keycode Left, SDL_Keycode Right, SDL_Keycode Action)
{
	KEY_Up = Up;
	KEY_Down = Down;
	KEY_Left = Left;
	KEY_Right = Right;
	KEY_Action = Action;
}

void Input::update()
{
			
		//defeine inputs
		if (Game::event->type == SDL_KEYDOWN) {

			SDL_Keycode keyPressed = Game::event->key.keysym.sym;

			if (KEY_Up == keyPressed)
			{
				entity->getComponent<RigidBody>().Up();
			}
			else if (KEY_Down == keyPressed)
			{
				entity->getComponent<RigidBody>().Down();
			}
			if (KEY_Left == keyPressed)
			{
				entity->getComponent<RigidBody>().Left();
			}
			else if (KEY_Right == keyPressed)
			{
				entity->getComponent<RigidBody>().Right();
			}

			if(KEY_Action == keyPressed)
			{
				entity->getComponent<CharAction>().Action();
			}
				
		}//Reset inputs
		else if (Game::event->type == SDL_KEYUP)
		{
			SDL_Keycode keyPressed = Game::event->key.keysym.sym;
			if (KEY_Up == keyPressed || KEY_Down == keyPressed)
			{
				entity->getComponent<RigidBody>().ResetYSpeed();
			}

			if (KEY_Left == keyPressed || KEY_Right == keyPressed)
			{
				entity->getComponent<RigidBody>().ResetXSpeed();
			}
		}
}
