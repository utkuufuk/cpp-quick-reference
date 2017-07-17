# Basic Comparison 
#### read the [guide](guide.md) for more

## Contents
 * [Compiling](#compiling)
 * [Memory Management](guide.md#memory-management)
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


## C
``` c
#include  <stdio.h>
#include  <stdlib.h>
#include  <time.h>

#define SIDES 6
#define R_SIDE (rand() % SIDES + 1)

int main()
{
    const int n_dice = 2;
    int j, trials, d1, d2;
    int *outcomes;

    srand(clock());
    printf("\nEnter number of trials:");
    scanf("%d", &trials);
    
    for (j = 0; j < trials; ++j)
    {
        outcomes[(d1 = R_SIDE) + (d2 = R_SIDE)]++;  
    }
    printf("probability\n");

    for (j = 2; j < n_dice * SIDES + 1; ++j)
    {
        printf("j = %d p = %lf\n", j, (double) (outcomes[j] / trials)); 
    }
}
```

## C++
``` cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int sides = 6;    // more type-safe than #define

inline int r_sides()    // more type-safe than #define
{
    return (rand() % sides + 1);
}

int main(void)
{
    const int n_dice = 2;
    int d1, d2;

    srand(clock());
    cout << "\nEnter number of trials:";
    
    int trials;     // interleaved declaration
    cin >> trials;  // cin is typesafe unlike scanf

    int *outcomes = new int[n_dice * sides + 1];    // keyword new replaces malloc()

    for (int j = 0; j < trials; ++j)                // allows local declarations 
    {
        outcomes[(d1 = r_sides()) + (d2 = r_sides())]++;    
    }
    cout << "probability" << endl;

    for (int j = 2; j < n_dice * sides + 1; ++j)
    {
        cout << "j=" << j << " p=" 
             << static_cast<double>(outcomes[j] / trials)   // safer type conversion
             << endl;                                       // io manipulator: ends line
    }
}
```
