#include <bits/stdc++.h>

using i64 = long long;

const int MXN = 6e5+5;
i64 x[MXN];

void solve() {
	int n;	std::cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	i64 prf[n];	prf[0] = a[0];
	for (int i = 1; i < n; ++i) prf[i] = prf[i - 1] + a[i];
	i64 tot = prf[n-1];

	i64 gain = 0, cur = 0;
	for (int i = 0; i < n; ++i) {
		i64 b = x[i] - a[i];
		cur = std::max(0LL, cur + b);
		gain = std::max(gain, cur);
	}

	i64 ans = tot + gain;

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	for (int i = 0, l = 1, r = 1; i < MXN; ++i, r++) x[i] = (r + l) * (r - l + 1);
	// for (int i = 0; i < 200; ++i) std::cout << x[i] << ' ';
	int t = 0;	std::cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}

