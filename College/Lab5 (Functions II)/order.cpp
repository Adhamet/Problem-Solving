#include <iostream>
using namespace std;

void SwapFunction(int& n1, int& n2) {
	if (n1 > n2) {
		int temp = n1;
		n1 = n2;
		n2 = temp;
	}
}

void order(int& n1, int& n2, int& n3) {
	if ((n1 > n2) && (n1 > n3)) { SwapFunction(n1, n3); }
	if ((n2 > n1) && (n2 > n3)) { SwapFunction(n2, n3); }
	if (n2 < n1) { SwapFunction(n1, n2); }
}

int main()
{
	int num1, num2, num3;
	cin >> num1 >> num2 >> num3;

	order(num1, num2, num3);
	cout << num1 << num2 << num3;
}