#include <vector2d.h>
#include <rigid_body.h>

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public RigidBody
{
    private:
        float width;
        float height;

    public:
        Rectangle();
        Rectangle(float mass, float width, float height, Vector2d position, Vector2d velocity);
        void setWidth(float width);
        void setHeight(float height);
        float getWidth();
        float getHeight();
        Vector2d getBottomRight();
        Vector2d getTopLeft();

        bool intersection(Rectangle other);
};

#endif