#include <rigid_body.h>
#include <vector2d.h>
#include <constants.h>

#include <algorithm>
#include <iostream>

using namespace std;

RigidBody::RigidBody()
{
    setMass( 0.0 );
    setPosition(Vector2d(0, 0));
    setVelocity(Vector2d(0, 0));
    setAcceleration(Vector2d(0, 0));
    setRestitutionCoefficient(0.0);
}

void RigidBody::setMass(float mass)
{
    this->mass = mass;
    setAcceleration(Vector2d(0.0, 9.81*mass));
}

void RigidBody::setRestitutionCoefficient(float e)
{
    this->restitution_coefficient = e;
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

float RigidBody::getRestitutionCoefficient()
{
    return this->restitution_coefficient;
}

bool RigidBody::intersection(RigidBody other)
{
    
}

void RigidBody::resolveCollision(RigidBody other, Vector2d collision_normal)
{}

Vector2d RigidBody::getRelativeVelocity(RigidBody other)
{
    return this->getVelocity() - other.getVelocity();
}

bool RigidBody::isVelocitySeparating(float velocity)
{
    return velocity > 0;
}

float RigidBody::getRelativeVelocityNormal(RigidBody other, Vector2d normal)
{
    return getRelativeVelocity(other) * normal;
}

float RigidBody::getMinRestitution(RigidBody other)
{
    return min(this->getRestitutionCoefficient(), other.getRestitutionCoefficient());
}

float RigidBody::getImpulseScalar(RigidBody other, float velocity_normal)
{
    float min_restitution_coefficient = getMinRestitution(other);

    float impulse_scalar = (-1 + min_restitution_coefficient) * velocity_normal;
    impulse_scalar /= (1 / this->getMass()) + (1 / other.getMass());

    return impulse_scalar;
}

Vector2d RigidBody::getImpulseNormal(float impulse_scalar, Vector2d normal)
{
    return normal * impulse_scalar;
}

void RigidBody::applyImpulse(RigidBody other, Vector2d impulse)
{
    this->setVelocity( this->getVelocity() - impulse * (1 / this->getMass()) );
    other.setVelocity( other.getVelocity() + impulse * (1 / other.getMass()) );
}

void RigidBody::numericalIntegrationStep()
{   
    float time_step = 0.01;
    
    setPosition( Vector2d(this->getPosition().getX() + this->getVelocity().getX() * time_step, this->getPosition().getY() + this->getVelocity().getY() * time_step) );
    setVelocity( Vector2d(this->getVelocity().getX() + this->getAcceleration().getX() * time_step, this->getVelocity().getY() + this->getAcceleration().getY() * time_step) );
}

