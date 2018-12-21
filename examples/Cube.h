#ifndef CUBE_H
#define CUBE_H

#include "Rectangle.h"

// the word public is the base class access specification
class Cube : public Rectangle
{
    private:
        double height;
        double volume;

    public:
        Cube() : Rectangle()
        {
            height = 0.0; volume = 0.0; 
        }

        Cube(double width, double length, double height);

        double getHeight() const
        { 
            return height; 
        }

        double getVolume() const
        {
            return volume; 
        }
};

Cube::Cube(double width, double length, double height) : Rectangle(width, length)
{
    height = height;
    volume = getArea() * height; // call parent class function
}
#endif