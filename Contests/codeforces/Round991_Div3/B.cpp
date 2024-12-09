#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, tot = 0;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i], tot += a[i];

		if (tot % n != 0) cout << "NO" << el;
		else {
			int mid = tot / n;
			for (int i = 1; i < n - 1; i++) {
				int diff = mid - a[i - 1];
				a[i - 1] += diff, a[i + 1] -= diff;
			}

			bool ok = true;
			for (int i = 1; i < n; i++) {
				if (a[i] != a[0]) {
					ok = false;
					break;
				}
			}

			cout << (ok? "YES": "NO") << el;
		}
	}

	return 0;
}
