#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class SimpleVector
{
    private:
        // array pointer
        T *arrPtr;              

        // number of elements
        int arraySize;          

        // handles subscripts out of range
        void subscriptError();  

    public:
        // default constructor
        SimpleVector()
        { 
            arrPtr = 0; 
            arraySize = 0;
        }

        // constructor declaration
        SimpleVector(int);

        // copy constructor declaration
        SimpleVector(const SimpleVector &);

        // destructor declaration
        ~SimpleVector();

        // array size accessor
        int size() const
        { 
            return arraySize; 
        }

        // accessor to return a specific element
        T getElementAt(int position);

        // overloaded [] operator declaration
        T &operator[](const int &);
};

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    arraySize = s;

    // allocate memory for the array
    arrPtr = new T[s];

    // initialize the array
    for (int count = 0; count < arraySize; count++)
    {
        *(arrPtr + count) = 0;
    }
}

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    // copy the array size
    arraySize = obj.arraySize;

    // allocate memory for the array
    arrPtr = new T [arraySize];

    // copy the elements of source array
    for (int count = 0; count < arraySize; count++)
    {
        *(arrPtr + count) = *(obj.arrPtr + count);
    }
}

template <class T>
SimpleVector<T>::~SimpleVector()
{
    if (arraySize > 0)
    {
        delete [] arrPtr;
    }
}

template <class T>
void SimpleVector<T>::subscriptError()
{
    throw "ERROR: Subscript out of range.";
}

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
    if (sub < 0 || sub >= arraySize)
    {
        subscriptError();
    }
    return arrPtr[sub];
}

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
    if (sub < 0 || sub >= arraySize)
    {
        subscriptError();
    }
    return arrPtr[sub];
}
#endif