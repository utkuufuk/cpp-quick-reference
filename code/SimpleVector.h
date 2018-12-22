#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <cstdlib>

template <class T>
class SimpleVector
{
    private:
        // array pointer
        T *arrPtr {nullptr};

        // number of elements
        int arraySize {0};

        // handles subscripts out of range
        void subscriptError();  

    public:
        // default constructor
        SimpleVector() = default;

        // constructor
        SimpleVector(int);

        // copy constructor
        SimpleVector(const SimpleVector&);

        // copy assignment
        SimpleVector& operator=(const SimpleVector&);

        // destructordeclaration
        ~SimpleVector();

        // array size accessor
        int size() const
        { 
            return arraySize; 
        }

        // accessor to return a specific element
        T getElementAt(int position);

        // overloaded [] operator declaration
        T &operator[](const int&);
};

template <class T>
SimpleVector<T>::SimpleVector(int s) : arraySize(s), arrPtr(new T[s])
{
    // initialize the array
    for (int i = 0; i < arraySize; i++)
    {
        arrPtr[i] = 0;
    }
}

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj) : arraySize(obj.arraySize), arrPtr(new T[obj.arraySize])
{
    // copy the elements of source array
    for (int i = 0; i < arraySize; i++)
    {
        arrPtr[i] = obj.arrPtr[i];
    }
}

template<class T>
SimpleVector<T>& SimpleVector<T>::operator=(const SimpleVector<T>& other)
{
    delete [] arrPtr;

    // copy the array size
    arraySize = other.arraySize;

    // allocate memory for the array
    arrPtr = new T[arraySize];

    // copy the elements of source array
    for (int i = 0; i < arraySize; i++)
    {
        arrPtr[i] = other.arrPtr[i];
    }
    return *this;
}

template <class T>
SimpleVector<T>::~SimpleVector()
{
    delete [] arrPtr;
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
T &SimpleVector<T>::operator[](const int& sub)
{
    if (sub < 0 || sub >= arraySize)
    {
        subscriptError();
    }
    return arrPtr[sub];
}
#endif