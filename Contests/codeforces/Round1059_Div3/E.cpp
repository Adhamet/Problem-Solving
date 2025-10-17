#include <bits/stdc++.h>
using i64 = long long;

void solve() {
	int n, k;	std::cin >> n >> k;
	std::set<std::pair<int,int>> st;
	std::vector<int> a(n+1), pos(n + 2, 0);
	for (int i = 1; i <= n; ++i) st.insert({0, i});
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		st.erase({pos[a[i]], a[i]});
		pos[a[i]] = i;
		st.insert({pos[a[i]], a[i]});
	}
	for (int i = 1; i <= k; ++i) {
		int x = st.begin()->second;
		st.erase({pos[x],x});
		pos[x] = i + n;
		st.insert({pos[x], x});
		std::cout << x << ' ';
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

