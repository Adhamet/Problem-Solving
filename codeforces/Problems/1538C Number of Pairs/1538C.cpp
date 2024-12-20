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
		int n, l, r;
		cin >> n >> l >> r;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		sort(a.begin(), a.end());

		int ans = 0;
		for (int i = 0; i < n; i++) { // l <= a[i] + a[j] <= r
			// we are finding the smallest j such that the condition is satisfied
			// and the furthest j such that the condition is satisfied (left,right)
			// which means all the indices between j1 and j2 also satisfy the condition
			int left = upper_bound(a.begin() + i + 1, a.end(), l - a[i] - 1) - a.begin();
			int right = upper_bound(a.begin() + i + 1, a.end(), r - a[i]) - a.begin();
			ans += right - left;
		}

		cout << ans << el;
	}

	return 0;
}	
