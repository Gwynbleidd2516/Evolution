
#ifndef POISON
#define POISON

#include"SFML/Graphics.hpp"
#include"Things.h"
using namespace sf;
using namespace std;

class Poison : public Thing {
private:
	Color color;

public:
	Poison(Color color);

	Color getColor() override;
};

#endif // !POISON
