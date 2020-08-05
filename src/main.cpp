#include <vector2d.h>
#include <circle.h>
#include <iostream>
using namespace std;

#include "olcPixelGameEngine.h"

class CirclePhysics : public olcConsoleGameEngine
{
    public:
        CirclePhysics()
        {
            app_name = L"Circle Physics";
        }

private:
    vector<pair<float, float>> model_circle;
    vector<Circle> vec_circles;

    void addCircle(Circle circle)
    {
        vec_circles.emplace_back(circle);
    }
    
public: 
    bool OnUserCreate()
    {
        model_circle.push_back( {0.0f, 0.0f} );
        int n_points = 20;
        for (int i = 0; i < n_points; i++)
			model_circle.push_back({ cosf(i / (float)(nPoints - 1) * 2.0f * 3.14159f) , sinf(i / (float)(nPoints - 1) * 2.0f * 3.14159f) });
        
        float default_radius = 8.0f;

        addCircle(ScreenWidth() * 0.25f, ScreenHeight() * 0.5f, default_radius);
        addCircle(ScreenWidth() * 0.75f, ScreenHeight() * 0.5f, default_radius);

        
        return true;
    }

    bool OnUserUpdate(float elapsed_time)
    {
        // clear screen
        Fill(0, 0, ScreenWidth(), ScreenHeight(), ' ');

        // draw balls
        for (auto circle: vec_circles)
            DrawWireFameModel(model_circle, circle.getPosition().getX(), circle.getPosition().getY(), atan2f(circle.getVelocity().getX(), circle.getVelocity().getY()), circle.getRadius(), FG_WHITE );

        return true;
    }
};

int main()
{   CirclePhysics game;

    if (game.ConstructConsole(160, 120, 8, 8))
        game.Start();
    else
        wcout << L"Could not construct console" << endl;

    // Vector2d vector2d(1.0, 1.0);
    // std::cout << vector2d.getX() << std::endl;
    return 0;
}