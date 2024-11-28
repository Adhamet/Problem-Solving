#include <bits/stdc++.h>
int main() {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0);
	int n, d;
	std::cin >> n >> d;
	std::vector<std::pair<int, int>> friends(n);
	for (auto &i: friends) std::cin >> i.first >> i.second;

	std::sort(friends.begin(), friends.end());

	long long ans = 0, maxAns = 0;
	int l = 0, r = 0;
	while (r < n) {
		ans += friends[r].second;
		while (friends[r].first - friends[l].first >= d) {
			ans -= friends[l].second;
			l += 1;
		}

		r += 1;
		maxAns = std::max(maxAns, ans);
	}

	return std::cout << maxAns, 0;
}
