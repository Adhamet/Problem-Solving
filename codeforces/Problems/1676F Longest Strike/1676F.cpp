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
		int n, k, x;
		cin >> n >> k;
		map<int, int> occ;
		vector<int> a;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (occ[x] == 0) a.push_back(x);
			occ[x] += 1;
		}

		sort(a.begin(), a.end());

		int m = a.size(), i = 1;
		vector<int> cnt(m + 1, 0);
		cnt[0] = 0;
		for (int i = 1; i <= m; i++) {
			if (occ[a[i - 1]] >= k) {
				if (cnt[i - 1] == 0 || ((i > 1) && (a[i - 1] != a[i - 2] + 1))) cnt[i] = 1;
				else cnt[i] = cnt[i - 1] + 1;
			} else cnt[i] = 0;
		}

		int mxDiff = 0;
		int l = 0, r = 1;
		pair<int, int> ans;
		while (r < m) {
			if (cnt[l + 1] == 1 && r - l + 1 == cnt[r + 1]) {
				if (mxDiff < a[r] - a[l]) {					
					mxDiff = a[r] - a[l];
					ans = {a[l], a[r]};
				}

				r += 1;
			} else if (l + 1 < r) {
				l = r, r = l + 1;
			} else l += 1, r += 1;
		}

		if (mxDiff == 0) {
			int mxK = 0;
			for (int i = 0; i < m; i++) {
				if (mxK < occ[a[i]]) {
					mxK = occ[a[i]];
					ans = {a[i], a[i]};
				}
			}

			if (mxK < k) {
				cout << -1 << el;
				continue;
			}
		}

		cout << ans.first << " " << ans.second << el;
	}

	return 0;
}
