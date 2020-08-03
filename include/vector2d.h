#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2d
{
    private:
        float x;
        float y;

    public:
        Vector2d();
        Vector2d(float x, float y);
        void setVector(float x, float y);
        float getX();
        float getY();
        float distance(Vector2d other);
};
#endif