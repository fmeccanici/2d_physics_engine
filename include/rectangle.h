#include <vector2d.h>

class Circle
{
    private:
        float width;
        float height;

        Vector2d position;
        Vector2d velocity;
        Vector2d acceleration;

    public:
        Rectangle();
        Rectangle(float mass, float radius, Vector2d position);
        void setRadius(float radius);
        void setMass(float mass);

        void setPosition(Vector2d position);
        void setVelocity(Vector2d velocity);
        void setAcceleration(Vector2d acceleration);

        float getRadius();
        float getMass();

        Vector2d getPosition();
        Vector2d getVelocity();
        Vector2d getAcceleration();

        bool intersection(Circle other);
        void numericalIntegrationStep();
};