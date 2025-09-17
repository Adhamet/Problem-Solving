#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int t;	std::cin >> t;
	while (t--) {
		int n;	std::cin >> n;
		std::vector<int> a(n);
		for (int i = 0; i < n; ++i) std::cin >> a[i];
		std::sort(a.rbegin(), a.rend());

		int mx = INT_MIN, accu = 0;
		while (!a.empty()) {
			a.back() -= accu;
			mx = std::max(mx, a.back());
			accu += a.back();
			a.pop_back();
		}

		std::cout << mx << '\n';
	}

	return 0;
}
