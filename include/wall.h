#include <vector2d.h>
#include <rigid_body.h>

#ifndef WALL_H
#define WALL_H

class Wall : public Rectangle
{
    public:
        Wall();
        Wall(float width, float height, Vector2d position);
        void setWidth(float width);
        void setHeight(float height);
        float getWidth();
        float getHeight();
        Vector2d getBottomRight();
        Vector2d getTopLeft();

        bool intersection(Rectangle other);
};

#endif