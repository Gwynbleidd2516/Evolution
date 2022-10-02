<<<<<<< HEAD

#ifndef VOIDNESS
#define VOIDNESS

#include"SFML/Graphics.hpp"
#include"Things.h"
using namespace sf;
using namespace std;

class Voidness : public Thing {
private:
	Color color;
	const Object object = Object::Voidness;

public:
	Voidness(Color color);

	Color getColor() override;

	Object getObject() override;
};

#endif // !VOIDNESS
=======

#ifndef VOIDNESS
#define VOIDNESS

#include"SFML/Graphics.hpp"
#include"Things.h"
using namespace sf;
using namespace std;

class Voidness : public Thing {
private:
	Color color;
	const Object object = Object::Voidness;

public:
	Voidness(Color color);

	Color getColor() override;

	Object getObject() override;
};

#endif // !VOIDNESS
>>>>>>> 5efb7d6256e01d8ddce7c3d66e56e77e41cc2105
