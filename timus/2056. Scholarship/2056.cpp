#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];

	bool has3 = false, all5 = true;
	double sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		if (a[i] == 3) has3 = true;
		if (a[i] != 5) all5 = false;
	}
	
	if (has3) return std::cout << "None", 0;
	if (all5) return std::cout << "Named", 0;
	if (sum / n >= 4.5) return std::cout << "High", 0;
	return std::cout << "Common", 0;
}
