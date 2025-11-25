#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;	std::cin >> n;
	int a[n];
	i64 ans = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		if (i != 0) {
			int x1 = (a[i] == -1? 0: a[i]);
			int x2 = (a[i-1] == -1? 0: a[i-1]);
			// std::cout << "WTF?: " << x1 << ' ' << x2 << '\n';
			ans += (x1 - x2);
		}
	}

	if (a[0] != -1 && a[n-1] != -1) {
		std::cout << std::abs(ans) << '\n';
		for (int i = 0; i < n; ++i) std::cout << (a[i]==-1? 0: a[i]) << ' ';
		std::cout << '\n';
	} else {
		if (a[0] == -1) {
			if (ans <= 0) a[0] = 0;
			else a[0] = ans;
			if (a[n-1] == -1) a[n-1] = 0;
		} else if (a[n - 1] == -1) {
			if (ans >= 0) a[n-1] = 0;
			else a[n-1] = std::abs(ans);
		}

		std::cout << 0 << '\n';
		for (int i = 0; i < n; ++i) std::cout << (a[i]==-1? 0: a[i]) << ' ';
		std::cout << '\n';
	}
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
