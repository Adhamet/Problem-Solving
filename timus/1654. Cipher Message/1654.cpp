#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;	std::cin >> s;
	std::string t;

	for (auto ch: s) {
		if (!t.empty() && t.back() == ch) t.pop_back();
		else t.push_back(ch);
	}

	return std::cout << t, 0;
}
