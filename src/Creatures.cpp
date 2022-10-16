#include "Creatures.h"

Creature::Creature(Color color, bool brand)
{
	int number;
	this->color = color;

	if(brand) srand(time(0));

	for(int i=0;i<48;i++)
	{
		number=rand() % 24;
		comands.push_back(number);
	}

	font.loadFromFile("res\\Time-Roman-Normal-Font.ttf");
	text.setFont(font);
	text.setString(to_string(life));

	number=rand()%8;
	switch (number)
	{
	case 0:
		direction=Direction::DOWN;
		break;
	case 1:
		direction=Direction::DOWN_LEFT;
		break;
	case 2:
		direction=Direction::DOWN_RIGHT;
		break;
	case 3:
		direction=Direction::LEFT;
		break;
	case 4:
		direction=Direction::LEFT_UP;
		break;
	case 5:
		direction=Direction::RIGHT;
		break;
	case 6:
		direction=Direction::RIGHT_UP;
		break;
	case 7:
		direction=Direction::UP;
		break;
	default:
		break;
	}
}

Creature::Creature()
{
	
}

void Creature::setCreature(Color color, bool brand)
{
	int number;
	this->color = color;
	if(brand) srand(time(0));

	for(int i=0;i<48;i++)
	{
		number=rand() % 24;
		comands.push_back(number);
	}

	font.loadFromFile("res\\Time-Roman-Normal-Font.ttf");
	text.setFont(font);
	text.setString(to_string(life));

	number=rand()%8;
	switch (number)
	{
	case 0:
		direction=Direction::DOWN;
		break;
	case 1:
		direction=Direction::DOWN_LEFT;
		break;
	case 2:
		direction=Direction::DOWN_RIGHT;
		break;
	case 3:
		direction=Direction::LEFT;
		break;
	case 4:
		direction=Direction::LEFT_UP;
		break;
	case 5:
		direction=Direction::RIGHT;
		break;
	case 6:
		direction=Direction::RIGHT_UP;
		break;
	case 7:
		direction=Direction::UP;
		break;
	default:
		break;
	}
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

void Creature::setRandomComands()
{
	srand(time(0));
	int number;
	for(int i=0;i<48;i++)
	{
		number=rand() % 24;
		comands[i]=number;
	}
}