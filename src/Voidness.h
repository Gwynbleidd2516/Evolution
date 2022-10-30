
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
	Text text;
	Font font;

public:
	Voidness(Color color);

	Color getColor() override;

	Object getObject() override;
};

#endif // !VOIDNESS
