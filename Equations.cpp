#include "Equations.h"

//square root equation
float Equations::Sqrt(Coordinate* A, Coordinate* B)
{

	return sqrt((B->Get_X() - A->Get_X()) * (B->Get_X() - A->Get_X()) + (B->Get_Y() - A->Get_Y()) * (B->Get_Y() - A->Get_Y()));
}
