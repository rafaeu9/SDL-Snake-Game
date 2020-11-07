#include "Body.h"

Body::Body(Entity* Snake1, Entity* Snake2)
{
	Player1 = Snake1;
	Player2 = Snake2;

	for (size_t i = 0; i < Nodes.size(); i++)
	{
		Nodes[i] = new Coordinate(Snake1->getComponent<Coordinate>().Get_X(), Snake1->getComponent<Coordinate>().Get_Y() + 10);
	}
	
}

void Body::Update()
{
	//Dont let player go to far from each other
	if (Equations::Sqrt(&Player1->getComponent<Coordinate>(), &Player2->getComponent<Coordinate>())> BodyLengh)
	{
		Player1->getComponent<RigidBody>().RevertPos();
		Player2->getComponent<RigidBody>().RevertPos();
	}

	follow();
}

void Body::draw()
{
	//Draw Lines Betwen the Nodes
	for (size_t i = 1; i < Nodes.size(); i++)
	{
		SDL_RenderDrawLine(Game::renderer,
			Nodes[i-1].Get_X(), Nodes[i - 1].Get_Y(),
			Nodes[i].Get_X(), Nodes[i].Get_Y());
	}
	
}

void Body::follow()
{
	//Set First and Last node to the playes position
	Nodes[0].Set(Player1->getComponent<Coordinate>().Get_X() + Player1->getComponent<Sprite>().destRect.w / 2,
				 Player1->getComponent<Coordinate>().Get_Y() + Player1->getComponent<Sprite>().destRect.h);

	Nodes.back().Set(Player2->getComponent<Coordinate>().Get_X() + Player2->getComponent<Sprite>().destRect.w / 2,
					 Player2->getComponent<Coordinate>().Get_Y() + Player2->getComponent<Sprite>().destRect.h);
	
	//Update nodes position starting from the first player
	for (size_t i = 1; i < (Nodes.size() - 1); i++)
	{
		if (abs(Equations::Sqrt(&Nodes[i], &Nodes[i-1])) > SpaceMidNodes)
		{
		
			if (Nodes[i-1].Get_X() > Nodes[i].Get_X())
				Nodes[i].Add_X(1 * Velocity);
			else if (Nodes[i - 1].Get_X() < Nodes[i].Get_X())
				Nodes[i].Add_X(-1 * Velocity);
			else
				Nodes[i].Add_X(0);

			if (Nodes[i - 1].Get_Y() > Nodes[i].Get_Y())
				Nodes[i].Add_Y(1 * Velocity);
			else if (Nodes[i - 1].Get_Y() < Nodes[i].Get_Y())
				Nodes[i].Add_Y(-1 * Velocity);
			else
				Nodes[i].Add_Y(0);
		}

	}

	//Update nodes position starting from the last player
	for (size_t i = Nodes.size() - 1; i > (1); i--)
	{
		if (abs(Equations::Sqrt(&Nodes[i], &Nodes[i + 1])) > SpaceMidNodes)
		{

			if (Nodes[i + 1].Get_X() > Nodes[i].Get_X())
				Nodes[i].Add_X(1 * Velocity);
			else if (Nodes[i + 1].Get_X() < Nodes[i].Get_X())
				Nodes[i].Add_X(-1 * Velocity);
			else
				Nodes[i].Add_X(0);

			if (Nodes[i + 1].Get_Y() > Nodes[i].Get_Y())
				Nodes[i].Add_Y(1 * Velocity);
			else if (Nodes[i + 1].Get_Y() < Nodes[i].Get_Y())
				Nodes[i].Add_Y(-1 * Velocity);
			else
				Nodes[i].Add_Y(0);
		}

	}
}
