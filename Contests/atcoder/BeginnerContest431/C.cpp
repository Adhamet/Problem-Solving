#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m, k; std::cin >> n >> m >> k;
	std::vector<i64> h(n), b(m);
	for (int i = 0; i < n; ++i) std::cin >> h[i];
	for (int i = 0; i < m; ++i) std::cin >> b[i];
	std::sort(h.rbegin(), h.rend());
	std::sort(b.rbegin(), b.rend());

	bool acc = true;
	int hItr = n - k, bItr = 0;
	// int cntTst=0;
	while (hItr < n && bItr < m) {
		if (h[hItr] > b[bItr]) {
			acc = false;
			break;
		}
		hItr++, bItr++;
		// cntTst++;
	}
	// std::cout << "TEST: " << cntTst << '\n';

	return std::cout << (acc? "Yes": "No") << '\n', 0;
}
