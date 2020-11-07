#pragma once
#include "ECS.h"

class Coordinate : public Component
{
private:
	int X;
	int Y;

	   
public:

	Coordinate();
	Coordinate(int Inp_X, int Inp_Y) { X = Inp_X; Y = Inp_Y; };
	Coordinate(Coordinate* Inp_Coordinate);


	void Add(Coordinate* Inp_Coordinate);
	void Add(int Inp_X, int Inp_Y) { X += Inp_X; Y += Inp_Y; };
	void Add_X(int Inp_X) { X += Inp_X; };
	void Add_Y(int Inp_Y) { Y += Inp_Y; };

	void Set(Coordinate *Inp_Coordinate);
	void Set(int Inp_X, int Inp_Y) { X = Inp_X; Y = Inp_Y; };
	void Set_X(int Inp_X) { X = Inp_X; };
	void Set_Y(int Inp_Y) { Y = Inp_Y; };

	int Get() { return X,Y; };
	int Get_X() { return X; };
	int Get_Y() { return Y; };
};

