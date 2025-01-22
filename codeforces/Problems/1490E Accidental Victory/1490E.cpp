#include <algorithm>
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
		vector<array<int, 2>> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i][0], a[i][1] = i;
		sort(a.begin(), a.end());

		auto can = [&](int idx) -> bool {
			int sum = a[idx][0];
			for (int i = 0; i < idx; ++i) sum += a[i][0];
			for (int i = idx + 1; i < n && sum >= a[i][0]; ++i) sum += a[i][0];
			return sum >= a[n - 1][0];
		};

		int l = 0, r = n - 1, ans = n;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (can(mid)) ans = mid, r = mid - 1;
			else l = mid + 1;
		}

		vector<int> res;
		for (int i = ans; i < n; ++i) res.push_back(a[i][1] + 1);
		sort(res.begin(), res.end());

		cout << n - ans << el;
		for (auto idx: res) cout << idx << ' ';
		cout << el;
	}

	return 0;
}
