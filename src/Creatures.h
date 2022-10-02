<<<<<<< HEAD
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
=======
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
>>>>>>> 5efb7d6256e01d8ddce7c3d66e56e77e41cc2105
