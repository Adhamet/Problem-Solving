#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;	std::cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) std::cin >> a[i];

	std::vector<int> b;
	b.push_back(std::max(a[0], a[n-1]));
	for (int i = 0; i < n - 1; ++i) b.push_back(std::max(a[i], a[i+1]));
	std::sort(b.begin(), b.end());
	std::cout << std::accumulate(b.begin(),b.end(),0LL) - b.back() << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;	std::cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
