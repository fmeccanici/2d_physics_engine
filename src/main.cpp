#include <vector2d.h>
#include <circle.h>
#include <iostream>

#include <SFML/Graphics.hpp>

using namespace std;


int main()
{   

    // Vector2d vector2d(1.0, 1.0);
    // std::cout << vector2d.getX() << std::endl;
    int n_circles = 1;
    vector<Circle> balls(n_circles);
    vector<sf::CircleShape> balls_to_draw(n_circles);

    for (int i = 0; i < n_circles; i++)
    {   
        float radius = i;
        float x = 1.0; 
        float y = 1.0;
        Vector2d position = Vector2d(x, y);
        
        balls[i].setCircle(radius, position);
        
        balls_to_draw[i].setOrigin(position.getX(), position.getY());
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
            // sf::CircleShape ball(balls[i].getRadius());
            // sf::CircleShape ball(10.0);

            cout<<balls_to_draw[i].getPosition().getX()<<endl;
            cout<<balls_to_draw[i].getPosition().getX()<<endl;
            cout<<balls_to_draw[i].getRadius()<<endl;

            cout<<"\n"<<endl;

            // ball.setOrigin(balls[i].getPosition().getX(), balls[i].getPosition().getY());
            ball.setOrigin(10.0, 10.0);

            window.draw(ball);
        }
        window.display();
    }

    return 0;

}