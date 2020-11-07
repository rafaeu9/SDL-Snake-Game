#include <iostream>
#include "Game.h"

#undef main

Game* game = nullptr;

int main(int argc, char arg[])
{

	//Target Frame rate
	const int FPS = 60;
	//Max time between frames
	const int frameDelay = 1000 / FPS;

	int FrameCount = 0;
	Uint32 CountSec = 0;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("The mysterious Big Forest", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (game->running())
	{
		//Current game time
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();
		
		//How long the cicle took
		frameTime = SDL_GetTicks() - frameStart;

		//check if need to Delay
		if (frameDelay > frameTime)
		{
			//How mush time will delay
			SDL_Delay(frameDelay - frameTime);
		}

		//Add frame count
		FrameCount++;

		//Detect how much time take to update game
		frameTime = SDL_GetTicks() - frameStart;

		//Store time
		CountSec += frameTime;

		//if pass 1 second display frame rate
		if (CountSec >= 1000)
		{
			CountSec = 0;			
			
			std::cout << FrameCount << " FPS" << endl;

			FrameCount = 0;
		}
	}

	game->clean();

	return 0;
}