#include "Coordinate.h"

Coordinate::Coordinate()
{
	X = 0;
	Y = 0;
}

Coordinate::Coordinate(Coordinate* Inp_Coordinate)
{
	X = Inp_Coordinate->Get_X();
	Y = Inp_Coordinate->Get_Y();
}

void Coordinate::Add(Coordinate *Inp_Coordinate)
{
	X += Inp_Coordinate->Get_X();
	Y += Inp_Coordinate->Get_Y();
}

void Coordinate::Set(Coordinate *Inp_Coordinate)
{
	X = Inp_Coordinate->Get_X();
	Y = Inp_Coordinate->Get_Y();
}
