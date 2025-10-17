#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;	std::cin >> n;
	std::string s;	std::cin >> s;

	bool found = false;
	for (int i = 0; i < (1 << n); ++i) {
		std::string t, nt;
		std::vector<int> indices;
		for (int bit = 0; bit < n; ++bit) {
			if (i & (1 << bit)) {
				indices.push_back(bit);
				nt.push_back(s[bit]);
			} else {
				t.push_back(s[bit]);
			}
		}

		if (!std::is_sorted(nt.begin(), nt.end())) continue;

		std::string tt = t;
		reverse(tt.begin(), tt.end());
		if (t == tt) {
			std::cout << (int)indices.size() << '\n';
			for (auto ii: indices) std::cout << ii + 1 << ' ';
			found = true;
			break;
		}
	}

	if (!found) std::cout << -1;
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
