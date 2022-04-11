#include <iostream>
using namespace std;

int fact(int& num)
{
	int temp = 1;
	for (int i = num; i > 1; i--)
	{
		temp *= i;
	}
	return temp;
}


int main()
{
	int x;
	cin >> x;
	fact(x);
	cout << x;
}