#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int a[3];
	std::cin >> a[0] >> a[1] >> a[2];
	std::sort(a, a+3);
	for (int i = 2; i >= 0; --i) std::cout << a[i];
	return 0;
}
