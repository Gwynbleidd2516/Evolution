
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
	Text text;
	Font font;
	int poison;

public:
	Poison(Color color, int poison);

	Color getColor() override;

	Object getObject() override;

	Text getText() override;

	int getPoison();
};

#endif // !POISON
