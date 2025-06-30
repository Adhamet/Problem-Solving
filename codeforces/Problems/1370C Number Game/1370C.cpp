#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

bool isPowerOfTwo(int n) {
	return (n & (n - 1)) == 0;
}

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) return false;
	return true;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		if (n == 1) cout << "FastestFinger" << el;
		else if (n == 2) cout << "Ashishgup" << el;
		else if (n % 2 == 1) cout << "Ashishgup" << el;
		else {
			if (isPowerOfTwo(n)) cout << "FastestFinger" << el;
			else if (n % 4 != 0 && isPrime(n / 2)) cout << "FastestFinger" << el;
			else cout << "Ashishgup" << el;
		}
	} return 0;
}
