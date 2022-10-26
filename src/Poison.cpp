#include "Poison.h"

Poison::Poison(Color color, int poison)
{
	this->color = color;
	this->poison=poison;
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

int Poison::getPoison()
{
	return poison;
}