#pragma once
#ifndef MAP
#define MAP

#include"SFML/Graphics.hpp"
#include"Things.h"
#include<vector>
using namespace sf;
using namespace std;

class Map {
private:
	vector<vector<Color>> ColorMap;
	vector<vector<RectangleShape>> CubeMap;
	int width;
	int height;
	int Cellsize;
	int interval;

public:
	Map(const int width, const int height, int Cellsize, int interval);

	void render(RenderWindow& window);

	void setObject(int x, int y, Thing& thing);

	void setPosition(float x, float y);

	void setPosition(Vector2f vector);
};
#endif // !MAP
