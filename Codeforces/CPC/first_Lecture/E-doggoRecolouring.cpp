#include <iostream>
#include <string>
using namespace std;

int main()
{
	int pups;
	string input;
	cin >> pups >> input;
	int colours[26]{ 0 };

	for (int i = 0; i < pups; i++) {
		colours[(input[i] - 97)]++;
	}
	for (int i = 0; i < 26; i++) {
		if (colours[i] >= 2) { return cout << "YES", 0; }
	}
	cout << "NO";
}