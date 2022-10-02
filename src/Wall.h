<<<<<<< HEAD
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
=======
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
>>>>>>> 5efb7d6256e01d8ddce7c3d66e56e77e41cc2105
