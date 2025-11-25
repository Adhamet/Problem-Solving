#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	if (n % 2 != 0) return void(std::cout << 0 << '\n');
	int n1 = n, n2 = n;
	int cnt1 = 0, cnt2 = 0;
	while (n1 > 4) n1 -= 4, cnt1+=1;
	while (n2 > 2) n2 -= 2, cnt2+=1;
	std::cout << (cnt2 - cnt1 + 1) << '\n';
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
