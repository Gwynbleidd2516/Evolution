#include "Creatures.h"

Creature::Creature(Color color)
{
	this->color = color;
}

Color Creature::getColor()
{
	return color;
}

Object Creature::getObject()
{
	return object;
}
