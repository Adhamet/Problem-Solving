#include <iostream>
using namespace std;

void init(int arr[], int size) {
	for (int i = 0; i < size; i++)
		cin >> arr[i];
}

bool equality(int arr1[], int arr2[], int size) {
	for (int i = 0; i < size; i++)
		if (arr1[i] != arr2[i])
			return false;
	return true;
}

int main()
{
	int firstArr[5], secArr[5];
	init(firstArr, 5); init(secArr, 5);
	if (equality(firstArr, secArr, 5))
		return cout << "Result: " << "Not Equal", 0;
	cout << "Equal";
}