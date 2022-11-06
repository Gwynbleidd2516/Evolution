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

class Creature : public Thing 
{
private:
	Color color;
	const Object object = Object::Creature;
	
	Font font;
	int life = 30;
	int lifeNow=life;
	Text text;
	Vector2i position;
	Direction direction;
	bool dead=false;
	int comands_capacity=40;
	int lifeLimit=100;

public: vector<int> comands;
	
public:
	Creature(Color color, int life, bool brand=true);

	Creature();

	Creature(int life, bool brand=true);

	void setCreature(Color color, int life, bool brand=true);

	void setCreature(int life, bool brand=true);

	Color getColor() override;

	Object getObject() override;

	void setLife(int life);
	
	int getLife();

	void setCordinats(Vector2i vector);

	void setCordinats(int x, int y);

	Vector2i getCordinats();

	Direction getDirection();

	void setDirection(Direction direction);

	void setRandomComands();

	void operator ++();

	void operator --();

	void operator +=(int value);

	void operator -=(int value);

	bool isDead();

	void setDead(bool dead);

	void operator =(Creature& creature);

	bool operator ==(Creature& creature);
};


#endif // !CREATURES
