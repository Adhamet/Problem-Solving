#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	i64 x;	std::cin >> x;	
	int n;	std::cin >> n;
	i64 a[n];
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	std::vector<bool> in(n, false);
	
	int q; std::cin >> q;
	while (q--) {
		int idx;
		std::cin >> idx; --idx;
		if (in[idx]) x -= a[idx], in[idx] = false;
		else x += a[idx], in[idx] = true;
		std::cout << x << '\n';
	}

	return 0;
}
