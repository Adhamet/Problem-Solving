#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];

	int ans = 0;
	for (int l = 0; l < n; ++l) {
		int cursm = 0;
		for (int r = l; r < n; ++r) {
			cursm += a[r];
			ans = std::max(ans, cursm / (r - l + 1));
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
