#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::string a1[9], a2[9], a3[9];
	a1[0] = "Alice", a1[1] = "Ariel", a1[2] = "Aurora";
	a1[3] = "Phil", a1[4] = "Peter", a1[5] = "Olaf";
	a1[6] = "Phoebus", a1[7] = "Ralph", a1[8] = "Robin";
	
	a2[0] = "Bambi", a2[1] = "Belle", a2[2] = "Bolt";
	a2[3] = "Mulan", a2[4] = "Mowgli", a2[5] = "Mickey";
	a2[6] = "Silver", a2[7] = "Simba", a2[8] = "Stitch";

	a3[0] = "Dumbo", a3[1] = "Genie", a3[2] = "Jiminy";
	a3[3] = "Kuzko", a3[4] = "Kida", a3[5] = "Kenai";
	a3[6] = "Tarzan", a3[7] = "Tiana", a3[8] = "Winnie";

	int n, ans = 0, cur = 0;	std::cin >> n;
	while (n--) {
		std::string s;
		std::cin >> s;
		for (int i = 0; i < 9; ++i) if (s == a1[i]) {
			ans += abs(cur - 0);
			cur = 0;
		}
		for (int i = 0; i < 9; ++i) if (s == a2[i]) {
			ans += abs(cur - 1);
			cur = 1;
		}
		for (int i = 0; i < 9; ++i) if (s == a3[i]) {
			ans += abs(cur - 2);
			cur = 2;
		}
	}

	return std::cout << ans, 0;
}
