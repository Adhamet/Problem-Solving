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
		std::vector<i64> e, o;
		for (int i = 0; i < n; ++i) {
			int x;	std::cin >> x;
			if (x % 2) o.push_back(x);
			else e.push_back(x);
		}

		if (o.empty()) {
			std::cout << 0 << '\n';
		} else {
			sort(o.rbegin(), o.rend());
			int k = (int)o.size();
			i64 sm = accumulate(e.begin(), e.end(), i64(0));
			for (int i = 0; i < (k + 1) / 2; ++i) sm += o[i];
			std::cout << sm << '\n';
		}
	}
	
	return 0;
}
