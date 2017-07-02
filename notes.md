# C++ for C Programmers

## Compiling C/C++ Code
**Compile and run a C program using terminal:**
```
gcc hello.c -o hello
./hello
``` 

**Compile and run a C++ program using terminal:**
```
g++ hello.cpp -o hello
./hello
```

## Memory Management in C++
**The keyword `new` replaces `malloc` and `delete` replaces `free`:**
``` cpp
char* s = new char[size];   // initialize an array
int* p = new int(9);        // initialize a single int

delete [] s;                // delete an array
delete p;                   // delete a single int
```

## Pointers in C/C++
**Swap in C:**
``` c
// i and j are pointers to ints
void swap(int* i, int *j)
{
	int temp = *i; // dereference i
	*i = *j;
	*j = temp;
}

// call C function
// pass addresses of a and b
swap(&a, &b);    
```

**Swap in C++:**
``` cpp
// i and j are references to ints
inline void swap(int &i, int &j)
{
  	int temp i; // no need to dereference
  	i = j;
  	j = temp;
}

// C++ supports function overloading unlike C
inline void swap(double &i, double &j)
{
  	double temp i;
  	i = j;
  	j = temp;
}

// call C++ function
// no need to pass addresses
swap(a, b);    
```

## Vectors in C++
```cpp
#include <vector>
using namespace std;

vector<int> numbers1;                   // an empty vector of ints
vector<int> numbers2(10);               // a vector of 10 ints
vector<int> numbers3(10, 2);            // a vector of 10 ints, each initialized to 2
vector<int> numbers4 {10, 20, 30, 40};  // a vector initialized with an initialization list
vector<int> myVec(numbers4);            // a vector initialized with the elements of numbers4 

int val = myVec.at(index);  // return the value of the element located at index of myVec
int* arr = myVec.data();    // return the underlying int array of myVec
myVec.push_back(50);        // create a last element (if myVec is full) and stores 50 in it
myVec.pop_back();           // remove the last element from myVec
myVec.size();               // get the number of elements in myVec
myvec.capacity();           // get the capacity of myVec
myVec.clear();              // completely clear the contents of myVec
myVec.empty();              // return true if myVec is empty
myVec.reverse();            // reverse the order of elements in myVec
myVec.resize(size, val);    // resize myVec. the new elements are initialized with val
myVec.swap(someVec);        // swap the contents of myVec with the contents of anotherVec
```

## Generics in C++
**Generic Swap in C++:**
``` cpp
template <class T>
inline void swap(T &i, T &j)
{
  	T temp i;
  	i = j;
  	j = temp;
}
    
// call C++ function
// no need to pass addresses
swap(a, b);   
```

**Generic Summation of an Array in C++:**
``` cpp
template<class T>
T sum(const T data[], int size, T s = 0)	// elements of const array can not be modified
{
	for (int i = 0; i < size; ++i)
	{
		s += data[i];
	}
}

// call the function
sum(scores, 92);		// sum = 0 by default
sum(scores, 92, 58);	// sum = 58 to begin with
```

## Operator Overloading in C++
``` cpp
// define a new enum type
typedef enum days {SUN, MON, TUE, WED, THU, FRI, SAT} days;

// overload the increment operator
inline days operator++ (days d)
{
    return static_cast<days>((static_cast<int>(d) + 1) % 7);    
}

// overload the bit shift operator
ostream& operator<< (ostream &out, const days &d)
{
    switch (d)
    {
        case SUN: out << "SUN"; break;
        case MON: out << "MON"; break;
        case TUE: out << "TUE"; break;
        case WED: out << "WED"; break;
        case THU: out << "THU"; break;
        case FRI: out << "FRI"; break;
        case SAT: out << "SAT"; break; 
    } 
}

// use the overloaded operators
int main()
{
    days d = MON, e;
    e = ++d;
    cout << d << '\t' << e << endl;
}
```

## Structs/Classes in C/C++
**Structs in C:**
``` c
typedef struct point
{
    double x;
    double y;
} point;

void addPoints(point* p1, point* p2, point* sum)
{
    sum->x = p1->x + p2->x;    
    sum->y = p1->y + p2->y;
}
```

**Classes in C++:**
``` cpp
class Point
{
    public:

        // this is the preferred constructor usage
        Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

        /**
         * This is also a valid constructor:
         * Point()
         * {
         *     this->x = 0.0;  // or x = 0.0;
         *     this->y = 0.0;  // or y = 0.0;
         * }
         */

        double getX()
        {
            return x;    
        }
        
        void setX(double v)
        {
            x = v;    
        }

        // pass the point objects by reference for efficiency
        point operator+ (point &p1, point &p2)
        {
            point sum = {p1.x + p2.x, p1.y + p2.y}
            return sum;
        }

        // pass the point object by reference for efficiency
        ostream& operator<< (ostream &out, const point &p) 
        {
            out << "( " << p.x << ", " << p.y << " )";
            return out;
        }

    private:

        double x;
        double y;
}
```

**Destructors in C++:**
``` cpp
class Node
{
    public:

        Node(int d = 0, Node* ptr = nullptr) : data(d), next(ptr) {}
 
    private:

        int data;
        Node* next;
}

class List
{
    public:

        List() : head(nullptr), cursor(nullptr) {}
        ~List();
        void prepend(int value);
        int getElement();
        void advance();
        void print();

    private:

        Node* head;
        Node* cursor;
}

List::~List()
{
    for (cursor = head; cursor != nullptr; )
    {
        cursor = head->next;
        delete head;
        head = cursor;
    }
}
```
