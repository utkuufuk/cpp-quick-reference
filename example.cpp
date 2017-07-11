#include <iostream>

using namespace std;

struct Circle
{
    double radius;
    double area;
};

void initCircle(Circle circle)
{
    circle.radius = 1.1;
    circle.area = 2.2;
}

void initCircles(Circle* circles, int numCircles)
{
    for (int i = 0; i < 5; i++)
    {
        circles[i].radius = 1.1 * i;
        circles[i].area = 2.2 * i;
    }
}

void printCircles(Circle* circles, int numCircles)
{
    for (int i = 0; i < 5; i++)
    {
        cout << circles[i].radius << endl;
        cout << circles[i].area << endl;
        cout << endl;
    }
}

int main()
{
    Circle* cirPtr = new Circle;
    Circle* circles = new Circle[5];

    initCircle(*cirPtr);

    cout << "circle radius: " << cirPtr->radius << endl;
    cout << "circle area: " << cirPtr->area << endl;

    initCircles(circles, 5);
    printCircles(circles, 5);
}
