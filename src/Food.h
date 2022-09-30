
#ifndef FOOD
#define FOOD

#include"SFML/Graphics.hpp"
#include"Things.h"
using namespace sf;
using namespace std;

class Food : public Thing {
private:
	Color color;
	const Object object = Object::Food;

public:
	Food(Color color);

	Color getColor() override;

	Object getObject() override;
};

#endif // !FOOD
