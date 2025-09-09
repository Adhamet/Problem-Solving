#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n, x;	cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		int idx = -1, diff = abs(a[0] - x);
		for (int i = 0; i < n; ++i) {
			if (i > 0 && i < n - 1) {
				int lhs = abs(a[i] - 1) + abs(a[i+1] - x);
				if (lhs < diff) idx = i, diff = lhs;
			}
		}

		if (abs(a[n - 1] - 1) < diff) idx = n - 1;
		vector<int> b;
		if (idx == -1)
			for (int j = 1; j <= x; ++j)
				b.push_back(j);
		for (int i = 0; i < n; ++i) {
			b.push_back(a[i]);
			if (i == idx)
				for (int j = 1; j <= x; ++j)
					b.push_back(j);	
		}

		int ans = 0;
		for (int i = 1; i < (int)b.size(); ++i)
			ans += abs(b[i] - b[i - 1]);
		for (auto &x: b) cerr << x << ' ';
		cerr << '\n';
		cout << ans << '\n';
	}

	return 0;
}
