#include <vector2d.h>
#include <circle.h>
#include <iostream>

#include <SFML/Graphics.hpp>

using namespace std;


int main()
{   

    // Vector2d vector2d(1.0, 1.0);
    // std::cout << vector2d.getX() << std::endl;
    
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
    
}