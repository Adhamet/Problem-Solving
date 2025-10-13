#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;	std::cin >> n;
	std::vector<std::array<int,2>> v;

	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];

	int i = 0;
	while (i < n) {
		int j = i, cnt = 0;
		while (a[j] == a[i]) cnt += 1, j++;
		v.push_back({cnt, a[i]});
		i = (i == j? i + 1: j);
	}

	for (auto x: v) std::cout << x[0] << ' ' << x[1] << ' ';
	return 0;
}
