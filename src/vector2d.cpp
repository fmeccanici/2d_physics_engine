#include "vector2d.h"
#include <math.h>

Vector2d::Vector2d(float x, float y)
{
    setVector(x, y);
}

Vector2d::Vector2d()
{
    setVector(0, 0);
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

float Vector2d::distance(Vector2d other)
{
    return sqrt( pow( (this->x - other.x), 2 ) + pow( (this->y - other.y), 2 ));
}
