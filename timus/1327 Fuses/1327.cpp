#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int a, b;	std::cin >> a >> b;
	int oddCnt = 0;
	for (int i = a; i <= b; ++i) if (i & 1) oddCnt += 1;
	return std::cout << oddCnt, 0;
}
