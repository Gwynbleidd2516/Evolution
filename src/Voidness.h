
#ifndef VOIDNESS
#define VOIDNESS

#include"SFML/Graphics.hpp"
#include"Things.h"
using namespace sf;
using namespace std;

class Voidness : public Thing {
private:
	Color color;

public:
	Voidness(Color color);

	Color getColor() override;
};

#endif // !VOIDNESS
