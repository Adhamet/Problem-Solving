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
		std::vector<i64> pref(n);
		pref[0] = a[0];
		for (int i = 1; i < n; ++i) pref[i] = pref[i - 1] + a[i];

		i64 mnPref = 0, best = LLONG_MIN;
		for (int j = 0; j < n; ++j) {
			best = std::max(best, pref[j] - mnPref);
			mnPref = std::min(mnPref, pref[j]);
		}

		best = std::max(best, (i64)0);
		std::cout << best;
	}

	return 0;
}
