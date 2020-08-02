#include <vector2d.h>
#include <point2d.h>

int main()
{   
    Point2d start_point(0.0,0.0);
    Point2d end_point(1.0,1.0);

    Vector2d vector2d(start_point, end_point);
    std::cout << vector2d.start_point.x << std::endl;
}