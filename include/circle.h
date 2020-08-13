#include <vector2d.h>
#include <rigid_body.h>

class Circle : public RigidBody
{
    private:
        float radius;

    public:
        Circle();
        Circle(float mass, float radius, Vector2d position, Vector2d velocity);

        void setRadius(float radius);
        float getRadius();

        bool intersection(Circle other);
        void resolveCollision(Circle other);
};
