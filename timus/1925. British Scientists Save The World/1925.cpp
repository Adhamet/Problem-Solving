#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, k;	std::cin >> n >> k;
	int sbm_b_np1 = 0, sbm_g_n = 0;
	for (int i = 0; i < n; ++i) {
		int bi, gi;	std::cin >> bi >> gi;
		sbm_b_np1 += bi;
		sbm_g_n += gi;
	}
	sbm_b_np1 += k;
	int res = sbm_b_np1 - sbm_g_n - (2 * (n + 1));
	if (res < 0) std::cout << "Big Bang!";
	else std::cout << res;
	return 0;
}
