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
        Vector2d operator+(const Vector2d& other);
        Vector2d operator-(const Vector2d& other);
        Vector2d operator*(const Vector2d& other);

        float getX() const;
        float getY() const;
        void setX(float x);
        void setY(float y);
        float distance(Vector2d other);

};
#endif