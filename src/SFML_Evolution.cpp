#include <SFML/Graphics.hpp>
#include"Map.h"
#include"Food.h"
#include"Wall.h"
#include"Voidness.h"
#include"Poison.h"
#include"Creatures.h"
#include"Things.h"
using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    Voidness voidness(Color::Cyan);
    Wall wall(Color::Red);
    Food food(Color::Blue);
    Poison poison(Color::Green);
    Creature idiot(Color::Yellow);
    Map map(25, 25, 35, 3);
    map.setPosition(0, 0);

    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 25; x++) {
            map.setObject(x, y, voidness);
        }
    }

    map.setObject(10, 1, wall);

    map.setObject(5, 10, idiot);

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