#include <circle.h>
#include <vector2d.h>

Circle::Circle()
{
    setRadius(0.0);
    setPosition(Vector2d());
}

Circle::Circle(float radius, Vector2d position)
{
    setRadius(radius);
    setPosition(position);
}

void Circle::setRadius(float radius)
{
    this->radius = radius;
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

Vector2d Circle::getPosition()
{
    return this->position;
}

Vector2d Circle::getVelocity()
{
    return this->velocity;
}

bool Circle::intersection(Circle other)
{
    float r = this->radius + other.radius;
    return r < this->position.distance(other.getPosition());
}