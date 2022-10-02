<<<<<<< HEAD

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
};

#endif // !THINGS
=======

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
};

#endif // !THINGS
>>>>>>> 5efb7d6256e01d8ddce7c3d66e56e77e41cc2105
