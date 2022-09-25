#include "Creatures.h"

Creature::Creature(Color color)
{
	this->color = color;
}

Color Creature::getColor()
{
	return color;
}
