#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

bool isPrime(int x) {
	bool isP = true;
	if (x <= 1) isP = false;

	for (int i = 2; i <= sqrt(x); ++i) {
		if (x % i == 0) {
			isP = false;
			break;
		}
	}

	return isP;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int x, k;
		cin >> x >> k;

		if (x == 1 && k == 2) {
			cout << "YES" << el;
			continue;
		}

		if (k != 1) {
			cout << "NO" << el;
			continue;
		} 

		if (isPrime(x)) {
			cout << "YES" << el;
		} else cout << "NO" << el;
	}

	return 0;
}
