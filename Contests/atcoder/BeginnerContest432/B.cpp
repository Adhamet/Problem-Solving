#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::string s;
	std::cin >> s;
	std::sort(s.begin(), s.end());
	if (s[0] == '0') {
		for (int i = 1; i < (int)s.size(); ++i) {
			if (s[i] != '0') {
				std::swap(s[0], s[i]);
				break;
			}
		}
	}
	std::cout << s;
	return 0;
}
