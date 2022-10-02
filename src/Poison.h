<<<<<<< HEAD

#ifndef POISON
#define POISON

#include"SFML/Graphics.hpp"
#include"Things.h"
using namespace sf;
using namespace std;

class Poison : public Thing {
private:
	Color color;
	const Object object = Object::Poison;

public:
	Poison(Color color);

	Color getColor() override;

	Object getObject() override;
};

#endif // !POISON
=======

#ifndef POISON
#define POISON

#include"SFML/Graphics.hpp"
#include"Things.h"
using namespace sf;
using namespace std;

class Poison : public Thing {
private:
	Color color;
	const Object object = Object::Poison;

public:
	Poison(Color color);

	Color getColor() override;

	Object getObject() override;
};

#endif // !POISON
>>>>>>> 5efb7d6256e01d8ddce7c3d66e56e77e41cc2105
