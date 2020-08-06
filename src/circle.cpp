#include <circle.h>
#include <vector2d.h>

Circle::Circle()
{
    setCircle(0.0, Vector2d());
}

Circle::Circle(float radius, Vector2d position)
{
    setCircle(radius, position);
}

void Circle::setCircle(float radius, Vector2d position)
{
    this->radius = radius;
    this->position = position;
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