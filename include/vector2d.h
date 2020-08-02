#include "point2d.h"

#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2d
{
    private:
        Point2d start_point;
        Point2d end_point;

    public:
        Vector2d(Point2d start_point, Point2d end_point);
        void setVector(Point2d start_point, Point2d end_point);
};
#endif