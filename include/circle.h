#include <vector2d.h>
#include <rigid_body.h>

#include <SFML/Graphics.hpp>

class Circle : public RigidBody
{
    private:
        float radius;
        sf::CircleShape drawable_circle;

    public:
        Circle();
        Circle(float mass, float radius, Vector2d position, Vector2d velocity);

        void setRadius(float radius);
        float getRadius();

        bool intersection(Circle other);
        void resolveCollision(Circle other);
        Vector2d getCollisionNormal(Circle other);

        sf::CircleShape getDrawableObject();
};
