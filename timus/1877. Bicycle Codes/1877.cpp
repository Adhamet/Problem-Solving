#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::string s1, s2;
	std::cin >> s1 >> s2;
	
	if ((s1[3] - '0') % 2 == 0 || (s2[3] - '0') & 1)
		std::cout << "yes\n";
	else std::cout << "no\n";

	return 0;
}
