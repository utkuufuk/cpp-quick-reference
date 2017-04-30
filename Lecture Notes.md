# C++

**Compile and run a C program using terminal:**

    gcc hello.c -o hello
    ./hello
    
**Compile and run a C++ program using terminal:**

    g++ hello.cpp -o hello
    ./hello
    
**Swap in C:**

    // i and j are pointers to ints
    void swap(int* i, int *j)
    {
      int temp = *i; // dereference i
      *i = *j;
      *j = temp;
    }
    
    // call C function
    swap(&a, &b);    // pass addresses of a and b
    
**Swap in C++:**

    // i and j are references to ints
    inline void swap(int& i, int& j)
    {
      int temp i; // no need to dereference
      i = j;
      j = temp;
    }
    
    // C++ supports function overloading unlike C
    inline void swap(double& i, double& j)
    {
      double temp i;
      i = j;
      j = temp;
    }
    
    // call C++ function
    swap(a, b);    // no need to pass addresses