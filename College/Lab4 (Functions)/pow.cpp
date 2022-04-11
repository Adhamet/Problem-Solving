#include <iostream>
using namespace std;

int product(int x, int y)
{
	int prod = 1;
	for (int i = 0; i < y; i++)
	{
		prod *= x;
	}
	return prod;
}

int main()
{
	int x, y;
	cin >> x >> y;
	product(x, y);
	cout << x;
}