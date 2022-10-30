#include "Voidness.h"
#define FONT_PATH "res\\Time-Roman-Normal-Font.ttf"

Voidness::Voidness(Color color)
{
	this->color = color;
	font.loadFromFile(FONT_PATH);
	text.setFont(font);
	text.setString(" ");
}

Color Voidness::getColor()
{
	return color;
}

Object Voidness::getObject()
{
	return object;
}
