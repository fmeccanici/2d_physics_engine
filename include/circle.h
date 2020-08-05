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
        float getRadius();
        Vector2d getPosition();
        Vector2d getVelocity();

        bool intersection(Circle other);
};