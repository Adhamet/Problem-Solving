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
		int n;
		i64 m;	std::cin >> n >> m;
		std::vector<std::pair<int,int>> req(n + 1);
		req[0] = {0,0};
		for (int i = 1; i <= n; ++i)
			std::cin >> req[i].first >> req[i].second;

		i64 ans = 0;
		for (int i = 1; i <= n; ++i) {
			i64 diff = req[i].first - req[i - 1].first;
			int me = req[i - 1].second, him = req[i].second;
			if ((diff % 2) == 0 && ((me ^ him) % 2) == 0) ans += diff;
			else if ((diff % 2) && ((me ^ him) % 2)) ans += diff;
			else ans += diff - 1;
		}

		i64 diff = m - req[n].first;
		ans += diff;
		std::cout << ans << '\n';
	}
	
	return 0;
}
