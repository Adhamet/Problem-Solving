#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	i64 t, c, s, e;	std::cin >> t >> c >> s >> e;
	if (s == e)	std::cout << t;
	else {
		i64 d = llabs(s - e);
		i64 ans;
		if (s < e) ans = (d - 1) * (t + 2 * c) + 2 * c;
		else ans = d * (t + 2 * c) + t;
		std::cout << ans;
	}
	return 0;
}	
