#include "Creatures.h"

Creature::Creature(Color color, int life, bool brand)
{
	this->life=life;
	lifeNow=life;
	int number;
	this->color = color;

	if(brand) srand(time(0));

	for(int i = 0; i < 48; i++)
	{
		number=rand() % comands_capacity;
		comands.push_back(number);
	}

	font.loadFromFile(FONT_PATH);
	text.setFont(font);
	text.setString(to_string(lifeNow));

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

Creature::Creature(int life, bool brand)
{
	this->life=life;
	lifeNow=life;
	int number;

	if(brand) srand(time(0));

	int r=rand()%256;
	int g=rand()%256;
	int b=rand()%256;

	color=Color(r,g,b,0);

	for(int i = 0; i < 48; i++)
	{
		number=rand() % comands_capacity;
		comands.push_back(number);
	}

	font.loadFromFile(FONT_PATH);
	text.setFont(font);
	text.setString(to_string(lifeNow));

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

void Creature::setCreature(Color color, int life, bool brand)
{
	this->life=life;
	lifeNow=life;
	int number;
	this->color = color;
	if(brand) srand(time(0));

	for(int i=0;i<48;i++)
	{
		number=rand() % comands_capacity;
		comands.push_back(number);
	}

	font.loadFromFile(FONT_PATH);
	text.setFont(font);
	text.setString(to_string(lifeNow));

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

void Creature::setCreature(int life, bool brand)
{
	this->life=life;
	lifeNow=life;
	int number;

	if(brand) srand(time(0));

	int r=rand()%256;
	int g=rand()%256;
	int b=rand()%256;
	int a=rand()%256;

	color=Color(r,g,b,a);

	for(int i = 0; i < 48; i++)
	{
		number=rand() % comands_capacity;
		comands.push_back(number);
	}

	font.loadFromFile(FONT_PATH);
	text.setFont(font);
	text.setString(to_string(lifeNow));

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
	lifeNow=life;
	if(lifeNow<=0) dead = true;
	else dead=false;
	text.setString(to_string(lifeNow));
}

int Creature::getLife()
{
	if(lifeNow<0) 
	{
		dead = true;
		lifeNow=0;
	}
	else dead=false;

	if(lifeNow>lifeLimit)
	{
		lifeNow=lifeLimit;
	}

	return lifeNow;
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
		number=rand() % comands_capacity;
		comands[i]=number;
	}
}

void Creature::operator++()
{
	lifeNow++;
	if(lifeNow<0) dead = true;
	else dead=false;
	text.setString(to_string(lifeNow));
}

void Creature::operator--()
{
	lifeNow--;
	if(lifeNow<0) dead = true;
	else dead=false;
	text.setString(to_string(lifeNow));
}

void Creature::operator+=(int value)
{
	lifeNow+=value;
	if(lifeNow<=0) dead = true;
	else dead=false;
	text.setString(to_string(lifeNow));
}

void Creature::operator-=(int value)
{
	if(lifeNow-value>0) lifeNow-=value;
	else lifeNow=0;
	text.setString(to_string(lifeNow));
	
}

bool Creature::isDead()
{
	if(lifeNow<0) dead = true;
	else dead=false;
	return dead;
}

void Creature::setDead(bool dead)
{
	this->dead=dead;
}

void Creature::operator=(Creature& creature)
{
	this->color=creature.color;
	this->comands=creature.comands;
	this->direction=creature.direction;
	this->font=creature.font;
	this->text=creature.text;
	this->life=creature.life;
	this->lifeNow=creature.lifeNow;
	this->position=creature.position;
	this->dead=creature.dead;
}

bool Creature::operator==(Creature& creature)
{
	return this->comands==creature.comands && this->position==creature.position;
}