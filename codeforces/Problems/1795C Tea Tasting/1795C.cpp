#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<i64> teas(n), tasters(n);
		for (int i = 0; i < n; ++i) cin >> teas[i];
		for (int i = 0; i < n; ++i) cin >> tasters[i];

		vector<i64> pref(n+1, 0), diff(n+1, 0);
		for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + tasters[i - 1];

		vector<i64> res(n, 0);
		for (int i = 0; i < n; ++i) {
			i64 target = pref[i] + teas[i];
			int j = int(upper_bound(pref.begin(), pref.end(), target) - pref.begin()) - 1;
			diff[i] += 1, diff[j] -= 1;
			if (j < n) res[j] += target - pref[j];
		}

		for (int i = 1; i < n; ++i) diff[i] += diff[i - 1];
		for (int i = 0; i < n; ++i) res[i] = res[i] + (diff[i] * tasters[i]);

		for (auto &x: res) cout << x << ' ';
		cout << '\n';
	}

	return 0;
}

