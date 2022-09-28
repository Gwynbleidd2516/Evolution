
#ifndef THINGS
#define THINGS

#include"SFML/Graphics.hpp"
using namespace sf;
using namespace std;

class Thing {

public:
	virtual Color getColor() = 0;

};

#endif // !THINGS
