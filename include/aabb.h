#include <vector2d.h>

#ifndef AABB_H
#define AABB_H

class AABB
{
    private:
        Vector2d min;
        Vector2d max;
    public:
        bool intersection(AABB other);
        Vector2d getMin();
        Vector2d getMax();

};

#endif