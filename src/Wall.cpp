#include "Wall.h"

Wall::Wall(Color color)
{
	this->color = color;
}

Color Wall::getColor()
{
	return color;
}

Object Wall::getObject()
{
	return object;
}
