#include "Food.h"
#define FONT_PATH "res\\Time-Roman-Normal-Font.ttf"

Food::Food(Color color)
{
	this->color = color;
	font.loadFromFile(FONT_PATH);
	text.setFont(font);
	text.setString(" ");
}

Color Food::getColor()
{
	return color;
}

Object Food::getObject()
{
	return object;
}

Text Food::getText()
{
	return text;
}