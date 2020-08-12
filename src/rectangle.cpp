#include <rectangle.h>
#include <vector2d.h>
#include <constants.h>

#include <iostream>

Rectangle::Rectangle()
{
    setWidth(0.0);
    setHeight(0.0);
    setMass(0.0);
    setPosition(Vector2d());
    setVelocity(Vector2d());
    setAcceleration(Vector2d());
}

Rectangle::Rectangle(float mass, float width, float height, Vector2d position, Vector2d velocity)
{
    setWidth(width);
    setHeight(height);
    setPosition(position);
    setVelocity(velocity);
    setAcceleration(Vector2d(0.0, 9.81*mass));
}

void Rectangle::setWidth(float width)
{
    this->width = width;
}

void Rectangle::setHeight(float height)
{
    this->height = height;
}

float Rectangle::getWidth()
{
    return this->width;
}

float Rectangle::getHeight()
{
    return this->height;
}

Vector2d Rectangle::getTopLeft()
{
    return this->getPosition() - Vector2d(this->getWidth()/2, this->getHeight()/2);
}

Vector2d Rectangle::getBottomRight()
{
    return this->getPosition() + Vector2d(this->getWidth()/2, this->getHeight()/2);
}

bool Rectangle::intersection(Rectangle other)
{
    if (this->getBottomRight().getX() < other.getTopLeft().getX() || this->getTopLeft().getX() > other.getBottomRight().getX())
    {
        return false;
    }
    
    if (this->getBottomRight().getY() < other.getTopLeft().getY() || this->getTopLeft().getY() > other.getBottomRight().getY())
    {
        return false;
    }

    return true;
}

