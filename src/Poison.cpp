#include "Poison.h"
#define FONT_PATH "res\\Time-Roman-Normal-Font.ttf"

Poison::Poison(Color color)
{
	this->color = color;
	font.loadFromFile(FONT_PATH);
	text.setFont(font);
	text.setString(" ");
}

Color Poison::getColor()
{
	return color;
}

Object Poison::getObject()
{
	return object;
}

Text Poison::getText()
{
	return text;
}