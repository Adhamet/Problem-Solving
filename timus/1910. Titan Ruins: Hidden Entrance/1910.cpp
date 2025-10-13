#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	i64 n;	std::cin >> n;
	std::vector<i64> a(n);
	for (i64 i = 0; i < n; ++i) std::cin >> a[i];

	i64 mdIdx = 0, mx = 0;
	for (i64 i = 0; i < n; ++i) {
		i64 cur = 0;
		if (i + 3 > n) continue;
		for (i64 j = i; j < i + 3; ++j) cur += a[j];
		if (cur > mx) {
			mdIdx = i + 1;
			mx = cur;
		}
	}
	
	std::cout << mx << ' ' << mdIdx + 1;
	return 0;
}
