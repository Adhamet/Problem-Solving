#include <bits/stdc++.h>
int main() {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0);
	int n, cnt = 0;
	std::string s, t;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> s;
		if (s == "0") return std::cout << 0, 0;

		int cnt1 = 0, cnt2 = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '1') cnt1 += 1;
			else if (s[j] != '0') cnt2 += 1;
		}

		if (cnt1 > 1 || cnt2) t = s;
		else cnt += s.size() - 1;
	}

	if (t != "") std::cout << t;
	else std::cout << 1;
	for (int i = 0; i < cnt; i++) std::cout << 0;
	return 0;
}
