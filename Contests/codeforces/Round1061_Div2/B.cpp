#include <bits/stdc++.h>
using i64 = long long;

void solve() {
	int n, q;	std::cin >> n >> q;
	std::string s;	std::cin >> s;
	bool hasB = false;
	for (char ch: s) {
		if (ch == 'B') {
			hasB = true;
			break;
		}
	}

	std::vector<int> a(q);
	for (int i = 0; i < q; ++i) std::cin >> a[i];
	
	if (!hasB) {
		for (int i = 0; i < q; ++i) std::cout << a[i] << '\n';
	} else {
		for (int i = 0; i < q; ++i) {
			int x = a[i], steps = 0, idx = 0;
			while (x > 0) {
				if (s[idx] == 'A') x--;
				else x/=2;
				steps++;
				idx = (idx + 1) % n;
			}
			std::cout << steps << '\n';
		}
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

