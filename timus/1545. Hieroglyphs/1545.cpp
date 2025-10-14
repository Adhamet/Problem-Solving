#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;	std::cin >> n;
	std::vector<std::string> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	
	char k;	std::cin >> k;
	for (int i = 0; i < n; ++i) {
		if (a[i][0] == k) std::cout << a[i] << '\n';
	}
	
	return 0;
}
