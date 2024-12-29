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
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		if (a[0] < b[0]) {
			cout << 0 << el;
			continue;
		}

		int ans = 0;
		for (int i = 0; i < n; i++) if (a[i] < b[0]) {
			ans = i;
			break;
		}

		for (int i = 0; i < n; i++) if (b[i] > a[0]) {
			ans = min(ans, i);
			break;
		}

		int mn = INT_MAX, mx = 0, mnIdx = n - 1, mxIdx = n - 1;
		for (int i = 0; i < n; i++) {
			if (mn > a[i]) mn = a[i], mnIdx = i;
			if (mx < b[i]) mx = b[i], mxIdx = i;
			if (mn < mx) {
				ans = min(ans, mnIdx + mxIdx);
				break;
			}
		}

		cout << ans << el;
	}

	return 0;
}
