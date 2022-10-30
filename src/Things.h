
#ifndef THINGS
#define THINGS

#include"SFML/Graphics.hpp"
using namespace sf;
using namespace std;
#define FONT_PATH "res\\Time-Roman-Normal-Font.ttf"

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
};

#endif // !THINGS
