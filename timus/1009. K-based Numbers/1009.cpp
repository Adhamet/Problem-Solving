#include <bits/stdc++.h>

using i64 = long long;


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;
	std::cin >> n >> k;

	std::vector<i64> prevdp(k, 0), curdp(k, 0);
	for (int i = 1; i < k; ++i) prevdp[i] = 1;

	for (int pos = 1; pos < n; ++pos) {
		fill(curdp.begin(), curdp.end(), 0);

		for (int prev = 0; prev < k; ++prev) {
			if (prevdp[prev] == 0) continue;
			for (int cur = 0; cur < k; ++cur) {
				if (prev == 0 && cur == 0) continue;
				curdp[cur] += prevdp[prev];
			}
		}

		prevdp = curdp;
	}

	i64 ans = 0;
	for (int i = 0; i < k; ++i) ans += prevdp[i];
	return std::cout << ans, 0;
}
