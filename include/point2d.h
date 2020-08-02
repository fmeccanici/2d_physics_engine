#ifndef POINT2D_H
#define POINT2D_H

class Point2d
{
    private:
        float x;
        float y;
    public:
        Point2d();
        Point2d(float x, float y);

        void setPoint(float x, float y);
};

#endif