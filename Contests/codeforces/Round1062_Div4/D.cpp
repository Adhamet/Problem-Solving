#include <bits/stdc++.h>

using i64 = long long;

std::vector<i64> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

void solve() {	
	int n;	std::cin >> n;
	i64 ans = LLONG_MAX;
	std::vector<i64> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	bool found = false;
	for (int d = 2; d <= 100; ++d) {
		for (int i = 0; i < n; ++i) if (std::gcd(a[i],d)==1) {
			ans = d;
			found = true;
			break;
		}
		if (found) break;
	}
	std::cout << (found? ans: -1) << '\n';
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
