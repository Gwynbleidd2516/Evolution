#include "Map.h"

Map::Map(const int width, const int height, int Cellsize, int interval)
{
	this->width = width;
	this->height = height;
	this->Cellsize = Cellsize;
	this->interval = interval;
	CubeMap.resize(width, vector<RectangleShape>(height));
	ColorMap.resize(width, vector<Color>(height));
	ObjectMap.resize(width, vector<Object>(height));
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			CubeMap[x][y].setSize(Vector2f(Cellsize + interval, Cellsize + interval));
		}
	}
}

void Map::setObject(int x, int y, Thing& thing)
{
	ColorMap[x][y] = thing.getColor();
	ObjectMap[x][y] = thing.getObject();
}

void Map::setPosition(float x, float y)
{
	CubeMap[0][0].setPosition(x, y);
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			CubeMap[x][y].setPosition(CubeMap[0][0].getPosition().x + (Cellsize * x), CubeMap[0][0].getPosition().y + (Cellsize * y));
		}

	}
}

void Map::setPosition(Vector2f vector)
{
	CubeMap[0][0].setPosition(vector);
	
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			CubeMap[x][y].setPosition(CubeMap[0][0].getPosition().x + (Cellsize * x), CubeMap[0][0].getPosition().y + (Cellsize * y));
		}
	}
	
}

void Map::operator=(Map & map)
{
	this->ColorMap = map.ColorMap;
	this->CubeMap = map.CubeMap;
	this->ObjectMap = map.ObjectMap;
	this->Cellsize = map.Cellsize;
	this->height = map.height;
	this->width = map.width;
	this->interval = map.interval;
}

int Map::getWidth()
{
	return width;
}

int Map::getHeight()
{
	return height;
}

void Map::render(RenderWindow& window)
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			CubeMap[x][y].setFillColor(ColorMap[x][y]);
			CubeMap[x][y].setOutlineThickness(interval);
			CubeMap[x][y].setOutlineColor(Color::Black);
		}
	}
	
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			window.draw(CubeMap[x][y]);
		}
	}
}
