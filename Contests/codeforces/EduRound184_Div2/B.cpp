#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;
	int n = (int)s.size();

	if (n == 1) return void(std::cout << 1 << '\n');

	bool inf = false;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == '*' && s[i+1] == '*') inf = true;
		else if (s[i] == '*' && s[i+1] == '<') inf = true;
		else if (s[i] == '>' && s[i+1] == '*') inf = true;
		else if (s[i] == '>' && s[i+1] == '<') inf = true;
	}

	if (inf) return void(std::cout << -1 << '\n');

	int itr = 0, mx = 0;
	while (itr < n) {
		int cur = 0;
		while (itr < n && (s[itr] == '>' || s[itr] == '*')) {
			cur++;
			itr++;
		}
		mx = std::max(mx, cur);
		itr++; // ???
	}

	itr = n - 1;
	while (itr >= 0) {
		int cur = 0;
		while (itr >= 0 && (s[itr] == '<' || s[itr] == '*')) {
			cur++;
			itr--;
		}
		mx = std::max(mx, cur);
		itr--; // ???
	}

	std::cout << mx << '\n';
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
