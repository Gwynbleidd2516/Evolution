#include<iostream>
#include <SFML/Graphics.hpp>
#include<string>

#include"Map.h"
#include"Food.h"
#include"Wall.h"
#include"Voidness.h"
#include"Poison.h"
#include"Creatures.h"
#include"Things.h"
#include"RandMap.h"
using namespace sf;
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	
	cout << "¬ведите размер экрана" << endl;

	int video[2];
	cin >> video[0] >> video[1];

	cout << "¬ведите размеры карты: \nширина, высота, размер клетки, интервал" << endl;

	int width, height, Cellsize, interval;

	cin >> width >> height >> Cellsize >> interval;
	
	sf::RenderWindow window(sf::VideoMode(video[0], video[1]), "Evolution", Style::Close);
	window.setVerticalSyncEnabled(60);

	Voidness voidness(Color::White);
	Wall wall(Color::Red);
	Food food(Color::Blue);
	Poison poison(Color::Green);
	Creature idiot(Color::Yellow);

	Map map(width,height,Cellsize,interval);
	map.setPosition(0, 0);


	RandMap Rand;
	Rand.setRandMap(map, voidness, wall, food, poison, idiot);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		}

		window.clear();
		map.render(window);
		window.display();
	}

	return 0;
}