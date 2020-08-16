#include <iostream>

#include <vector2d.h>
#include <circle.h>
#include <constants.h>
#include <world.h>

using namespace std;

void World::numericalIntegrationStep()
{
    for (int i = 0; i < this->balls.size(); i++)
    {
        balls[i].numericalIntegrationStep(this->time_step);
    }

    for (int i = 0; i < this->rectangles.size(); i++)
    {
        rectangles[i].numericalIntegrationStep(this->time_step);
    }
}

void World::addBall(Circle ball)
{
    this->balls.push_back(ball);
}

void World::addRectangle(Rectangle rectangle)
{
    this->rectangles.push_back(rectangle);
}

void World::addRandomBalls()
{
    int n_circles = rand() % 5;
    float mass_in_kg = 0.001;

    for (int i = 0; i < n_circles; i++)
    {   
        Circle ball;

        float random_radius = rand() % 50 + 1;

        float random_x_position = rand() % 700 + 1;
        float random_y_position = rand() % 700 + 1;

        Vector2d random_position = Vector2d(random_x_position, random_y_position);
        // Vector2d velocity = Vector2d(1.0, 1.0);
        
        ball.setRadius(random_radius);
        ball.setMass(mass_in_kg);
        ball.setPosition(random_position);
        // balls[i].setVelocity(velocity);

        addBall(ball);
    }
}

void World::startSimulation()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    addRandomBalls();
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        for (int i = 0; i < this->balls.size(); i++)
        {
            window.draw(balls[i].getDrawableObject());
        }

        numericalIntegrationStep();

        window.display();
    }
}

int main()
{   
    World world;
    world.startSimulation();
    
    return 0;
}