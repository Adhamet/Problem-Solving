#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m;
	std::cin >> n >> m;
	int tot = n * m;
	if (tot & 1) std::cout << "[second]=:]";
	else std::cout << "[:=[first]";
	
	return 0;
}
