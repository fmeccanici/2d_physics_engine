#include <vector2d.h>

class Circle
{
    private:
        float radius;
        Vector2d position;
        Vector2d velocity;
        Vector2d acceleration;
        int id;

    public:
        Circle();
        Circle(float radius, Vector2d position);
        void setRadius(float radius);
        void setPosition(Vector2d position);
        void setVelocity(Vector2d velocity);
        void setAcceleration(Vector2d acceleration);

        float getRadius();
        Vector2d getPosition();
        Vector2d getVelocity();
        bool intersection(Circle other);
};