#include <iostream>

class MyMathClass
{
private:

	int counter;

	// LogAction function, only available for within the class
	void LogAction(std::string msg)
	{
		counter++;
		std::cout << msg << std::endl;
	}

public:
	MyMathClass()
	{
		counter = 0;
	}

	// Getter fuction for the counter, available publically
	int getActionCount()
	{
		return counter;
	}

	// Addition function, available publically
	int add(int val1, int val2)
	{
		int value = val1 + val2;
		LogAction("Adding " + std::to_string(val1) + " and " + std::to_string(val2) + " is " + std::to_string(value));
		return value;
	}

	// Subtraction function, available publically
	int sub(int val1, int val2)
	{
		int value = val1 - val2;
		LogAction("Subtracting " + std::to_string(val1) + " and " + std::to_string(val2) + " is " + std::to_string(value));
		return value;
	}
};

/// Globally available function
void output(std::string msg)
{
	std::cout << msg << std::endl;
}

bool isEmpty(std::string str)
{
	return str == "";
}

int main()
{
	output("Starting...");

	if (isEmpty(""))
	{
		output("It's Empty!");
	}
	else
	{
		output("Not Empty!");
	}

	MyMathClass myClass = MyMathClass();

	myClass.add(3, 5);
	myClass.add(1, 6);
	myClass.add(192, 243);
	myClass.sub(543, 1235);
	myClass.sub(53, 12);

	output(std::to_string(myClass.getActionCount()));

	output("Goodbye");
}