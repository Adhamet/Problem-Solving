#include <bits/stdc++.h>
#define el '\n'
int main() {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> eggs(n);
	for (auto &pr: eggs) std::cin >> pr.first >> pr.second;

	std::string result;
	long long Asum = 0, Gsum = 0;
	for (int i = 0; i < n; i++) {
		int ai = eggs[i].first, gi = eggs[i].second;
		if (std::abs((Asum + ai) - Gsum) <= 500) {
			result += 'A';
			Asum += ai;
		} else if (std::abs(Asum - (Gsum + gi)) <= 500) {
			result += 'G';
			Gsum += gi;
		} else {
			std::cout << -1 << el;
			return 0;
		}
	}

	return std::cout << result << el, 0;
}
