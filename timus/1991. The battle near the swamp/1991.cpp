#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, k;	std::cin >> n >> k;
	int totBoomBooms = 0, totSurvived = 0;
	for (int i = 0; i < n; ++i) {
		int x;	std::cin >> x;
		totBoomBooms += std::max(0, x - k);
		totSurvived += std::max(0, k - x);
	}
	
	return std::cout << totBoomBooms << ' ' << totSurvived, 0;
}
