#ifndef CREATURES
#define CREATURES

#include"SFML/Graphics.hpp"
#include"Things.h"
#include<ctime>
#include<vector>
using namespace sf;
using namespace std;

enum class Direction
	{
		LEFT_UP,
		UP,
		RIGHT_UP,
		RIGHT,
		DOWN_RIGHT,
		DOWN,
		DOWN_LEFT,
		LEFT
	};

class Creature : public Thing {
private:
	Color color;
	const Object object = Object::Creature;
	
	Font font;
	int life = 30;
	Text text;
	Vector2i position;
	Direction direction;

public: vector<int> comands;
	
public:
	Creature(Color color, bool brand=true);

	Creature();

	void setCreature(Color color, bool brand=true);

	Color getColor() override;

	Object getObject() override;

	void setLife(int life);

	Text getText() override;

	void setCordinats(Vector2i vector);

	void setCordinats(int x, int y);

	Vector2i getCordinats();

	Direction getDirection();

	void setDirection(Direction direction);

	void setRandomComands();
};

#endif // !CREATURES
