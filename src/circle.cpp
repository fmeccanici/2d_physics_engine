#include <circle.h>

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