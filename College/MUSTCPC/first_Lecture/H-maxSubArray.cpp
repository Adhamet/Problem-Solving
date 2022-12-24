#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int j = 1, incN = n, decN = n, idx = n, maximum = ((n * (n + 1)) / 2);
		int* arr = new int[maximum+1];

		for (int i = 0; i < n; i++) { cin >> arr[i]; }
		while (idx < maximum)
		{
			while (j < incN) {
				arr[idx] = max(arr[j], arr[j - 1]);
				j++;
				idx++;
			}
			j++;
			incN += (--decN);
		}

		sort(arr, arr + maximum);
		for (int i = 0; i < maximum; i++) { cout << arr[i] << " "; }
	}
}