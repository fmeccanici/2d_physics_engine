#include <aabb.h>
#include <vector2d.h>

Vector2d AABB::getMin()
{
    return this->min;
}

Vector2d AABB::getMax()
{
    return this->max;
}

bool AABB::intersection(AABB other)
{
    if (this->max.getX() < other.min.getX() or this->min.getX() > other.max.getX()) return false;
    if (this->max.getY() < other.min.getY() or this->min.getY() > other.max.getY()) return false;

    return true;
}
