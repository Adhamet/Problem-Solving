#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;	std::cin >> n;
	std::set<int> prof;
	for (int i = 0; i < n; ++i) {
		int x;	std::cin >> x;
		prof.insert(x);
	}

	int ans = 0;
	int m;	std::cin >> m;
	for (int i = 0; i < m; ++i) {
		int x;	std::cin >> x;
		if (prof.find(x) != prof.end()) ans += 1;
	}
	
	return std::cout << ans, 0;
}
