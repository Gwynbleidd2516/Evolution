#include<iostream>
#include <SFML/Graphics.hpp>
#include<string>
#include<vector>
#include<math.h>

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

#define DEBUG

void reborn(Map& map, vector<Creature> & Creatures, vector<Creature> & deadCreatures, int life, int howManyMustBeReproducted, Voidness& voidness)
{
	srand(time(0));
	RandMap Rand(true);
	vector<Creature> NewCreatures;
	for(int i=deadCreatures.size()-1; i>=deadCreatures.size()-howManyMustBeReproducted; i--)
	{
		for(int r=0; r<howManyMustBeReproducted; r++)
		{
			NewCreatures.push_back(deadCreatures[i]);
		}
	}
	for (int y = 0; y < map.getHeight(); y++) {
		for (int x = 0; x < map.getWidth(); x++) {
			if(map.getObject(x,y)==Object::Creature || map.getObject(x,y)==Object::Food || map.getObject(x,y)==Object::Poison)
			{
				map.setObject(x,y,voidness);
			}
		}
	}

	Creatures=NewCreatures;
	int number=rand()%Creatures.size();
	Creatures[number].comands[number]=rand()%32;
	Creatures[number].comands[number+1]=rand()%32;
	for (int i = 0; i < Creatures.size(); i++)
	{
		Creatures[i].setLife(life);
		Creatures[i].setDead(false);
		Rand.setCreatures(map,Creatures[i]);
	}
}

void reproduction(Map& map, vector<Creature>& creatures, int howMany, Vector2i lifeReproduction)
{
	srand(time(0));
	int amount=creatures.size();
	int number;
	int change;
	int x;
	int y;
	
	for(int i=0; i<amount; i++)
	{
		if(creatures[i].getLife()>=lifeReproduction.x && creatures[i].getLife()<=lifeReproduction.y)
		{
			for (int r=0; r<=howMany; r++){
				Creature idiot=creatures[i];
				number=rand()%creatures[i].comands.size();
				change=rand()%50;
				if(change==1)
				{
					idiot.comands[number]=number;
				}
				idiot.setLife(30);
				creatures.push_back(idiot);
				int i=0;
				while(true)
				{
					x=rand()%map.getWidth();
					y=rand()%map.getHeight();
					if(map.getObject(x,y)==Object::Voidness)
					{
						creatures[amount+r].setCordinats(x,y);
						map.setObject(x, y, creatures[amount+r]);
						break;
					}

					i++;

					if(i==(map.getHeight()-1) * (map.getWidth()-1)) break;
				}
			}
		}
	}
	
}

int main()
{
	setlocale(LC_ALL, "ru");
	int width, height, Cellsize, interval;
	int video[2];
	bool a=false;

	
	#ifndef DEBUG

	cout << "Enter the map parametrs: \nwidth, height, Cellsize, interval" << endl;

	cin >> width >> height >> Cellsize >> interval;
	#else	
		width=80;
		height=40;
		Cellsize=20;
		interval=1;
		
	#endif
	video[0]=width*Cellsize+250;
	video[1]=height*Cellsize;
	sf::RenderWindow window(sf::VideoMode(video[0], video[1]), "Evolution", Style::Close);
	window.setFramerateLimit(60);

	Voidness voidness(Color::Color(26,26,26));
	Wall wall(Color::Red);
	Food food(Color::Green, 5);
	Poison poisonn(Color::Yellow, 5);

	vector<Creature> idiots(16);
	for (int i=0;i<idiots.size();i++)
	{
		idiots[i].setCreature(Color::Blue,30);
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

	bool pause=true;

	float time=1.0f;

	vector<Creature> deadCreatures;

	int maxlive=0;

	Font font;

	font.loadFromFile(FONT_PATH);
	Text maxText;
	maxText.setPosition(map.getPosition().x + map.getSize().x+1, map.getPosition().y);
	maxText.setFont(font);
	maxText.setCharacterSize(20);

	Text average;
	average.setFont(font);
	average.setCharacterSize(20);
	average.setPosition(map.getPosition().x + map.getSize().x+1, map.getPosition().y+20);

	Text life;
	life.setFont(font);
	life.setCharacterSize(20);

	while (window.isOpen())
	{

		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();

			
			if(event.type==event.KeyPressed)
			{
				if(Keyboard::isKeyPressed(Keyboard::Up) && time>0.0f)
				{
					time-=0.01f;
				}
				else if(Keyboard::isKeyPressed(Keyboard::Down))
				{
					
					time+=0.01f;
				}

				if(Keyboard::isKeyPressed(Keyboard::Space))
				{
					if(pause) pause=false;
					else pause=true;
				}
			}
			
		}
		
		if (clock.getElapsedTime().asSeconds()>time && pause)
		{
			
			/*
			for (int i = 0; i < idiots.size(); i++)
			{
				--idiots[i];
			}
			*/
			step.doStep(map, idiots, voidness, food, poisonn);
			
			int deads=0;

			int lifes=0;

			for (int i=0; i<idiots.size(); i++)
			{
				deads+=idiots[i].isDead();
				lifes+=!idiots[i].isDead();
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

			reproduction(map, idiots, 1, Vector2i(90, 100));

			if(deads==idiots.size())
			{
				reborn(map,idiots,deadCreatures,30,4,voidness);
				Rand.setFoodandPoison(map,food,poisonn,voidness);
			}

			// for (int i = 0; i<idiots.size(); i++)
			// {
			// 	if(idiots[i].isDead())
			// 	{
			// 		map.setObject(idiots[i].getCordinats(), voidness);
			// 	}
			// }

			clock.restart();
		}

		float livesumm=0;
		for(int i=0; i<idiots.size(); i++)
		{
			maxlive=max(maxlive, idiots[i].getLife());
			if(!idiots[i].isDead()) livesumm+=idiots[i].getLife();
		}

		maxText.setString("max - " + to_string(maxlive));
		average.setString("average - " + to_string(livesumm/idiots.size()));

		

		window.clear();
		map.render(window);
		window.draw(maxText);
		window.draw(average);
		int textPosition=map.getPosition().x + map.getSize().x+1;
		for(int h = 0, i = 0;i<idiots.size();i++)
		{
			life.setString(to_string(i) + " - " + to_string(idiots[i].getLife()));
			if(map.getPosition().y + 40 + h*20 > map.getPosition().y + map.getSize().y-20)
			{
				textPosition+=70;
				h=0;
			}
			h++;
			life.setPosition(textPosition, map.getPosition().y+20 + h*20);
			window.draw(life);
		}
		window.display();
	}

	return 0;
}