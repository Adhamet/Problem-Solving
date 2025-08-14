#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'
#define debug(...)
/*#define debug(...) cerr << __VA_ARGS__ << ' ';*/

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		unordered_set<i64> in;
		vector<i64> a;
		for (int i = 0; i < n; ++i) {
			i64 x;	cin >> x;
			if (!in.count(x)) a.push_back(x), in.insert(x);
		}

		int m = (int)a.size();
		sort(a.begin(), a.end());
		/*for (auto &x: a) debug(x); cout << el;*/
		
		if (m < 2) {
			cout << 0 << el;
			continue;
		}

		i64 ans = (a[m-1] - a[0]) + max(a[1] - a[0], a[m-1] - a[m-2]);
		for (int j = 2; j < m; ++j)
			ans = max(ans, (a[j] - a[j - 1]) + (a[j] - a[0]));
		for (int j = 0; j <= m - 3; ++j)
			ans = max(ans, (a[j + 1] - a[j]) + (a[m - 1] - a[j]));
		cout << ans << el;
	}

	return 0;
}
