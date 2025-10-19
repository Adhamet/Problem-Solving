#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;	std::cin >> n >> k;
	std::string s;	std::cin >> s;
	std::vector<bool> protecte(n);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			int j = std::max(0, i - (k - 1));
			bool prot = false;
			while (j < i) {
				if (s[j] == '1') prot = true;
				j++;
			}
			if (!prot) protecte[s[i]] = true, cnt+=1;
		}
	}
	std::cout << cnt << '\n';;
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
