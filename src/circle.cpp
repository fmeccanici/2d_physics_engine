#include <circle.h>
#include <vector2d.h>
#include <rigid_body.h>

#include <constants.h>
#include <iostream>

Circle::Circle()
{
    setRadius(0.0);
    setMass(0.0);
    setPosition(Vector2d());
    setVelocity(Vector2d());
    setAcceleration(Vector2d());
}

Circle::Circle(float radius, float mass, Vector2d position, Vector2d velocity)
{
    setRadius(radius);
    setMass(mass);
    setPosition(position);
    setVelocity(velocity);
    setAcceleration(Vector2d(0.0, 9.81*mass));
}

void Circle::setRadius(float radius)
{
    this->radius = radius;
}

float Circle::getRadius()
{
    return this->radius;
}

bool Circle::intersection(Circle other)
{
    float r = this->getRadius() + other.getRadius();
    return r < this->getPosition().distance(other.getPosition()); 
}