#include <RigidBody.h>
#include <vector2d.h>
#include <constants.h>

#include <iostream>


RigidBody::RigidBody()
{
    setMass(0.0);
    setPosition(Vector2d());
    setVelocity(Vector2d());
    setAcceleration(Vector2d());
}

void RigidBody::setMass(float mass)
{
    this->mass = mass;
    setAcceleration(Vector2d(0.0, 9.81*mass));

}

void RigidBody::setPosition(Vector2d position)
{
    this->position = position;
}

void RigidBody::setVelocity(Vector2d velocity)
{
    this->velocity = velocity;
}

void RigidBody::setAcceleration(Vector2d acceleration)
{
    this->acceleration = acceleration;
}

float RigidBody::getMass()
{
    return this->mass;
}

Vector2d RigidBody::getPosition()
{
    return this->position;
}

Vector2d RigidBody::getVelocity()
{
    return this->velocity;
}

Vector2d RigidBody::getAcceleration()
{
    return this->acceleration;
}

virtual bool RigidBody::intersection(RigidBody other)
{
    
}

void RigidBody::numericalIntegrationStep()
{   
    float time_step = 0.01;
    
    setPosition( Vector2d(this->getPosition().getX() + this->getVelocity().getX() * time_step, this->getPosition().getY() + this->getVelocity().getY() * time_step) );
    setVelocity( Vector2d(this->getVelocity().getX() + this->getAcceleration().getX() * time_step, this->getVelocity().getY() + this->getAcceleration().getY() * time_step) );
}
