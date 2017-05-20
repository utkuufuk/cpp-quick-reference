#include <iostream>
#include <vector>

using namespace std;

const int N = 40;

template <class Summable>
inline void sum(Summable& p, Summable n, vector<Summable> d)
{
	p = 0;

	for (Summable i = 0; i < n; ++i)
	{
		p = p + d[i];	
	}
}

int main()
{
	int accum = 0;
    vector<int> data(N);

	for (int i = 0; i < N; ++i)
	{
		data[i] = i;
	}	
	sum(accum, N, data);
	cout << "sum is " << accum << endl;
}
