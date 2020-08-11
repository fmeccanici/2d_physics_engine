#include <circle.h>
#include <vector2d.h>
#include <constants.h>

#include <iostream>


Rectangle::Rectangle()
{
    setRadius(0.0);
    setMass(0.0);
    setPosition(Vector2d());
    setVelocity(Vector2d());
    setAcceleration(Vector2d());
}

Rectangle::Rectangle(float radius, float mass, Vector2d position)
{
    setRadius(radius);
    setRadius(mass);
    setPosition(position);
    setAcceleration(Vector2d(0.0, 9.81*mass));
}

void Circle::setRadius(float radius)
{
    this->radius = radius;
}

void Circle::setMass(float mass)
{
    this->mass = mass;
    setAcceleration(Vector2d(0.0, 9.81*mass));

}

void Circle::setPosition(Vector2d position)
{
    this->position = position;
}

void Circle::setVelocity(Vector2d velocity)
{
    this->velocity = velocity;
}

void Circle::setAcceleration(Vector2d acceleration)
{
    this->acceleration = acceleration;
}

float Circle::getRadius()
{
    return this->radius;
}

float Circle::getMass()
{
    return this->mass;
}

Vector2d Circle::getPosition()
{
    return this->position;
}

Vector2d Circle::getVelocity()
{
    return this->velocity;
}

Vector2d Circle::getAcceleration()
{
    return this->acceleration;
}

bool Circle::intersection(Circle other)
{
    float r = this->radius + other.radius;
    return r < this->position.distance(other.getPosition());
}

void Circle::numericalIntegrationStep()
{   
    float time_step = 0.01;
    
    setPosition( Vector2d(this->getPosition().getX() + this->getVelocity().getX() * time_step, this->getPosition().getY() + this->getVelocity().getY() * time_step) );
    setVelocity( Vector2d(this->getVelocity().getX() + this->getAcceleration().getX() * time_step, this->getVelocity().getY() + this->getAcceleration().getY() * time_step) );
}
