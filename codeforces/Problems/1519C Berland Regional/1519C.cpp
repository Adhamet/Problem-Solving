#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tc;	cin >> tc;
	while (tc--) {
		int n;	cin >> n;
		vector<i64> uni(n);
		vector<vector<i64>> students(n);
		for (int i = 0; i < n; ++i) cin >> uni[i];
		for (int i = 0, x; i < n; ++i) {
			cin >> x;
			students[uni[i] - 1].push_back(x);
		}

		vector<vector<i64>> pref(n);
		for (int i = 0; i < n; ++i) {
			if (students[i].empty()) continue;
			auto &v = students[i];
			sort(v.rbegin(), v.rend());
			pref[i].resize((int)v.size());
			pref[i][0] = v[0];
			for (int j = 1; j < (int)v.size(); ++j)
				pref[i][j] = pref[i][j - 1] + v[j];
		}

		vector<i64> ans(n + 1);
		for (int i = 0; i < n; ++i) {
			int sz = (int)students[i].size();
			for (int k = 1; k <= sz; ++k) {
				int rem = (sz - (sz % k));
				if (rem > 0) ans[k] += pref[i][rem - 1];
			}
		}
	
		for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
		cout << el;
	}

	return 0;
}
