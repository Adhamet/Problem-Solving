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
		using vi = std::vector<int>;
		vi od, ev;
		for (int i = 1; i <= n; ++i) {
			if (i % 2) od.push_back(i);
			else ev.push_back(i);
		}

		vi ans(2 * n + 1, 0);
		int idx = 1;
		while (!ev.empty()) {
			int x = ev.back();
			ev.pop_back();

			ans[idx] = ans[idx+x] = x;
			idx += 1;
		}

		while (od.back() != 1) {
			while (idx < 2 * n + 1 && ans[idx]) idx++;
			int x = od.back();
			od.pop_back();

			/*fprintf(stderr, "TEST: %d\n", x);*/
			ans[idx] = ans[idx+x] = x;
			idx += 1;
		}

		for (int i = 1; i <= 2 * n; ++i) if (ans[i] == 0)
			ans[i] = 1;
	
		for (int i = 1; i <= 2 * n; ++i) std::cout << ans[i] << ' ';
		std::cout << '\n';
	}
	
	return 0;
}
