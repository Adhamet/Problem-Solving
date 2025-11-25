#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;	std::cin >> n;
	int p[n], pos[n + 1];
	for (int i = 0; i < n; ++i) std::cin >> p[i], pos[p[i]] = i + 1;
	int pref[n+1], suff[n+1];
	pref[1] = pos[1];
	for (int i = 2; i <= n; ++i) pref[i] = std::min(pref[i - 1], pos[i]);
	suff[n] = pos[n];
	for (int i = n - 1; i >= 1; --i) suff[i] = std::max(suff[i + 1], pos[i]);
	bool acc = true;
	for (int i = 1; i <= n - 1; ++i) acc = (pref[i] > suff[i + 1])? 0: acc;
	std::cout << (acc? "Yes\n": "No\n");
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
