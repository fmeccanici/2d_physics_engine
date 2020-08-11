#include <vector2d.h>

class RigidBody
{
    private:
    
        Vector2d position;
        Vector2d velocity;
        Vector2d acceleration;

    public:
        RigidBody();
        void setMass(float mass);
        void setPosition(Vector2d position);
        void setVelocity(Vector2d velocity);
        void setAcceleration(Vector2d acceleration);
        void setShape();

        Vector2d getPosition();
        Vector2d getVelocity();
        Vector2d getAcceleration();

        virtual bool intersection(RigidBody other);
 
        void numericalIntegrationStep();
};