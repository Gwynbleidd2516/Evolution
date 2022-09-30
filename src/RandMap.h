#pragma once

#include <SFML/Graphics.hpp>
#include<ctime>

#include"Map.h"
#include"Food.h"
#include"Wall.h"
#include"Voidness.h"
#include"Poison.h"
#include"Creatures.h"
#include"Things.h"
using namespace sf;
using namespace std;

class RandMap {
private:
	bool randMark;
public:
	void setRandMap(Map& map,
		Voidness& voidness,
		Wall& wall,
		Food& food,
		Poison& poison,
		Creature creature);

	RandMap(bool randMark = false);

	void setRandMark(bool randMark);
};