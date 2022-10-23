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

void reproduction(Map& map, vector<Creature> & Creatures, vector<Creature> & deadCreatures, int life, int howManyMustBeReproducted)
{
	RandMap Rand(true);
	vector<Creature> NewCreatures;
	for(int i=deadCreatures.size()-1; i>=deadCreatures.size()-howManyMustBeReproducted; i--)
	{
		deadCreatures[i].setLife(life);
		deadCreatures[i].setDead(false);
		for(int r=0; r<howManyMustBeReproducted; r++)
		{
			NewCreatures.push_back(deadCreatures[i]);
		}
	}
	Creatures=NewCreatures;
	for (int i = 0; i < Creatures.size(); i++)
	{
		Rand.setCreatures(map,Creatures[i]);
	}
}

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
		idiots[i].setCreature(Color::Blue, 30, false);
	}

	Map map(width, height, Cellsize, interval);
	map.setPosition(0, 0);


	RandMap Rand(false);
	Rand.setRandMap(map, voidness, wall);
	Rand.setFoodandPoison(map,food,poisonn,voidness);

	for (int i = 0; i < idiots.size(); i++)
	{
		Rand.setCreatures(map, idiots[i], false);
	}

	Clock clock;

	Step step;

	bool pause=false;

	float time=1.0f;

	vector<Creature> deadCreatures;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();

			
			if(event.type==event.KeyPressed)
			{
				if(Keyboard::isKeyPressed(Keyboard::Up))
				{
					time+=0.01f;
				}
				else if(Keyboard::isKeyPressed(Keyboard::Down) && time>0.0f)
				{
					time-=0.01f;
				}
			}
			
			
		}
		
		if (clock.getElapsedTime().asSeconds()>time)
		{
			for (int i = 0; i < idiots.size(); i++)
			{
				--idiots[i];
			}

			step.doStep(map, idiots, voidness);
			
			int deads=0;

			for (int i=0; i<idiots.size(); i++)
			{
				deads+=idiots[i].isDead();
				if(idiots[i].isDead())
				{
					bool exit=false;
					for(int y=0;y<deadCreatures.size();y++)
					{
						if(idiots[i]==deadCreatures[y])
						{
							exit=true;
							break;
						}
					}
					if(!exit) deadCreatures.push_back(idiots[i]);
				}
			}

			if(deads==idiots.size())
			{
				Rand.setFoodandPoison(map,food,poisonn,voidness);
				reproduction(map,idiots,deadCreatures,30,4);
			}

			clock.restart();
		}

		window.clear();
		map.render(window);
		window.display();
	}

	return 0;
}