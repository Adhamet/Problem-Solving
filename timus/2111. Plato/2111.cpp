#include <bits/stdc++.h>
#include <numeric>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;	std::cin >> n;
	std::vector<i64> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	std::sort(a.begin(), a.end());
	i64 curW = std::accumulate(a.begin(), a.end(), 0), ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += (a[i] * curW);
		curW -= a[i];
		ans += (a[i] * curW);
	}
	return std::cout << ans, 0;
}
