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

void Circle::resolveCollision(Circle other)
{
    Vector2d normal = getCollisionNormal(other);
    float relative_velocity_along_normal = getRelativeVelocityNormal(other, normal);

    if (isVelocitySeparating(relative_velocity_along_normal))
    {
        return;
    }

    float impulse_scalar = getImpulseScalar(other, relative_velocity_along_normal);
    Vector2d impulse = getImpulseNormal(impulse_scalar, normal);

    applyImpulse(other, impulse);
}

Vector2d Circle::getCollisionNormal(Circle other)
{
    return this->getPosition() - other.getPosition();
}
