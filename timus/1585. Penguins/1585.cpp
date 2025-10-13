#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;	std::cin >> n;
	std::map<std::string, int> cnt;
	std::cin.ignore();
	while (n--) {
		std::string s;
		std::getline(std::cin, s);
		cnt[s]++;
	}

	std::string ans;
	int mx = 0;
	for (auto &x: cnt)
		if (x.second > mx)
			mx = x.second, ans = x.first;
	return std::cout << ans, 0;
}
