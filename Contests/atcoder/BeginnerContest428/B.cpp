#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, k;	std::cin >> n >> k;
	std::string s;	std::cin >> s;
	std::map<std::string, int> cnt;
	for (int i = 0; i + k <= n; ++i) {
		std::string t = "";
		for (int j = i; j < i + k; ++j) t += s[j];
		cnt[t] += 1;
	}

	int mxRep = 0;
	for (auto x: cnt) mxRep = std::max(mxRep, x.second);
	std::set<std::string> ans;
	for (auto x: cnt) if (mxRep == x.second) ans.insert(x.first);

	std::cout << mxRep << '\n';
	for (auto x: ans) std::cout << x << ' ';
	return 0;
}
