#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;	std::cin >> n;
	std::vector<i64> a(n+1);
	for (int i = 1; i <= n; ++i) std::cin >> a[i];

	bool leave = true;
	for (int i = 1; i < n; ++i) {
		if ((i & 1) && a[i] >= a[i+1]) {
			leave = false;
			break;
		}
		if ((i%2==0) && a[i] <= a[i+1]) {
			leave = false;
			break;
		}
	}

	if (leave) {
		std::cout << 0 << '\n';
		return;
	}

	i64 mx = a[1];
	for (int i = 2; i <= n; ++i) {
		mx = std::max(mx, a[i]);
		if ((i%2==0) && a[i] < mx) a[i] = mx;
	}
	
	i64 ans = 0;
	for (int i = 1; i < n; ++i) {
		if (((i&1) && a[i] >= a[i+1]) || ((i%2==0) && a[i] <= a[i+1])) {
			ans += (std::abs(a[i]-a[i+1]) + 1);
			if (i&1) a[i] = a[i+1] - 1;
			else a[i+1] = a[i] - 1;
		}
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;	std::cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
