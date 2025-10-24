#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;	std::cin >> n >> k;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];

	std::vector<int> freq(n+1, 0);
	for (int i = 0; i < n; ++i) if (a[i] <= n) freq[a[i]]++;
	
	std::vector<int> cnt(n+1, 0);
	for (int d = 1; d <= n; ++d)
		for (int j = d; j <= n; j += d)
			cnt[d] += freq[j];

	int ans = 1;
	for (int d = n; d >= 1; d--) if (n - cnt[d] <= k) {
		ans = d;
		break;
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
