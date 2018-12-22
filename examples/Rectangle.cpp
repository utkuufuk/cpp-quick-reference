// double quotes indicate that Rectangle.h is located in the current project directory;
// as opposed to the compiler's include file directory
#include "Rectangle.h"   

// the static member variable definition
int Rectangle::numObjects = 0;

Rectangle::Rectangle() : width(0.0), length(0.0)
{
    // increment total number of objects in each constructor call
    numObjects++;   
} 

void Rectangle::setWidth(double w)
{
    width = w;
}

void Rectangle::setLength(double len)
{
    length = len;
}

double Rectangle::getArea() const
{
    return width * length;
}

int Rectangle::getNumObjects()
{
    return numObjects;
}
