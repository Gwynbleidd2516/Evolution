#include "Poison.h"

Poison::Poison(Color color)
{
	this->color = color;
}

Color Poison::getColor()
{
	return color;
}

Object Poison::getObject()
{
	return object;
}
