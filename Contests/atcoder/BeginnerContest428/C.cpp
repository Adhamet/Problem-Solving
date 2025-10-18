#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int q;	std::cin >> q;
	std::vector<int> a{0}, b{0};
	while (q--) {
		int type;	std::cin >> type;
		if (type == 1) {
			char c;	std::cin >> c;
			a.push_back(a.back() + (c == '('? 1: -1));
			b.push_back(std::min(b.back(), a.back()));
		} else { // type == 2
			a.pop_back();
			b.pop_back();
		}
		std::cout << (a.back() == 0 && b.back() == 0? "Yes": "No") << '\n';
	}
	
	return 0;
}
