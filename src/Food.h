<<<<<<< HEAD

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
=======

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
>>>>>>> 5efb7d6256e01d8ddce7c3d66e56e77e41cc2105
