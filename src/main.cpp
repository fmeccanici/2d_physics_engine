#include <vector2d.h>
#include <circle.h>
#include <iostream>

#include <SFML/Graphics.hpp>

using namespace std;


int main()
{   
    int n_circles = 5;
    vector<Circle> balls(n_circles);
    vector<sf::CircleShape> balls_to_draw(n_circles);

    for (int i = 0; i < n_circles; i++)
    {   
        float random_radius = rand() % 50 + 1;
        float radius = random_radius;

        float random_x_position = rand() % 700 + 1;
        float random_y_position = rand() % 700 + 1;

        float x = random_x_position; 
        float y = random_y_position;

        Vector2d position = Vector2d(x, y);
        
        balls[i].setCircle(radius, position);
        
        balls_to_draw[i].setPosition(position.getX(), position.getY());
        balls_to_draw[i].setRadius(radius);
        balls_to_draw[i].setFillColor(sf::Color::Green);
    }

    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        for (int i = 0; i < balls_to_draw.size(); i++)
        {
            window.draw(balls_to_draw[i]);
        }

        window.display();
    }

    return 0;

}