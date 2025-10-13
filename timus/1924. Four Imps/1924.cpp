#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;	std::cin >> n;
	int oddCnt = 0;
	for (int i = 1; i <= n; ++i)
		if (i & 1) oddCnt += 1;
	if (oddCnt & 1) std::cout << "grimy";
	else std::cout << "black";
	return 0;
}
