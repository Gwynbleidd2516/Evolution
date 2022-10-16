#include "Creatures.h"

Creature::Creature(Color color, bool brand)
{
	int number;
	this->color = color;

	if(brand) srand(time(0));

	for(int i=0;i<48;i++)
	{
		number=rand() % 17;
		comands.push_back(number);
	}

	font.loadFromFile("res\\Time-Roman-Normal-Font.ttf");
	Text txt(to_string(life),font);
	text=txt;
}

Creature::Creature()
{
	
}

void Creature::setCreature(Color color, bool brand)
{
	int number;
	this->color = color;
	if(brand) srand(time(0));
	for(int i=0;i<48;i++){
		number=rand() % 17;
		comands.push_back(number);
	}
	font.loadFromFile("res\\Time-Roman-Normal-Font.ttf");
	Text txt(to_string(life),font);
	text=txt;
	text.setScale(0.5,0.5);
}

Color Creature::getColor()
{
	return color;
}

Object Creature::getObject()
{
	return object;
}

void Creature::setLife(int life)
{
	text.setString(to_string(life));
}

Text Creature::getText()
{
	return text;
}

void Creature::setCordinats(Vector2i vector)
{
	position=vector;
}

void Creature::setCordinats(int x, int y)
{
	position.x=x;
	position.y=y;
}

Vector2i Creature::getCordinats()
{
	return position;
}

void Creature::setDirection(Direction direction)
{
	this->direction = direction;
}

Direction Creature::getDirection()
{
	return direction;
}