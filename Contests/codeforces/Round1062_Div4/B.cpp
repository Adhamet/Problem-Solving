#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;	std::cin >> n;
	std::string s, t;
	std::cin >> s >> t;

	std::map<int,int> mp1, mp2;
	for (auto x: s) mp1[x]++;
	for (auto x: t) mp2[x]++;

	bool deny = false;
	for (auto x: s) {
		if (mp1[x] != mp2[x]) {
			deny = true;
		}
	}
	std::cout << (deny? "NO\n": "YES\n");
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
