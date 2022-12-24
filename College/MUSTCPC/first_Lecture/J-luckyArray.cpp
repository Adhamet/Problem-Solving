include <iostream>
using namespace std;

int main()
{
	int n, smallest;
	cin >> n;
	int arr[1000];
	int prefix[1000]{ 0 };
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i == 0) { smallest = arr[i]; }
		else if (arr[i] < smallest) { smallest = arr[i]; }
	}
	for (int i = 0; i < n; i++) {
		if (i == 0 && arr[0] == smallest) { prefix[0] = 1; }
		else if (i > 0 && arr[i] == smallest) {
			prefix[i] = prefix[i - 1] + 1;
		}
		else if ( i != 0 ) { prefix[i] = prefix[i - 1]; }
	}
	if (prefix[n - 1] % 2 != 0) { cout << "Lucky"; }
	else cout << "Unlucky";
}