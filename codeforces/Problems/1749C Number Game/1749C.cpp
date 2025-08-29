#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'
#define debug(...)
/*#define debug(...) cerr << __VA_ARGS__ << el;*/

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		auto can = [&](vector<int> v, int k) {
			sort(v.begin(), v.end());
			for (int i = 0; i < k; ++i) {
				int cur = k - i;
				auto it = upper_bound(v.begin(), v.end(), cur);
				if (it == v.begin()) return false;
				v.erase(it - 1);
				if (!v.empty()) {
					v[0] += cur;
					sort(v.begin(), v.end());
				}
			}
			return true;
		};

		int l = 0, r = n, ans = 0;
		while (l <= r) {
			int md = (l + r) >> 1;
			if (can(a, md)) ans = md, l = md + 1;
			else r = md - 1;
		}

		cout << ans << el;
	}

	return 0;
}
