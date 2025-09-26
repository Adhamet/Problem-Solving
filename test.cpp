#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;	std::cin >> n;
	std::vector<int> f(n + 1, 0);
	for (int i = 1; i <= n; ++i) std::cin >> f[i];

	int mx = n;
	while (mx > 0 && f[mx] == 0) mx--;
	if (f[mx] == 1) {
		return void(std::cout << -1 << '\n');
	}

	f[1] -= n;

	int p = 0;
	std::vector<int> ans(n, 1);
	for (int i = 1; i <= n; ++i) {
		while (f[i] > 0) {
			ans[p] = i;
			f[i]--;
			p++;
		}
	}

	ans[n - 1] = 1;
	for (int i = 0; i < n; ++i) std::cout << ans[i] << ' ';
	std::cout << '\n';
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
