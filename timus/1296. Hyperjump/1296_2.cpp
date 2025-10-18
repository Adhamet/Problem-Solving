
#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;	std::cin >> n;
	bool pos = false, neg = false;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		pos = pos | (a[i] > 0);
		neg = neg | (a[i] < 0);
	}

	if (n == 0) return std::cout << 0, 0;

	int tot = std::accumulate(a.begin(), a.end(), 0);
	if (pos && !neg) std::cout << tot;
	else if (!pos && neg) std::cout << 0;
	else {
		i64 cur = 0, best = 0;
		for (int i = 0; i < n; ++i) {
			cur = std::max<i64>(0, cur + a[i]);
			best = std::max(best, cur);
		}
		std::cout << best;
	}

	return 0;
}
