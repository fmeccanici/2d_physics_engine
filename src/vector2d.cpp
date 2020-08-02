#include "vector2d.h"

Vector2d::Vector2d(float x, float y)
{
    setVector(x, y);
}

void Vector2d::setVector(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Vector2d::getX()
{
    return this->x;
}

float Vector2d::getY()
{
    return this->y;
}