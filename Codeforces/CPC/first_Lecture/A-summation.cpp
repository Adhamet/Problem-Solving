#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	int* preSum = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	preSum[0] = arr[0];
	for (int i = 1; i < n; i++)
		preSum[i] = preSum[i-1] + arr[i];
	cout << abs(preSum[n - 1]);
}