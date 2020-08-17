#include <rectangle.h>
#include <vector2d.h>
#include <constants.h>

#include <iostream>

Wall::Wall()
{
    setWidth(0.0);
    setHeight(0.0);
    setMass(0.0);
    setPosition(Vector2d());
    setVelocity(Vector2d());
    setAcceleration(Vector2d());
}

Wall::Wall(float width, float height, Vector2d position)
{
    setWidth(width);
    setHeight(height);
    setPosition(position);
}

