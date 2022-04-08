#include <iostream>
#include <string>
using namespace std;

struct frac {
	float numerator, denominator;
}num1, num2;

int main()
{
	cout << "Enter fraction 1(numerator denominator): ", cin >> num1.numerator >> num1.denominator;
	cout << "Enter fraction 2(numerator denominator): ", cin >> num2.numerator >> num2.denominator;
	float result = ((num1.numerator / num1.denominator) + (num2.numerator / num2.denominator));
	cout << result;
}