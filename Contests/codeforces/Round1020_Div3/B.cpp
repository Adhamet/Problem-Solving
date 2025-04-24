#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;

		if (n == x) {
			for (int i = 0; i < n; ++i) cout << i << ' ';
			cout << el;
		} else {
			for (int i = 0; i < x; ++i) cout << i << ' ';
			for (int i = x + 1; i < n; ++i) cout << i << ' ';
			cout << x << el;
		}
	}

	return 0;
}
