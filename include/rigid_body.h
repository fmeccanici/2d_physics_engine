#include <vector2d.h>

#ifndef RIGID_BODY_H
#define RIGID_BODY_H

class RigidBody
{
    private:
        Vector2d position;
        Vector2d velocity;
        Vector2d acceleration;
        float mass;
        float restitution_coefficient;

    public:
        RigidBody();
        void setMass(float mass);
        void setPosition(Vector2d position);
        void setVelocity(Vector2d velocity);
        void setAcceleration(Vector2d acceleration);
        void setRestitutionCoefficient(float e);


        Vector2d getPosition();
        Vector2d getVelocity();
        Vector2d getAcceleration();
        float getMass();
        float getRestitutionCoefficient();

        bool intersection(RigidBody other);
        void resolveCollision(RigidBody other, Vector2d collision_normal);
        void numericalIntegrationStep();
        Vector2d getRelativeVelocity(RigidBody other);
        bool isVelocitySeparating(float velocity);
        float getRelativeVelocityNormal(RigidBody other, Vector2d normal);
        float getMinRestitution(RigidBody other);
        float getImpulseScalar(RigidBody other, float velocity_normal);
        Vector2d getImpulseNormal(float impulse_scalar, Vector2d normal);
        void applyImpulse(RigidBody other, Vector2d impulse);
};

#endif