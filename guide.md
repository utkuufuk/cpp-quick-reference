# C++ for C Programmers

## Sections
 * [Compiling](#compiling)
 * [Memory Management](#memory-management)
 * [Pointers](#pointers)
 * [Pass by Reference](#pass-by-reference)
 * [Vectors](#vectors)
 * [Character Functions](#character-functions)
 * [C-Strings](#c-strings)
 * [Strings](#strings)
 * [File Operations](#file-operations)
 * [Enumerated Data Types](#enumerated-data-types)
 * [Structs](#structs)
 * [Classes](#classes)
 * [Inheritence](#inheritence)
 * [Generics](#generics)

## Compiling
``` sh
# compile and run a C program
gcc hello.c -o hello
./hello

# compile and run a C++ program
g++ hello.cpp -o hello
./hello

# compile a program which uses C++11 features
g++ -std=c++11 hello.cpp -o hello
./hello
```

## Memory Management
#### The keyword `new` replaces `malloc` and `delete` replaces `free`
``` cpp
char* s = new char[size];   // dynamically allocate memory for an array
delete [] s;                // free the allocated memory
s = nullptr;                // good practice for preventing errors
```

## Pointers
#### Constant values & constant pointers
``` cpp 
// this function accepts a pointer to an array of constants
void displayPayRates(const double *rates, int size)
{
    for (int count = 0; count < size; count++)
    {
        cout << *(rates + count) << endl;
    }
}

// constant pointers can not point to something else
int value = 22;
int * const ptr = &value; 

// this is a constant pointer to a constant
int number = 15;
const int * const ptr = &number 
```

## Pass by Reference
#### Swap in C
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

#### Swap in C++
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

## Vectors
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

## Character Functions
```cpp 
#include <cctype>   // required for using the following functions
```  
#### Character testing
| Function  | Returns true if the argument is a ...; returns 0 otherwise  |
| :-------: | :---------------------------------------------------------- |
| `isalpha` | letter of the alphabet.                                     |
| `isalnum` | letter of the alphabet or a digit.                          |
| `isdigit` | digit from 0 through 9.                                     |
| `islower` | lowercase letter.                                           |
| `isprint` | printable character (including a space).                    |
| `ispunct` | printable character other than a digit, letter, or space.   |
| `isupper` | uppercase letter. Otherwise, it returns 0.                  |
| `isspace` | whitespace character. (`' '`, `' \n '`, `' \v '`, `' \t '`) |

#### Character case conversion
| Function  | Description                                       |
| :-------: | :------------------------------------------------ |
| `toupper` | Returns the uppercase equivalent of its argument. |
| `tolower` | Returns the lowercase equivalent of its argument. |

## C-Strings
### Working with c-strings
``` cpp 
#include <cstring>   // required for using the following functions
```  

#### The `strlen` function
``` cpp 
// don't confuse the length of a string with the size of the array holding it
char name[] = "Thomas Edison";
int length = strlen(name); // length is 13
```

#### The `strcat` function (see also: `strncat`)
*If the array holding the first string isn't large enough to hold both strings,
`strcat` will overflow the boundaries of the array.*
``` cpp 
char string1[100] = "Hello ";   // string1 has enough capacity for strcat 
char string2[] = "World!";
strcat(string1, string2);
cout << string1 << endl;        // outputs "Hello World!"
```

#### The `strcpy` function (see also: `strncpy`)
*`strcpy` performs no bounds checking. The array specified by the first 
argument will be overflowed if it isn’t large enough to hold the string
specified by the second argument.*
``` cpp
char name[] = "Some other string";  // size of the holding array is sufficient
strcpy(name, "Albert Einstein");
```

#### The `strstr` function
``` cpp
char arr[] = "Four score and seven years ago";
char *ptr = strstr(arr, "seven");   // search for "seven" and return address
cout << ptr << endl;                // outputs "seven years ago"
```

#### The `strcmp` function
``` cpp
int strcmp(char *string1, char *string2); // function prototype
```
The result is
 - **zero** if the two strings are **equal**.
 - **negagive** if string1 comes **before** string2 in alphabetical order.
 - **positive** if string1 comes **after** string2 in alphabetical order.

### C-string/numeric conversion functions
``` cpp 
#include <cstdlib>   // required for using the following functions

//Converts a c-string to an integer.
int intVal = atoi("1000");

//Converts a c-string to a long value.
long longVal = atol("1000000");

//Converts a c-string to a double/float value.
float floatVal = atof("12.67");
double doubleVal = atof("12.67");

// returns a numeric argument converted to a c-string object
to_string(int value);
to_string(long value);
to_string(long long value);
to_string(unsigned value);
to_string(unsigned long value);
to_string(unsigned long long value);
to_string(float value);
to_string(double value);
to_string(long double value);
```

## Strings
#### Defining `string` objects
``` cpp 
#include <string>           // required for using the string data type

string str0;                // defines an empty string

string str1 = "Hello";      // defines a string initialized with "Hello"

string str2("Greetings!");  // defines a string initialized with "Greetings!"

string str3(str2);          // defines a string which is a copy of str2.
                            // (str2 may be either a string or a c-string)

char cStr[] = "abcdefgh";   // this has to be a c-string, not a string
string str4(cStr, 5);       // defines a string which is initialized 
                            // to the first 5 characters in the c-string cStr

string str5('x', 10);       // defines a string initialized with 10 'x' chars

string str6(str5, 2, 8);    // defines a string which is initialized
                            // with a substring of str5. 
```
#### `string` operators
There is no need to use a function such as `strcmp` to compare string objects. 
You may use the `<` , `>` , `<=` , `>=` , `==` , and `!=` relational operators.

``` cpp
string s1 = "Hello ";
string s2 = "World!";
string mystring = s1 + s2;  // concatenates s1 and s2
char c = mystring[0];       // returns the char at position 0 in mystring
```
#### `string` member functions
![string functions 1](images/string_functions_1.png)
![string functions 2](images/string_functions_2.png)
![string functions 3](images/string_functions_3.png)

## File Operations
| Data Type  | Description                                                    |
| :--------: | :------------------------------------------------------------- |
| `ifstream` | Input file stream. Can be used to read data from files.        |
| `ofstream` | Output file stream. Can be used to create write data to files. |
| `fstream`  | File stream. Can be used to read and write data to/from files. |

#### `ifstream` and `ofstream`
``` cpp
#include <fstream>

// open an ifstream
ifstream inputFile;
inputFile.open("InputFile.txt");
// Alternatively: 
// ifstream inputFile("InputFile.txt");

// open an ofstream
ofstream outputFile;
outputFile.open("OutputFile.txt");
// Alternatively: 
// ofstream outputFile("OutputFile.txt");

// open ofstream in append mode
outputFile.open("OutputFile.txt", ios::out | ios::app);

inputFile >> value;
outputFile << "I love C++ programming" << endl;

inputFile.close();
outputFile.close();
```

#### `fstream`
``` cpp
#include <fstream>

fstream file;

// open fstream in output mode
file.open("DataFile.txt", ios::out);

// open fstream in both input and output modes
file.open("DataFile.txt", ios::in | ios::out);

// read and write data in binary mode
char data[4] = {'A', 'B', 'C', 'D'};
fstream file("DataFile.dat", ios::binary | ios::out);
file.write(data, sizeof(data));
file.open("DataFile.dat", ios::binary | ios::in);
file.read(data, sizeof(data));

// read and write non-char data
int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
fstream file("numbers.dat", ios::out | ios::binary);
file.write(reinterpret_cast<char *>(numbers), sizeof(numbers));
file.open("numbers.dat", ios::in | ios::binary);
file.read(reinterpret_cast<char *>(numbers), sizeof(numbers));

// close the file
file.close();
```

#### File access flags
By using different combinations of access flags, you can open files in many possible modes:
![File Access Flags](images/file-access-flags.png)

## Enumerated Data Types
``` cpp
// each enumerator is assigned an integer starting from 0
enum Day
{
    MONDAY,     // 0
    TUESDAY,    // 1
    WEDNESDAY,  // 2
    THURSDAY,   // 3
    FRIDAY      // 4
};

// assign an enumerator to an integer
int x = THURSDAY;

// can not directly assign an int to an enum variable
Day day1 = static_cast<Day>(3);         // day1 = 3 is illegal!!
Day day2 = static_cast<Day>(day1 + 1);  // day2 = day1 + 1 is illegal!!

// compare enum values
bool b = FRIDAY > MONDAY // true because FIRDAY comes after MONDAY

// anonymous enum types can be used when you don't need to define variables
enum {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY};

// can specify integer values for all or some enumerators
enum Color {RED, ORANGE, YELLOW = 9, GREEN, BLUE};
```

#### Strongly typed enumerators `(enum class)`
``` cpp
// can specify multiple enumerators with the same name, within the same scope
enum class President {MCKINLEY, ROOSEVELT, TAFT};
enum class VicePresident {ROOSEVELT, FAIRBANKS, SHERMAN};

// can not directly assign a strongly typed enum to an integer
// int x = President::MCKINLEY is illegal!!
int x = static_cast<int>(President::MCKINLEY);  

// can specify any integer data type as the underlying type
enum class Day : char {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY}; 
```

## Structs
``` cpp
// declare a struct
struct CityInfo
{
    string cityName;
    string state;
    long population;
    int distance;
};

// define a struct
CityInfo location;
CityInfo cities[20];

// initialize a struct
CityInfo location = {"Asheville", "NC", 50000, 28};
CityInfo location = {"Atlanta"};  // only cityName is initialized 
CityInfo cities[2] = {{"Asheville", "NC", 50000, 28}, 
                      {"Atlanta", "GA", 45000, 90}};

// access struct members
location.population = 4750;
cout << location.population << endl;

// declare a nested struct
struct EmployeeInfo
{
    string name;
    int employeeNumber;
    CityInfo birthPlace;
};

// access nested struct members
EmployeeInfo manager;
manager.birthPlace.population = 4750;
cout << manager.birthPlace.population << endl;
```
**Note:** *By default, structures are passed to functions by value.*<br>
**Note:** *You can return local structs defined in functions unlike arrays.*

#### Dynamically allocating structs
``` cpp
struct Circle
{
    double radius;
    double diameter;
    double area;
};

Circle* cirPtr = new Circle;
Circle* circles = new Circle[5];

// access members after dereferencing the struct pointer
cirPtr->radius = 1.1;
cirPtr->area = 2.2;

// array elements are structs, not pointers
for (int i = 0; i < 5; i++)
{
    circles[i].radius = 1.1 * i;
    circles[i].area = 2.2 * i;
}
```

## Classes
#### Class Specification 
``` cpp
// Rectangle.h

#ifndef RECTANGLE_H     // include guard prevents the header file from 
#define RECTANGLE_H     // accidentally being included more than once

class Rectangle
{
    private:

        // instance member variables
        double width;
        double length;

        // static member variable
        static int numObjects;

    public:

        Rectangle();    // default constructor (takes no arguments)

        // constructors can also be defined inline
        Rectangle(double width, double length)
        {
            this->width = width;    
            this->length = length;
            numObjects++;   // increment total number of objects in each constructor call
        }

        // this is a better constructor definition
        Rectangle(double width = 0.0, double length = 0.0) :
        width(width), length(length) {}

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
```

#### Class Implementation
``` cpp
// Rectangle.cpp

// double quotes indicate that Rectangle.h is located in the current 
// project directory; instead of the compiler's include file directory
#include "Rectangle.h"   

// the static member variable must be defined in the implementation file
int Rectangle::numObjects = 0;

Rectangle::Rectangle()
{
    width = 0.0;
    length = 0.0;
    numObjects++;   // increment total number of objects in each constructor call
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
```

#### Copy constructors and destructors
``` cpp
// ContactInfo.h

#ifndef CONTACTINFO_H
#define CONTACTINFO_H

#include <cstring> // Needed for strlen and strcpy

class ContactInfo
{
    private:

        char *name;
        char *phone;

    public:

        ContactInfo(char *n, char *p)
        { 
            // Allocate just enough memory for the name and phone number.
            name = new char[strlen(n) + 1];
            phone = new char[strlen(p) + 1];

            // Copy the name and phone number to the allocated memory.
            strcpy(name, n);
            strcpy(phone, p); 
        }

        // copy constructor (const protects the argument object against modification)
        ContactInfo(const ContactInfo &obj)
        {
            int nameSize = strlen(obj.name) + 1;
            int phoneSize = strlen(obj.phone) + 1;

            name = new char[nameSize];
            phone = new char[phoneSize];

            strcpy(name, obj.getName());
            strcpy(phone, obj.getPhoneNumber());
        }
        
        ~ContactInfo() // Destructor
        { 
            delete [] name;
            delete [] phone; 
        }

        // const prevents any code calling the function from changing the name
        const char *getName() const
        {
            return name; 
        }

        const char *getPhoneNumber() const
        {
            return phone; 
        }
};
#endif
```

#### Objects
``` cpp
// define an object from the Rectangle class (lives on stack)
Rectangle box1(12.8, 9.4);

// initialize the new object with width & length of box1 (lives on stack)
// c++ automatically creates a default copy constructor if it's not defined by programmer
Rectangle box2 = box1;  // numObjects not incremented because it's not handled in default copy constructor
box2.setWidth(4.7);     // assign a new width to box2

// call static member function
cout << "Number of objects: " << Rectangle::getNumObjects();    // Number of objects: 1

// define a pointer to a ContactInfo class object
// this object lives on the heap and should be deleted manually
ContactInfo* contactPtr = new ContactInfo("Kristen Lee", "555-2021");
contactPtr->getName();

// create a new contact and copy name & phone number from the previous one (lives on stack)
ContactInfo newContact = *contactPtr;       // our copy constructor is called here automatically
const char* newName = newContact.getName(); // same as "Kristen Lee"

// the destructor is called here automatically 
delete contactPtr;      
contactPtr = nullptr;   // good practice for preventing errors

// don't delete other objects because they live on stack and will get deleted when the calling function returns
```

## Inheritence
### Parent class declaration
``` cpp
#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

class GradedActivity
{
    protected:  // only accesible by children

        double score;

    public:

        GradedActivity()
        {
            score = 0.0; 
        }

        GradedActivity(double s)
        {
            score = s; 
        }
       
        void setScore(double s)
        {
            score = s; 
        }
       
        double getScore() const
        {
            return score; 
        }

        char getLetterGrade() const;
};
#endif
```

### Parent class implementation
``` cpp
#include "GradedActivity.h"

char GradedActivity::getLetterGrade() const
{
    char letterGrade;

    if (score > 89)
    {
        letterGrade = 'A';
    }
    else if (score > 79)
    {
        letterGrade = 'B';
    }
    else if (score > 69)
    {
        letterGrade = 'C';
    }
    else if (score > 59)
    {
        letterGrade = 'D';
    }
    else
    {
        letterGrade = 'F'
    }
    return letterGrade;
}
```

### Child class declaration
``` cpp
#ifndef FINALEXAM_H
#define FINALEXAM_H

#include "GradedActivity.h"

// the word public is the base class access specification
class FinalExam : public GradedActivity
{
    private:

        int numQuestions;
        int numMissed;

    public:
    
        FinalExam()
        {
            numQuestions = 0;
            numMissed = 0; 
        }
       
        FinalExam(int questions, int missed)
        {
            set(questions, missed); 
        }
       
        void set(int, int);
        
        double getNumQuestions() const
        {
            return numQuestions; 
        }

        int getNumMissed() const
        {
            return numMissed; 
        }
};
#endif
```

### Child class implementation
``` cpp
#include "FinalExam.h"

void FinalExam::set(int questions, int missed)
{
    numQuestions = questions;
    numMissed = missed;
    double pointsEach = 100.0 / numQuestions;
    double numericScore = 100.0 - (missed * pointsEach);
  
    // call parent function 
    setScore(numericScore);
}
```

### Base class access specification
![BCAS](images/base-class-access-specification.png)
**NOTE:** If the base class access specification is left out of a declaration, the default access specification is `private.`

## Generics
#### Generic Swap in C++
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

#### Generic summation of an array in C++
``` cpp
template<class T>
T sum(const T data[], int size, T s = 0)    // elements of const array can not be modified
{
    for (int i = 0; i < size; ++i)
    {
        s += data[i];
    }
}

// call the function
sum(scores, 92);        // sum = 0 by default
sum(scores, 92, 58);    // sum = 58 to begin with
```
