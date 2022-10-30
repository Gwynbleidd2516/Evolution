#pragma once
#ifndef MAP
#define MAP

#include"SFML/Graphics.hpp"
#include"Things.h"
#include<vector>

// #define DEBUG_MAP

#ifdef DEBUG_MAP
#include<iostream>
#endif

using namespace sf;
using namespace std;


class Map {
private:
	vector<vector<Color>> ColorMap;
	vector<vector<Object>> ObjectMap;
	int width;
	int height;
	int Cellsize;
	int interval;
	Vector2f Position;
	RectangleShape cube;

public:
	Map(const int width, const int height, int Cellsize, int interval);

	void render(RenderWindow& window);

	void setObject(int x, int y, Thing& thing);

	void setObject(Vector2i vector, Thing & thing);

	void setPosition(float x, float y);

	void setPosition(Vector2f vector);

	void operator =(Map& map);

	Object getObject(int x, int y);

	Object getObject(Vector2i vector);

	int getWidth();

	int getHeight();

	Vector2f getSize();

	Vector2f getPosition();
};
#endif // !MAP
