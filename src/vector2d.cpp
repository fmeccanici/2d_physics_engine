#include "vector2d.h"
#include "point2d.h"

Vector2d::Vector2d(Point2d start_point, Point2d end_point)
{
    setVector(start_point, end_point);
}

void Vector2d::setVector(Point2d start_point, Point2d end_point)
{
    this->start_point = start_point;
    this->end_point = end_point;
}

Point2d getStartPoint()
{
    return this->start_point;
}

Point2d getEndPoint()
{
    return this->end_point;
}