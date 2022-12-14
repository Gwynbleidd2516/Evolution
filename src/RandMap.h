#pragma once

#include <SFML/Graphics.hpp>
#include<ctime>
#include<iostream>

//#define DEBUG

#include"Map.h"
#include"Food.h"
#include"Wall.h"
#include"Voidness.h"
#include"Poison.h"
#include"Creatures.h"
#include"Things.h"
using namespace sf;


#ifdef DEBUG
#include<iostream>
using namespace std;
#endif

class RandMap {
private:
	bool randMark;
public:
	void setRandMap(Map& map,
		Voidness& voidness,
		Wall& wall
		);

	RandMap(bool randMark = false);

	void setCreatures(Map& map, Creature& creature, bool random=true);

	void setFoodandPoison(Map& map, Food& food, Poison& poison, Voidness& voidness);
};