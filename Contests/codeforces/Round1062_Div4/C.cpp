#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;	std::cin >> n;
	std::vector<int> a(n);
	int cntOd = 0, cntEv = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		if (a[i] & 1) cntOd++;
		else cntEv++;
	}
	
	if (cntEv == 0 || cntOd == 0) {
		for (int i = 0; i < n; ++i) std::cout << a[i] << ' ';
	} else {
		std::sort(a.begin(), a.end());
		for (int i = 0; i < n; ++i) std::cout << a[i] << ' ';
	}
	std::cout << '\n';
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
