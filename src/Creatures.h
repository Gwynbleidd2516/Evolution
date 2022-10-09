#ifndef CREATURES
#define CREATURES

#include"SFML/Graphics.hpp"
#include"Things.h"
#include<ctime>
#include<vector>
using namespace sf;
using namespace std;

class Creature : public Thing {
private:
	Color color;
	const Object object = Object::Creature;
	
	Font font;
	int life = 30;
	Text text;
	Vector2i position;

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
};

#endif // !CREATURES
