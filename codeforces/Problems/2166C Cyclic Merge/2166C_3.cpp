#include <bits/stdc++.h>

using i64 = long long;
template<typename T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

void solve() {
	int n;	std::cin >> n;
	i64 a[n];
	for (int i = 0; i < n; ++i) std::cin >> a[i];

	auto nxt = [&](int i) { return (i + 1 == n? 0: i + 1); };
	auto prv = [&](int i) { return (i - 1 == -1? n - 1: i - 1); };

	MinHeap<std::array<i64,3>> pq;
	auto add = [&](int i, int j) {
		pq.push({std::max(a[i],a[j]), i, j});
	};

	for (int i = 0; i < n; ++i) {
		add(prv(i), i);
		add(i, nxt(i));
	}

	i64 cnt = n-1, ans = 0;
	std::map<std::array<i64,2>, bool> mark;
	while (cnt--) {
		std::array<i64, 3> cur;
		do {
			cur = pq.top(), pq.pop();
		} while (mark[{cur[1], cur[2]}]);

		auto [cost, i, j] = cur;
		ans += cost;
		a[i] = a[j] = cost;
		mark[{i, j}] = true;

		if (i > j) std::swap(i, j);
		add(prv(i), i);
		add(j, nxt(j));
		add(i, nxt(i));
		add(prv(j), j);
	}

	std::cout << ans << '\n';
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
