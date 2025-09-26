#include <bits/stdc++.h>
using i64 = long long;

void solve() {
	int n; std::cin >> n;
	std::string s; std::cin >> s;

	std::vector<int> As, Bs;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') As.push_back(i);
		else Bs.push_back(i);
	}

	auto calc = [&](std::vector<int>& Ch) -> i64 {
		int m = (int)Ch.size(), md = m / 2;
		i64 cur = 0;
		for (int i = 0; i < m; i++)
			cur += std::abs(Ch[i] - (Ch[md] + (i - md)));
		return cur;
	};

	if (As.empty() || Bs.empty()) {
		std::cout << 0 << '\n';
		return;
	}

	std::cout << std::min(calc(As), calc(Bs)) << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t; std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}


