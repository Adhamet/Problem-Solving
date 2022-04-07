#include <iostream>
using namespace std;

int main()
{
	int n, minimum, maximum, minIndex = 0, maxIndex = 0;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i == 0) {
			minimum = arr[i];
			maximum = arr[i];
		}
		else if (arr[i] > maximum) {
			maximum = arr[i];
			maxIndex = i;
		}
		else if (arr[i] < minimum) {
			minimum = arr[i];
			minIndex = i;
		}
	}
	arr[maxIndex] = minimum;
	arr[minIndex] = maximum;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}