#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define int i64
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int mxK = 0;
		for (int i = 1; i <= n / 2; ++i) {
			mxK += 2 * (n - 2 * i + 1);
		}

		if (k > mxK || (mxK - k) % 2 != 0) {
			cout << "No" << el;
			continue;
		}

		vector<int> p(n);
		iota(p.begin(), p.end(), 1);
		int rem = k;
		for (int i = 0; i < n / 2 && rem > 0; ++i) {
			int d = min(rem / 2, (n - 2 * i - 1));
			if (d > 0) {
				swap(p[i], p[i + d]);
				rem -= 2 * d;
			}
		}
		if (rem == 0) {
			cout << "Yes" << el;
			for (int i = 0; i < n; ++i) {
				cout << p[i];
				if (i + 1 == n) cout << el;
				else cout << ' ';
			}
		} else cout << "No" << el;
	}

	return 0;
}

