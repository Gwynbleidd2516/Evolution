#include "Food.h"

Food::Food(Color color, int food)
{
	this->color = color;
	this->food=food;
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

int Food::getFood()
{
	return food;
}