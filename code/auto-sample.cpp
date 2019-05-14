#include <iostream>

double getValue()    // This works
// int getValue()    // This doesn't work
{
	return 0.1;
}

int main()
{
	auto myValue = getValue();
	auto myCalculation = 1235 / myValue;

	std::cout << myValue << std::endl;
	std::cout << myCalculation << std::endl;
}