#ifndef CREATURES
#define CREATURES

#include"SFML/Graphics.hpp"
#include"Things.h"
using namespace sf;
using namespace std;

class Creature : public Thing {
private:
	Color color;
	const Object object = Object::Creature;

public:
	Creature(Color color);

	Color getColor() override;

	Object getObject() override;
};

#endif // !CREATURES
