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

    public:
        RigidBody();
        void setMass(float mass);
        void setPosition(Vector2d position);
        void setVelocity(Vector2d velocity);
        void setAcceleration(Vector2d acceleration);

        Vector2d getPosition();
        Vector2d getVelocity();
        Vector2d getAcceleration();
        float getMass();
        
        bool intersection(RigidBody other);
        void numericalIntegrationStep();
};

#endif