#pragma once
#ifndef WALL
#define WALL

#include"SFML/Graphics.hpp"
#include"Things.h"
using namespace sf;
using namespace std;

class Wall: public Thing {
private:
	Color color;
	const Object object = Object::Wall;

public:
	Wall(Color color);

	Color getColor() override;

	Object getObject() override;
};

#endif // !WALL
