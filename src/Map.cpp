#include "Map.h"

Map::Map(const int width, const int height, int Cellsize, int interval)
{
	this->width = width;
	this->height = height;
	this->Cellsize = Cellsize;
	this->interval = interval;
	if (Cellsize<5)
	{
		this->Cellsize=10;
	}
	ColorMap.resize(width, vector<Color>(height));
	ObjectMap.resize(width, vector<Object>(height));
	
	cube.setSize(Vector2f(Cellsize + interval, Cellsize + interval));
	cube.setOutlineThickness(interval);
	cube.setOutlineColor(Color::Black);
}

void Map::setObject(int x, int y, Thing& thing)
{
	ColorMap[x][y] = thing.getColor();
	ObjectMap[x][y] = thing.getObject();
}

void Map::setObject(Vector2i vector, Thing & thing)
{
	ColorMap[vector.x][vector.y] = thing.getColor();
	ObjectMap[vector.x][vector.y] = thing.getObject();
}

void Map::setPosition(float x, float y)
{
	Position.x=x;
	Position.y=y;
}

void Map::setPosition(Vector2f vector)
{
	Position=vector;
}

void Map::operator=(Map & map)
{
	this->ColorMap = map.ColorMap;
	this->ObjectMap = map.ObjectMap;
	this->Cellsize = map.Cellsize;
	this->height = map.height;
	this->width = map.width;
	this->interval = map.interval;
	this->cube=map.cube;
}

int Map::getWidth()
{
	return width;
}

int Map::getHeight()
{
	return height;
}

Object Map::getObject(int x, int y)
{
	return ObjectMap[x][y];
}

Object Map::getObject(Vector2i vector)
{
	return ObjectMap[vector.x][vector.y];
}

void Map::render(RenderWindow& window)
{
	for (int y = 0; y < height; y++) 
	{
		for (int x = 0; x < width; x++) 
		{
			cube.setFillColor(ColorMap[x][y]);
			cube.setPosition(Position.x + (Cellsize * x), Position.y + (Cellsize * y));
			window.draw(cube);
		}
	}
}

Vector2f Map::getSize()
{
	return Vector2f((Cellsize)*width,(Cellsize)*height);
}

Vector2f Map::getPosition()
{
	return Position;
}