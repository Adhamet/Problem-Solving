#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int x, y, z;
	std::cin >> x >> y >> z;
	if (x == z*y) std::cout << "Yes\n";
	else {
		bool acc = false;
		for (int i = 0; i < 100000; ++i) {
			x++,y++;
			if (x == z*y) acc = true;
		}
		std::cout << (acc? "Yes\n": "No\n");
	}

	return 0;
}
