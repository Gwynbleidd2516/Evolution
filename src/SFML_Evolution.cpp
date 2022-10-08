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
	int width, height, Cellsize, interval;
	int video[2];
	bool a;

	cin >> a;
	if(a){
	cout << "Enter the window resolution:" << endl;

	
	cin >> video[0] >> video[1];

	cout << "Enter the map parametrs: \nwidth, height, Cellsize, interval" << endl;

	cin >> width >> height >> Cellsize >> interval;
	}
	else{
		video[0]=800;
		video[1]=800;
		width=40;
		height=40;
		Cellsize=20;
		interval=1;
	}
	sf::RenderWindow window(sf::VideoMode(video[0], video[1]), "Evolution", Style::Close);
	window.setFramerateLimit(60);

	Voidness voidness(Color::Color(26,26,26));
	Wall wall(Color::Red);
	Food food(Color::Green);
	Poison poisonn(Color::Yellow);
	Creature idiot(Color::Cyan);

	Map map(width, height, Cellsize, interval);
	map.setPosition(0, 0);


	RandMap Rand(true);
	Rand.setRandMap(map, voidness, wall, food, poisonn, idiot);

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