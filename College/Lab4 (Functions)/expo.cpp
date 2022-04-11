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

int fact(int& num)
{
	int temp = 1;
	for (int i = num; i > 1; i--)
	{
		temp *= i;
	}
	return temp;
}

float expo(int x, int n)
{
	float result = 0;
	for (int i = 0; i <= n; i++)
	{
		result += (1.0*product(x, i)) / fact(i);
	}
	return result;
}

int main()
{
	int x, y;
	cin >> x >> y;
	cout << expo(x, y);
}