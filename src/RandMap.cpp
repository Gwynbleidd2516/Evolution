#include "RandMap.h"

void RandMap::setRandMap(Map & map, Voidness & voidness, Wall & wall, Food & food, Poison & poison)
{
	int Number;

	if (randMark) srand(time(0));

	for (int i=0;i<map.getWidth();++i){
		map.setObject(i,0,wall);
		map.setObject(i,map.getHeight()-1,wall);
	}

	for (int i=0;i<map.getHeight();++i){
		map.setObject(0,i,wall);
		map.setObject(map.getWidth()-1,i,wall);
	}

	for (int y = 0; y < map.getHeight(); ++y) {
		for (int x = 0; x < map.getWidth(); ++x) {

			Number = rand() % 20;
			
			if(map.getObject(x,y)!=Object::Wall){
			
				switch (Number)
				{
				case 0:
					map.setObject(x, y, food);
					break;
				case 1:
					map.setObject(x, y, poison);
					#ifdef DEBUG
					std::cout<<"food "<<x<<"\t"<< y << endl;
					#endif
					break;
				case 2:
					map.setObject(x, y, wall);

					#ifdef DEBUG
					std::cout<<"wall "<<x<<"\t"<< y << endl;
					#endif

					break;
				default:
					map.setObject(x, y, voidness);

					#ifdef DEBUG
					std::cout<<"voidness "<<x<<"\t"<< y << endl;
					#endif
				break;
				}
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

void RandMap::setCreatures(Map& map, Creature& creature, bool random)
{
	if(random) srand(time(0));
	
	int Number[2];
	while(true)
	{
		Number[0]=rand() % map.getWidth();
		Number[1]=rand() % map.getHeight();
		if (map.getObject(Number[0], Number[1])==Object::Voidness)
		{
			map.setObject(Number[0], Number[1], creature);
			creature.setCordinats(Vector2i(Number[0], Number[1]));
			break;
		}
	}
}