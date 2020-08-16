#include <iostream>
#include <rectangle.h>

using namespace std;

class World
{
    private:
        vector<Circle> balls;
        vector<Rectangle> rectangles;
        float time_step = 0.01;
    public:
        void numericalIntegrationStep();
        void addBall(Circle ball);
        void addRandomBalls();
        void addRectangle(Rectangle rectangle);

        void startSimulation();

};
