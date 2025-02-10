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
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < m; ++i) cin >> b[i];
		sort(b.begin(), b.end());

		bool acc = true;

		int prevMax = -1e18;
		for (int i = 0; i < n; ++i) {
			int org = a[i], flip = 1e18;

			// b[j] - a[i] >= prevMax
			auto it = lower_bound(b.begin(), b.end(), prevMax + a[i]);
			if (it != b.end()) {
				flip = (*it - a[i]);
			}

			int mnValid = 1e18;
			if (org >= prevMax) mnValid = min(mnValid, org);
			if (flip >= prevMax) mnValid = min(mnValid, flip);

			if (mnValid == 1e18) {
				acc = false;
				break;
			}

			prevMax = mnValid;
		}
	
		cout << (acc? "YES": "NO") << el;
	}

	return 0;
}

