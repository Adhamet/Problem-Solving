#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n;
	while (std::cin >> n && n) {
		std::vector<int> a(n + 1);
		a[0] = 0, a[1] = 1;

		int idx = 1, mx = 1;
		while (2*idx+1 <= n) {
			a[2*idx] = a[idx];
			a[2*idx+1] = a[idx] + a[idx + 1];
			mx = std::max({mx, a[2*idx], a[2*idx+1]});
			++idx;
		}
		if (2*idx <= n) a[2*idx] = a[idx], mx = std::max(mx, a[idx]);

		std::cout << mx << '\n';
	}
	
	return 0;
}

