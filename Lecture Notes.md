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
swap(&a, &b);    // pass addresses of a and b
```

**Swap in C++:**
``` cpp
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
```

## Generics in C++
**Generic Swap in C++:**
``` cpp
template <class T>
inline void swap(T& i, T& j)
{
  	T temp i;
  	i = j;
  	j = temp;
}
    
// call C++ function
swap(a, b);    // no need to pass addresses
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
