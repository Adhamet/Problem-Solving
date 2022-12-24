#include <iostream>
#include <string>
using namespace std;

int main()
{
	int digits, sum = 0;
	string input;
	cin >> digits >> input;
	for (int i = 0; i < digits; i++) {
		int j = (int)input[i] - 48;
		sum += j;
	}
	cout << sum;
}