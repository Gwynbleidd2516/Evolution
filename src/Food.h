
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
	Text text;
	Font font;
	int food;

public:
	Food(Color color, int food);

	Color getColor() override;

	Object getObject() override;

	int getFood();
};

#endif // !FOOD
