
#ifndef THINGS
#define THINGS

#include"SFML/Graphics.hpp"
using namespace sf;
using namespace std;

enum class Object {
	Voidness,
	Creature,
	Poison,
	Wall,
	Food
};


class Thing {

public:
	virtual Color getColor() = 0;

	virtual Object getObject() = 0;

	virtual Text getText() = 0;
};

#endif // !THINGS
