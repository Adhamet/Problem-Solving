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
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		int x;
		cin >> x;

		int prevMax = -1e18;
		bool acc = true;
		for (int i = 0; i < n; ++i) {
			int org = a[i], flip = x - a[i];

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
