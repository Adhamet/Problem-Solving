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
	i64 k;
	std::cin >> n >> k;

	std::vector<std::array<i64, 3>> g(n);
	for (int i = 0; i < n; ++i) std::cin >> g[i][0] >> g[i][1] >> g[i][2];

	std::vector<i64> ans(n);
	using Event = std::pair<i64, i64>;
	std::priority_queue<Event, std::vector<Event>, std::greater<Event>> pq;

	i64 in = 0, now = 0;
	for (int i = 0; i < n; ++i) {
		now = std::max(now, g[i][0]);

		while (!pq.empty() && pq.top().first <= now)
			in -= pq.top().second, pq.pop();

		while (in + g[i][2] > k) {
			auto [exit, cnt] = pq.top();
			pq.pop();

			in -= cnt;
			now = std::max(now, exit);
			while (!pq.empty() && pq.top().first <= now)
				in -= pq.top().second, pq.pop();
		}

		ans[i] = now;
		in += g[i][2];
		pq.push({now + g[i][1], g[i][2]});
	}
	
	for (int i = 0; i < n; ++i) std::cout << ans[i] << '\n';
	return 0;
}
