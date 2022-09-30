#include "RandMap.h"

void RandMap::setRandMap(Map & map, Voidness & voidness, Wall & wall, Food & food, Poison & poison, Creature creature)
{
	int Number;

	if (randMark) srand(time(0));

	for (int y = 0; y < map.getHeight(); ++y) {
		for (int x = 0; x < map.getWidth(); ++x) {

			Number = rand() % 4;

			switch (Number)
			{
			case 0:
				map.setObject(x, y, voidness);
				break;
			case 1:
				map.setObject(x, y, creature);
				break;
			case 2:
				map.setObject(x, y, food);
				break;
			case 3:
				map.setObject(x, y, wall);
				break;
			case 4:
				map.setObject(x, y, poison);
			default:
				break;
			}
		}
	}
}

RandMap::RandMap(bool randMark)
{
	this->randMark = randMark;
}

void RandMap::setRandMark(bool randMark)
{
	this->randMark = randMark;
}
