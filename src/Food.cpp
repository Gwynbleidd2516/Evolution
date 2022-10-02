#include "Food.h"

Food::Food(Color color)
{
	this->color = color;
}

Color Food::getColor()
{
	return color;
}

Object Food::getObject()
{
	return object;
}
