#include "vector2d.h"
#include <math.h>

Vector2d::Vector2d(float x, float y)
{
    setX(x);
    setY(y);
}

Vector2d::Vector2d()
{
    setX(0);
    setY(0);
}

Vector2d Vector2d::operator+(const Vector2d& other)
{
    Vector2d result;
    result.setX(this->getX() + other.getX());
    result.setY(this->getY() + other.getY());
    return result;
}

Vector2d Vector2d::operator-(const Vector2d& other)
{
    Vector2d result;
    result.setX(this->getX() - other.getX());
    result.setY(this->getY() - other.getY());
    return result;
}

float Vector2d::operator*(const Vector2d& other)
{
    return this->getX() * other.getX() + this->getY() + other.getY();
}

float Vector2d::getX() const
{
    return this->x;
}

float Vector2d::getY() const
{
    return this->y;
}

void Vector2d::setX(float x)
{
    this->x = x;
}

void Vector2d::setY(float y)
{
    this->y = y;
}

float Vector2d::distance(Vector2d other)
{
    return sqrt( pow( (this->x - other.x), 2 ) + pow( (this->y - other.y), 2 ));
}
