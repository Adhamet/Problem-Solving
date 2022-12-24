#include <iostream>
#define ll long long
using namespace std;

int main()
{
	int n;
	cin >> n;
	ll* arr = new ll[n];
	arr[0] = 0;
	if (n > 1) { arr[1] = 1; }

	for (int i = 2; i < n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	cout << arr[n - 1];
}