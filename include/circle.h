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
        void setCircle(float radius, Vector2d position);
        float getRadius();
        Vector2d getPosition();
        Vector2d getVelocity();
        bool intersection(Circle other);
};