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
		vector<bool> exist(n + 1, false);
		for (int i = 0; i < n; ++i) cin >> a[i], exist[a[i]] = true;

		set<int> special;
		for (int l = 0; l < n; ++l) {
			int sum = 0;
			for (int r = l; r < n; ++r) {
				sum += a[r];
				if (r > l && sum <= n && exist[sum]) special.insert(sum);
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; ++i) cnt += (special.count(a[i]));
		cout << cnt << el;
	}

	return 0;
}
