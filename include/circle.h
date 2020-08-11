#include <vector2d.h>
#include <rigid_body.h>

class Circle : RigidBody
{
    private:
        float radius;

    public:
        Circle();
        Circle(float mass, float radius, Vector2d position);

        void setShape(float radius)
        bool intersection(RigidBody other) override;
};
