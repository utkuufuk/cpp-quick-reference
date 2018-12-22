// include guard prevents the header file from accidentally being included more than once
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
    private:
        // instance member variables
        double width;
        double length;

        // static member variable
        static int numObjects;

    public:
        // default constructor (takes no arguments)
        Rectangle();    

        // constructors can also be defined inline
        Rectangle(double width, double length)
        {
            this->width = width;    
            this->length = length;
            numObjects++;   // increment total number of objects in each constructor call
        }

        // this is a better constructor definition
        Rectangle(double width = 0.0, double length = 0.0) : width(width), length(length) {}

        // member function declarations
        void setWidth(double);
        void setLength(double);

        // a member function defined in declaration is an inline function
        double getWidth() const
        {
            return width;
        }

        // no need to use the scope resolution operator for inline functions
        double getLength() const
        {
            return width;
        }

        // const keyword specifies that the function will not change any data
        double getArea() const;

        // static member functions cannot access any nonstatic member data
        static int getNumObjects();
};
#endif