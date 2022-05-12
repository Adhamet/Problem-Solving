#include <iostream>
using namespace std;
 
int main()
{
	int smallest, smaller, other;
	int n;
	cin >> n;
 
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
 
	smallest = arr[0];
	other = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (smallest > arr[i])
			smallest = arr[i];
		if (other < arr[i])
			other = arr[i];
	}
 
	smaller = other;
	for (int i = 0; i < n; i++)
		if (smaller > arr[i] && arr[i] > smallest)
				smaller = arr[i];
 
	if (smaller == smallest) cout << "NO";
	else cout << smaller;
}