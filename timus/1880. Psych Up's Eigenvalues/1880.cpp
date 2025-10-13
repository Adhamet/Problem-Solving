#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::map<int, int> freq;
	int n1;	std::cin >> n1;
	for (int i = 0; i < n1; ++i) {
		int x;
		std::cin >> x;
		freq[x]++;
	}

	int n2;	std::cin >> n2;
	for (int i = 0; i < n2; ++i) {
		int x;
		std::cin >> x;
		freq[x]++;
	}

	int ans = 0;
	int n3;	std::cin >> n3;
	for (int i = 0; i < n3; ++i) {
		int x;
		std::cin >> x;
		freq[x]++;
		if (freq[x] == 3) ans += 1;
	}
	
	return std::cout << ans, 0;
}
