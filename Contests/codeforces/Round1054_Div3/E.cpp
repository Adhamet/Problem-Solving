#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k, l, r; std::cin >> n >> k >> l >> r;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];

	std::unordered_map<int,int> mp1, mp2;
	int p = 0, bp = 0;
	int distinctP = 0, distinctBP = 0;
	i64 ans = 0;

	for (int rr = 0; rr < n; ++rr) {
		if (++mp1[a[rr]] == 1) ++distinctP;
		if (++mp2[a[rr]] == 1) ++distinctBP;

		while (distinctP > k) {
			if (--mp1[a[p]] == 0) --distinctP;
			++p;
		}
		while (distinctBP > k - 1) {
			if (--mp2[a[bp]] == 0) --distinctBP;
			++bp;
		}

		int forK = p, forBK = bp - 1;
		int forL = std::max(0, rr - r + 1);
		int forBL = std::min(rr - l + 1, rr);

		int lll = std::max(forK, forL);
		int rrr = std::min(forBK, forBL);
		if (lll <= rrr) ans += (rrr - lll + 1);
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t; std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}

