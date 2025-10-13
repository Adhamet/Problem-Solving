#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int cnt = 2;
	int n;	std::cin >> n;
	while (n--) {
		std::string s;
		std::cin >> s;
		int m = (int)s.size();
		if (m >= 4 && s[m-4] == '+' && s[m-3]=='o' && s[m-2]=='n' && s[m-1]=='e')
			cnt += 1;
		cnt += 1;
	}
	if (cnt == 13) cnt += 1;
	std::cout << 100 * cnt;

	return 0;
}
