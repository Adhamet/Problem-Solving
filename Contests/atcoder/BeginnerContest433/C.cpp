#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::string s;
	std::getline(std::cin, s);

	int n = (int)s.size();

	std::vector<int> pos;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] + 1 == s[i+1]) {
			pos.push_back(i);
		}
	}

	i64 ans = 0;
	for (auto p: pos) {
		int l = p, r = p+1;
		int x1 = s[l], x2 = s[r];

		ans += 1;
		l--, r++;
		while (l >= 0 && r < n && s[l]==x1 && s[r]==x2) {
			ans += 1;
			l--, r++;
		}
	}
	
	return std::cout << ans, 0;
}
