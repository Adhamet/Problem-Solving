#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, ans = 0;	std::cin >> n;
	std::cin.ignore();
	std::set<std::string> st;
	for (int i = 0; i < n; ++i) {
		std::string x;
		std::getline(std::cin, x);
		if (st.find(x) != st.end()) ans += 1;
		else st.insert(x);
	}
	
	return std::cout << ans, 0;
}
