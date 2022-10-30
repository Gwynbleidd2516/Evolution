#include "Wall.h"
#define FONT_PATH "res\\Time-Roman-Normal-Font.ttf"

Wall::Wall(Color color)
{
	this->color = color;
	font.loadFromFile(FONT_PATH);
	text.setFont(font);
	text.setString(" ");
}

Color Wall::getColor()
{
	return color;
}

Object Wall::getObject()
{
	return object;
}
