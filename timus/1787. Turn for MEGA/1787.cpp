#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int k, n;
	std::cin >> k >> n;
	int excess = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		if (x == k) x-=k;
		else if (x < k) {
			int tmpK = k - x;
			excess = std::max(0, excess - tmpK);
		} else if (x > k) {
			x-=k;
			excess += x;
		}
	}
	
	return std::cout << excess, 0;
}
