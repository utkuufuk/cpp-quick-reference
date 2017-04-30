#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// more type-safe than #define
const int sides = 6;

// more type-safe than #define
inline int r_sides()
{
	return (rand() % sides + 1);
}

int main(void)
{
	const int n_dice = 2;
	int d1, d2;

	srand(clock());
	cout << "\nEnter number of trials:";
	
	int trials;	// interleaved declaration
	cin >> trials;	// cin is typesafe unlike scanf()

	// keyword new replaces malloc()
	int *outcomes = new int[n_dice * sides + 1];	

	// allows local declarations 
	for (int j = 0; j < trials; ++j)
	{
		outcomes[(d1 = r_sides()) + (d2 = r_sides())]++;	
	}
	cout << "probability" << endl;

	for (int j = 2; j < n_dice * sides + 1; ++j)
	{
		cout << "j=" << j << " p=" 
		     << static_cast<double>(outcomes[j] / trials) // safe conversion
		     << endl;	// io manipulator: skips to the next line
	}
}
