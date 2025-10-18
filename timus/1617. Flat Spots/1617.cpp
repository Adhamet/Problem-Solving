#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;	std::cin >> n;
	std::map<int,int> freq;
	for (int i = 0; i < n; ++i) {
		int d;	std::cin >> d;
		freq[d]++;
	}

	int cars = 0;
	for (auto &p: freq) cars += p.second / 4;
	
	return std::cout << cars, 0;
}
