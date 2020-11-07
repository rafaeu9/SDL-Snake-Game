#include "Game.h"

Map* map;
Manager manager;
Body* snake = nullptr;


SDL_Renderer* Game::renderer = nullptr;
SDL_Event* Game::event = nullptr;
CollisionManager* Game::collisionManger = nullptr;
vector<Entity*> Game::enemys;

///Create Entitys
Entity& Goal(manager.addEntity());
Entity& Player1(manager.addEntity());
Entity& Player2(manager.addEntity());
Entity& Coin(manager.addEntity());


Game::Game()
{
	window = nullptr;
}

Game::~Game()
{
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{	
	
#pragma region Create Window
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//Check if SDL is inicialized
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{

		//create the window
		window = SDL_CreateWindow(
			title,				//title
			xpos,				//initial x position
			ypos,				//initial y position
			width,				//width, in pixels
			height,				//height, in pixels
			flags				//window behaviour flags (ignorw for now)
		);

		if (!window)
		{
			printf("WINDOW initialisation failed: %s\n", SDL_GetError());
			printf("Press any key to continued\n");
			getchar();
			return;
		}

		renderer = SDL_CreateRenderer(
			window,				//link the renderer to our newly created win
			-1,					//index rendering driver (ignore for now)
			0					//renderer behaviour flags (ignore for now)
		);

		if (!renderer)
		{
			printf("RENDERER initialisation failed: %s\n", SDL_GetError());
			printf("Press any key to continued\n");
			getchar();
			return;
		}

		if (renderer)
		{
			SDL_SetRenderDrawColor(
				renderer,		//our target renderer
				255,			//r
				255,			//g
				255,			//b
				255				//alpha
			);
		}


		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
#pragma endregion Create Window

	
	Game::event = new SDL_Event();

	map = new Map();
	
	Game::collisionManger = new CollisionManager();
		
#pragma region Create Players

	Player1.addComponent<Coordinate>(200, 550);	
	Player1.addComponent<Sprite>("assets/SnakeHead2.bmp", false);
	Player1.addComponent<RigidBody>();
	Player1.getComponent<RigidBody>().SetVelocity(2);
	Player1.addComponent<Input>(SDLK_w, SDLK_s, SDLK_a, SDLK_d, SDLK_SPACE);
	Player1.addComponent<Collision>("assets/SnakeHead2.bmp");
	Player1.addComponent<CharAction>();

	Player2.addComponent<Coordinate>(400, 550);	
	Player2.addComponent<Sprite>("assets/SnakeHead.bmp", false);
	Player2.addComponent<RigidBody>();
	Player2.getComponent<RigidBody>().SetVelocity(2);
	Player2.addComponent<Input>(SDLK_UP, SDLK_DOWN, SDLK_LEFT, SDLK_RIGHT, SDLK_m);
	Player2.addComponent<Collision>("assets/SnakeHead.bmp");
	Player2.addComponent<CharAction>();

	snake = new Body(&Player1, &Player2);

#pragma endregion Create Players

#pragma region Create Coin

	Coin.addComponent<Coordinate>(650,270);
	Coin.addComponent<Sprite>("assets/Coin.bmp");
	Coin.getComponent<Sprite>().destRect.h = 50;
	Coin.getComponent<Sprite>().destRect.w = 50;
	Coin.addComponent<Coins>(snake);

#pragma endregion Create Coin

#pragma region Create end

	Goal.addComponent<Coordinate>(128,0);
	Goal.addComponent<End>(snake);

#pragma endregion Create end
}

void Game::handleEvents()
{
	
	if (snake->Health <= 0 || Goal.getComponent<End>().EndGame)
		isRunning = false;
	else {

		SDL_PollEvent(Game::event);
		switch (Game::event->type)
		{
			//detect if the X of the window was pressed
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
		}
	}

}

void Game::update()
{
	
	//Update Entity manager
	manager.refresh();
	manager.update();

	//Update snake body
	snake->Update();	
	
	//Update Map
	map->update();	

	//Update Collision manager
	Game::collisionManger->update();
}

void Game::render()
{
	//Clean window
	SDL_RenderClear(renderer);
		
	//Redraw Map
	map->DrawMap();
  
	//Draw Entitys
	manager.draw();

	//Draw snake body
	snake->draw();

	//Draw on screen
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	printf("GameClean\n");
}

//Creat Enemys
void Game::SumonEnemys(int X, int Y)
{
	Entity& Enemy(manager.addEntity());

	Enemy.addComponent<Coordinate>(X, Y);
	Enemy.addComponent<Sprite>("assets/Bird.bmp", false);
	Enemy.getComponent<Sprite>().destRect.w = 50;
	Enemy.getComponent<Sprite>().destRect.h = 60;
	Enemy.addComponent<RigidBody>();
	Enemy.addComponent<EnemyAI>(snake);


	enemys.push_back(&Enemy);
}


