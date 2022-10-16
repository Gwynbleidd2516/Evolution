#include<iostream>
#include <SFML/Graphics.hpp>
#include<string>
#include<vector>

#include"Map.h"
#include"Food.h"
#include"Wall.h"
#include"Voidness.h"
#include"Poison.h"
#include"Creatures.h"
#include"Things.h"
#include"RandMap.h"
#include"Step.h"
using namespace sf;
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int width, height, Cellsize, interval;
	int video[2];
	bool a=false;

	
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

	vector<Creature> idiots(16);
	for (int i=0;i<idiots.size();i++)
	{
		idiots[i].setCreature(Color::Cyan,false);
	}

	Map map(width, height, Cellsize, interval);
	map.setPosition(0, 0);


	RandMap Rand(false);
	Rand.setRandMap(map, voidness, wall, food, poisonn);

	for (int i = 0; i < idiots.size(); i++)
	{
		Rand.setCreatures(map, idiots[i], false);
	}

	Clock clock;

	Step step;

	bool pause=false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Space) || event.type==event.KeyReleased)
			{
				if(pause) pause=false;
				else pause=true;
			}
			
		}
		
		cout<<pause<<endl;
		if (clock.getElapsedTime().asSeconds()>3 && pause)
		{
			step.doStep(map, idiots, voidness);
			clock.restart();
		}

		window.clear();
		map.render(window);
		window.display();
	}

	return 0;
}